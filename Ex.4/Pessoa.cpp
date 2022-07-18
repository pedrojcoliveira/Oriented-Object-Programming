#include "Pessoa.h"

// alinea a)
Pessoa::Pessoa()
{
}

// alinea a)
Pessoa::~Pessoa()
{
}

// alinea a)
Pessoa::Pessoa(string _nome, string _morada, Data _data)
{
	nome = _nome;
	morada = _morada;
	data = _data;
}

// alinea a)
Pessoa::Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano)
{
	nome = _nome;
	morada = _morada;
	data.SetDia(_dia);
	data.SetMes(_mes);
	data.SetAno(_ano);
}

// alinea c)
void Pessoa::Show(void)
{
	cout << "Nome: " << nome << "; ";
	cout << "Morada: " << morada << "; ";
	data.Show();
	//	cout << "; Data de nascimento: " << data << ";";
}

// alinea f)
void Pessoa::ReadK(void)
{
	char aux[100];

	cout << "Nome: ";
	cin.getline(aux, sizeof aux);
	nome = aux;
	cout << "Morada: ";
	cin.getline(aux, sizeof aux);
	morada = aux;
	cout << "Data de nascimento: ";
	cin >> data;
}

// aline g)
ostream& operator << (ostream& _os, const Pessoa _P)
{
	_os << "Nome: " << _P.nome << "; ";
	_os << "Morada: " << _P.morada << "; ";
	_os << "Data de nascimento: " << _P.data << "\n";

	return _os;
}

// aline g)
istream& operator >> (istream& _is, Pessoa& _P)
{
	char aux[100];

	cout << "Nome: ";
	_is.getline(aux, sizeof aux);
	_P.nome = aux;
	cout << "Morada: ";
	_is.getline(aux, sizeof aux);
	_P.morada = aux;
	cout << "Data de nascimento: ";
	_is >> _P.data;

	return _is;
}


// alinea h)
bool Pessoa::operator == (const Pessoa _P) const
{
	if (_P.data == data && _P.nome == nome)
		return(true);
	return(false);
}

// alinea h)
bool Pessoa::operator != (const Pessoa _P) const
{
	if (_P.data != data || _P.nome != nome)
		return(true);
	return(false);
}

// alinea i)
bool Pessoa::MaisNovo(Pessoa _P)
{
	if (data < _P.data)
		return false;
	else
		return true;
}

// alinea j)
void Pessoa::SaveFile(ofstream& _os)
{
	_os << nome << ";" << morada << ";" << data << ";\n";
	/*
	_os << nome << ";" << morada << ";";
	data.SaveFile(_os);
	_os<<"\n";
	*/
}

// alinea k)
void Pessoa::ReadFile(ifstream& _is)
{
	char aux[100];

	_is.getline(aux, 100, ';');
	nome = aux;
	_is.getline(aux, 100, ';');
	morada = aux;

	data.ReadFile(_is);
	//OU
/*	_is.getline(aux,10,'/');
	data.SetDia(atoi(aux));
	_is.getline(aux,10,'/');
	data.SetMes(atoi(aux));
	_is.getline(aux,10,';');
	data.SetAno(atoi(aux));*/
}

