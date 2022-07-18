#include "Funcionario.h"

// alinea 5.1
Funcionario::Funcionario()
{
}

// alinea 5.1
Funcionario::~Funcionario()
{
}

// alinea 5.1
Funcionario::Funcionario(int _num, string _setor, string _nome, string _morada, Data _data)
	:Pessoa(_nome, _morada, _data)
{
	setor = _setor;
	num = _num;
}

// alinea 5.1
Funcionario::Funcionario(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a)
	:Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = _setor;
	num = _num;
}

// alinea 5.5
void Funcionario::Show(void)
{
	Pessoa::Show();
	cout << "Num: " << num << "; Setor: " << setor << "\n";
}


// alinea 5.8
istream& operator >> (istream& _is, Funcionario& _F)
{
	char aux[100];

	_is >> (Pessoa&)_F;
	cout << "Num: ";
	_is >> _F.num;
	cout << "Setor: ";
	_is >> aux;
	_F.setor = aux;

	return _is;
}

// alinea 5.10
void Funcionario::SaveFile(ofstream& _os)
{
	Pessoa::SaveFile(_os);
	_os << num << ";" << setor << "\n";
}


// alinea 5.12
void Funcionario::ReadFile(ifstream& _is)
{
	char aux[100];

	Pessoa::ReadFile(_is);
	_is.getline(aux, 100, ';');
	num = atoi(aux);
	_is.getline(aux, 100, '\n');
	setor = aux;
}

// não era preciso definir este método
void Funcionario::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Num: ";
	cin >> num;
	cout << "Setor: ";
	cin >> setor;
}

// não era pedido para definir 
ostream& operator << (ostream& _os, const Funcionario _F)
{
	_os << (Pessoa&)_F;
	_os << "Num: " << _F.num;
	_os << "; Setor: " << _F.setor;

	return _os;
}

