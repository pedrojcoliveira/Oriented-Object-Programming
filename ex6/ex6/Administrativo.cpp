#include "Administrativo.h"

// alinea 6.2
Administrativo::Administrativo()
{
}

// alinea 6.2
Administrativo::~Administrativo()
{
}

// alinea 6.2
Administrativo::Administrativo(float _p_h_extra, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data)
	:Funcionario(_h_extra, _ord_b, _num, _setor, _nome, _morada, _data)
{
	SetPreco_Extra(_p_h_extra);
}

// alinea 6.2
Administrativo::Administrativo(float _p_h_extra, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a)
	: Funcionario(_h_extra, _ord_b, _num, _setor, _nome, _morada, _d, _m, _a)
{
	SetPreco_Extra(_p_h_extra);
}

// alinea 6.4
float Administrativo::Calc_Ordenado(void)
{
	return GetOrdenado() + GetPreco_Extra() * GetExtra();
}

void Administrativo::Show(void)
{
	Funcionario::Show();
	cout << "Preço por hora Extra: " << this->GetPreco_Extra() << endl; 
}

void Administrativo::ReadK(void)
{
	float _p_h_extra;

	Funcionario::ReadK();
	SetPreco_Extra(Preco_h_extra_Admin);
}


ostream& operator << (ostream& os, const Administrativo A)
{
	os << (Funcionario&)A;
	os << "Num: " << ((Funcionario&)A).GetNum();
	os << "; Setor: " << ((Funcionario&)A).GetSetor();
	os << "; Ord. base: " << ((Funcionario&)A).GetOrdenado();
	os << "; Horas extra: " << ((Funcionario&)A).GetExtra() << endl;

	return os;
}

istream& operator >> (istream& is, Administrativo& A)
{
	char aux[100], op;
	int x;
	float _p_h_extra;

	is >> (Funcionario&)A;
	cout << "Num:";
	is >> x;
	A.SetNum(x);
	cout << "Setor:";
	is >> aux;
	A.SetSetor(aux);
	cout << "Ordenado base:";
	is >> x;
	A.SetOrdenado(x);
	cout << "Horas extra:";
	is >> x;
	A.SetExtra(x);

	A.SetPreco_Extra(Preco_h_extra_Admin);


	return is;
}

void Administrativo::SaveFile(ofstream& os)
{
	Funcionario::SaveFile(os);
}

void Administrativo::ReadFile(ifstream& is)
{
	char aux[100];

	Funcionario::ReadFile(is);
	this->SetPreco_Extra(Preco_h_extra_Admin); //10 € por hora extra
}

