#include "Operario.h"

// alinea 6.2
Operario::Operario()
{
}

// alinea 6.2
Operario::~Operario()
{
}

// alinea 6.2
Operario::Operario(bool _f_turno, float _p_h_extra, int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, Data _data)
	:Funcionario(_h_extra, _ord_b, _num, _setor, _nome, _morada, _data)
{
	SetPreco_Extra(_p_h_extra);
	f_turno = _f_turno;
}

// alinea 6.2
Operario::Operario(bool _f_turno, float _p_h_extra, int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a)
	: Funcionario(_h_extra, _ord_b, _num, _setor, _nome, _morada, _d, _m, _a)
{
	SetPreco_Extra(_p_h_extra);
	f_turno = _f_turno;
}

// alinea 6.4
float Operario::Calc_Ordenado(void)
{
	if (f_turno)
		return 1.25 * GetOrdenado() + GetPreco_Extra() * GetExtra();
	else
		return	GetOrdenado() + GetPreco_Extra() * GetExtra();
}

void Operario::Show(void)
{
	Funcionario::Show();
	cout << " Preço por hora Extra: " << this->GetPreco_Extra();
	if (f_turno)
		cout << " Turnos: " << "sim" << endl;
	else
		cout << " Turnos: " << "nao" << endl;
}

void Operario::ReadK(void)
{
	char op;
	float _p_h_extra;

	Funcionario::ReadK();
	SetPreco_Extra(Preco_h_extra_Oper);

	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		f_turno = true;
	else
		f_turno = false;
}


ostream& operator << (ostream& os, const Operario O)
{
	os << (Funcionario&)O;
	os << "Num: " << ((Funcionario&)O).GetNum();
	os << "; Setor: " << ((Funcionario&)O).GetSetor();
	os << "; Ord. base: " << ((Funcionario&)O).GetOrdenado();
	os << "; Horas extra: " << ((Funcionario&)O).GetExtra();
	if (O.f_turno)
		os << "Turnos:" << "sim" << endl;
	else
		os << "Turnos:" << "nao" << endl;

	return os;
}

istream& operator >> (istream& is, Operario& O)
{
	char aux[100], op;
	int x;
	float _p_h_extra;

	is >> (Funcionario&)O;
	cout << "Num:";
	is >> x;
	O.SetNum(x);
	cout << "Setor:";
	is >> aux;
	O.SetSetor(aux);
	cout << "Ordenado base:";
	is >> x;
	O.SetOrdenado(x);
	cout << "Horas extra:";
	is >> x;
	O.SetExtra(x);
	O.SetPreco_Extra(Preco_h_extra_Oper);
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		O.f_turno = true;
	else
		O.f_turno = false;

	return is;
}

void Operario::SaveFile(ofstream& os)
{
	Funcionario::SaveFile(os);
	if (f_turno)
		os << "sim" << endl;
	else
		os << "nao" << endl;
}

void Operario::ReadFile(ifstream& is)
{
	char aux[100];

	Funcionario::ReadFile(is);
	is.getline(aux, 100, ';');
	if (!strcmp(aux, "sim"))
		f_turno = true;
	else
		f_turno = false;
	this->SetPreco_Extra(Preco_h_extra_Oper); //8 € por hora extra
}

