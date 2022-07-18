#include "Funcionario.h"

// alinea 6.1
Funcionario::Funcionario()
{
}

// alinea 6.1
Funcionario::~Funcionario()
{
}

// alinea 6.1
Funcionario::Funcionario(int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, Data _data)
	:Pessoa(_nome, _morada, _data)
{
	setor = _setor;
	num = _num;
	ord_b = _ord_b;
	h_extra = _h_extra;
}

// alinea 6.1
Funcionario::Funcionario(int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) 
	:Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = _setor;
	num = _num;
	ord_b = _ord_b;
	h_extra = _h_extra;
}

void Funcionario::Show(void)
{
	Pessoa::Show();
	cout << " Horas extra: " << h_extra << " Ord. Base: " << ord_b
		<< " Num: " << num << " Setor: " << setor << "\n";
}

void Funcionario::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Horas extra:";
	cin >> h_extra;
	cout << "Ord. Base:";
	cin >> ord_b;
	cout << "Num:";
	cin >> num;
	cout << "Setor:";
	cin >> setor;
}


ostream& operator << (ostream& os, Funcionario& F)
{
	os << (Pessoa&)F;
	os << "Num: " << F.GetNum();
	os << "; Setor: " << F.GetSetor();

	return os;
}

istream& operator >> (istream& is, Funcionario& F)
{
	char aux[100];

	is >> (Pessoa&)F;
	cout << "Num:";
	is >> F.num;
	cout << "Setor:";
	is >> aux;
	F.setor = aux;

	return is;
}


void Funcionario::SaveFile(ofstream& os)
{
	Pessoa::SaveFile(os);
	os << h_extra << ";" << ord_b << "; " << num << "; " << setor << "\n";
}

void Funcionario::ReadFile(ifstream& is)
{
	char aux[100];

	Pessoa::ReadFile(is);
	is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;
	is.getline(aux, 100, ';');
	ord_b = atoi(aux);
	is.getline(aux, 100, ';');
	h_extra = atoi(aux);
}
