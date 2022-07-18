#include <iostream>
#include <fstream>
#include "GestorN.h"

#include<list>

using namespace std;

GestorN::GestorN()
{
	if (!lista.empty())
	{
		lista.clear();
	}
}

GestorN::~GestorN()
{
	if (!lista.empty())
	{
		lista.clear();
	}
}

void GestorN::SetLista(list<int> _lista)
{
	if (!lista.empty())
	{
		lista.clear();
	}
	lista = _lista;
}

list<int> GestorN::GetLista()
{
	return lista;
}

void GestorN::InserirInicio(int num)
{
	lista.push_front(num); //em inglês: "front" é o início da lista; "push" é uma operação de inserção.
	return;
}

void GestorN::InserirFinal(int num)
{
	lista.push_back(num);//em inglês: "back" é o final da lista; "push" é uma operação de inserção.
	return;
}

void GestorN::Remover(int num)
{

	lista.remove(num);
	////iterador (temporário) utilizado para apontar para qualquer um dos nós da lista
	//list<int>::iterator p;
	//
	////procurar o valor "num" dentro de um intervalo na lista
	//p = find(lista.begin(), lista.end(), num);
	////se "num" não for encontrado, o iterador aponta para o final da lista
	////se "num" for encontrado, o iterador aponta para o elemento da lista que contem "num"
	//if (p != lista.end())
	//{
	//	lista.erase(p); //remover elemento da lista (apontado por 'p')
	//	cout << "Elemento removido.\n";
	//	return;
	//}
	//cout << "Elemento nao encontrado.\n";
}

// lista/apresenta no ecran todos os elementos da lista
void GestorN::Show()
{
	list<int>::iterator p = lista.begin(); //apontar para o início

	while (p != lista.end())
	{
		cout << *p << "\n";
		p++;
	}
	cout << "\n";
}

// lista/apresenta no ecran todos os elementos da lista
ostream& operator << (ostream& os, GestorN& g)
{
	list<int>::iterator p = g.lista.begin(); //apontar para o início

	while (p != g.lista.end())
	{
		os << *p << '\n';
		p++;
	}

	return os;
}

// lê do teclado um número e insere-o no início da lista
istream& operator >> (istream& is, GestorN& g)
{
	int temp;
	is >> temp;
	g.InserirInicio(temp);

	return is;
}

int GestorN::EncontrarIndice(int num)
{
	int i = 0;
	list<int>::iterator p = lista.begin(); //apontar para o início

	while (p != lista.end())
	{
		if (*p == num)
		{
			return i;
		}
		i++;
		p++;
	}
	return -1;
}

// carrega uma lista a partir de um ficheiro
void GestorN::ReadFile(ifstream& is)
{
	int i; 
	char aux[10];
	
	while (is.peek() != EOF)
	{
		is.getline(aux, sizeof(aux), '\n');
		i = atoi(aux);
		InserirFinal(i);
	}
}

// grava num ficheiro os elementos de uma lista
void GestorN::SaveFile(ofstream& os)
{
	list<int>::iterator p = lista.begin(); //apontar para o início
	while (p != lista.end())
	{
		os << *p << "\n";
		p++;
	}
}

