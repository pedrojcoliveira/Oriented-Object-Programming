#include "Data.h"

// alinea a)
Data::~Data()
{
}

// alinea a)
Data::Data()
{
	dia = mes = ano = 0;
}

// alinea a)
Data::Data(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
}


// alinea b)
// para ver a diferença entre métodos inline e normal
int Data::GetDia(void)
{
	return dia;
}


// alinea c)
void Data::Show(void)
{
	cout << "Data:" << dia << "/" << mes << "/" << ano << "\n";
}

// alinea d)
void Data::Update(int _dia, int _mes, int _ano)
{
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

// aliena f)
bool Data::Igual(const Data _data)
{
	if (_data.ano != ano || _data.mes != mes || _data.dia != dia)
		return(false);
	return(true);
}

// alinea g)
bool Data::operator == (const Data _data) const
{
	if (_data.ano != ano || _data.mes != mes || _data.dia != dia)
		return(false);
	return(true);
}

// alinea h)
bool Data::operator != (const Data _data) const
{
	if (_data.ano != ano || _data.mes != mes || _data.dia != dia)
		return(true);
	return(false);
}

// alinea h)
ostream& operator << (ostream& _os, Data _data)
{
	_os << "Data:" << _data.GetDia() << "/" << _data.mes << "/" << _data.ano << "\n";

	return _os;
}

// alinea h)
istream& operator >> (istream& _is, Data& _data)
{
	int aux;

	cout << "Dia: ";
	_is >> _data.dia;
	//	_is >> aux;
	//	_data.SetDia(aux);
	cout << "Mes: ";
	_is >> _data.mes;
	cout << "Ano: ";
	_is >> _data.ano;

	return _is;
}

// alinea h)
bool Data::operator < (const Data _data) const
{
	if (_data.ano < ano)
		return(false);
	else	if (_data.ano == ano && _data.mes < mes)
		return(false);
	else	if (_data.ano == ano && _data.mes == mes && _data.dia < dia)
		return(false);
	return(true);
}

// alinea h)
bool Data::operator >(const Data _data) const
{
	if (_data.ano > ano)
		return(false);
	else	if (_data.ano == ano && _data.mes > mes)
		return(false);
	else	if (_data.ano == ano && _data.mes == mes && _data.dia > dia)
		return(false);
	return(true);
}


// alinea k)
void Data::SaveFile(ofstream& _os)
{
	_os << "Data: " << dia << "/" << mes << "/" << ano << ";\n";
}

// alinea k)
void Data::ReadFile(ifstream& _is)
{
	char aux[10];

	_is.getline(aux, 10, ' ');

	_is.getline(aux, 10, '/');
	dia = atoi(aux);
	_is.getline(aux, 10, '/');
	mes = atoi(aux);
	_is.getline(aux, 10, ';');
	ano = atoi(aux);
}