#pragma once
#include <iostream>
#include <fstream>
#include "Gestor_Func.h"
#include "Opera.h"
#include "Func.h"
#include "Admin.h"

#include<list>

using namespace std;

// 8.1
Gestor_Func::Gestor_Func()
{
	if (!lista.empty())
	{
		lista.clear();
	};

}

Gestor_Func::~Gestor_Func()
{
	if (!lista.empty())
	{
		lista.clear();
	};
}

void Gestor_Func::SetLista(list<Func*> _lista)
{
	if (!lista.empty())
	{
		lista.clear();
	}
	lista = _lista;
}

list<Func*> Gestor_Func::GetLista()
{
	return lista;
}


// 8.2
//alinea a

void Gestor_Func::ReadFile(string filename)
{
	char aux[10]; //ler "O" ou "A"
	char aux2; //consumir caracteres indesejados (exemplo : "\n")
	ifstream ifile;

	ifile.open(filename);
	if (!ifile)
	{
		cout << "Erro ao abrir ficheiro.\n";
		return;
	}

	list<Func*>::iterator p = lista.end();

	while (ifile.peek() != EOF)
	{
		ifile.getline(aux, sizeof(aux), ':'); //ler do inicio da nova linha até ao ":"
		if (strcmp(aux, "O") == 0)
			p = lista.insert(p, (Opera*) new Opera); //insere na posicao da lista imediatamente anterior à apontada por p

		if (strcmp(aux, "A") == 0)
			p = lista.insert(p, (Admin*) new Admin);

		(*p)->ReadFile(ifile);
		p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
		ifile.get(aux2); //consumir o "\n" do fim de linha
	}
}


//alinea b

void Gestor_Func::ShowFunc()
{
	list<Func*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		(*p)->Show();
		//		cout << (*(*p));
		p++;
	}

}



//alinea c

///Adiciona uma nova pessoa à lista. O tipo define se é Admin ou Opera.
///tipo: Admin = "A" e Opera = "O"
void Gestor_Func::AddFunc(string tipo)
{
	list<Func*>::iterator p = lista.begin();

	if (tipo == "O") //cria operario por defeito (turno=false)
	{
		p = lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(false);
		(*p)->ReadK();
	}
	else if (tipo == "A") //cria administrativo por defeito
	{
		p = lista.insert(p, (Admin*) new Admin);
		(*p)->ReadK();
	}
	else
	{
		return;
	}
}

//alinea d

void Gestor_Func::RemoveFunc(int num) //remover pessoa pelo seu número de funcionário
{
	list<Func*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if ((*p)->GetNum() == num)
		{
			lista.erase(p);
			return;
		}
		p++;
	}
}

//alinea e

ostream& operator << (ostream& os, Gestor_Func& GF)
{
	list<Func*>::iterator p = GF.lista.begin();
	while (p != GF.lista.end())
	{
		(*p)->Show();
		p++;
	}
	return os;
}

istream& operator >> (istream& is, Gestor_Func& GF)
{
	int op;
	list<Func*>::iterator p = GF.lista.begin();
	cout << "\n1-Operario | 2-Operario(turnos) | 3-Administrativo\n";
	cin >> op;
	if (op == 1)
	{
		p = GF.lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(false);
		(*p)->ReadK();

	}
	if (op == 2)
	{
		p = GF.lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(true);
		(*p)->ReadK();
	}
	if (op == 3)
	{
		p = GF.lista.insert(p, (Admin*) new Admin);
		(*p)->ReadK();
	}
	return is;
}


//alinea f

void Gestor_Func::SaveFile(ofstream& os)
{
	list<Func*>::iterator p = lista.begin();
	
	//Opera* O = new Opera; Admin* A = new Admin;
	
	while (p != lista.end())
	{
		if (dynamic_cast<Admin*>(*p) != NULL) //é admin
			os << "A:";
		if (dynamic_cast<Opera*>(*p) != NULL) //verifica se é Operario
			os << "O:";

		(*p)->SaveFile(os);

		os << "\n";
		p++;
	}
}

// extra
// inserir um funcionário na "posicao"
void Gestor_Func::SetFunc(Func* mp, int posicao)
{
	list<Func*>::iterator p = lista.begin();
	if (posicao >= 0 && posicao < lista.size())
	{
		for (int i = 0; i < posicao; i++)
		{
			p++; //colocar iterador a apontar p/posicao correta e inserir
		}
		lista.insert(p, mp);
	}
	else
	{
		lista.push_back(mp);//adicionar pessoa na ultima posicao da lista, caso a posicao seja inadequada
	}
}

// retorna um dado funcionário -- pesquisa por nome
Func* Gestor_Func::GetFunc(string nome)
{
	list<Func*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if (nome == (*p)->GetNome())
		{
			return (*p);
		}
		p++;
	}
	return NULL;
}


