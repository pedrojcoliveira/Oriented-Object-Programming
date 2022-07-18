#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

Data::Data()
{
	dia = mes = ano = 0;
}

Data::~Data()
{
}

Data::Data(int _dia, int _mes, int _ano)
{
	dia = _dia;
	mes = _mes;
	ano = _ano;
}

void Data::Show(void)
{
	cout << dia << "/" << mes << "/" << ano << "\n";
}

void Data::Update(int _dia, int _mes, int _ano)
{
	SetDia(_dia);// dia = _dia;
	SetMes(_mes);//	mes = _mes;
	SetAno(_ano);//	ano = _ano;
}

bool Data::Igual(const Data _data)
{
	if (_data.ano != ano || _data.mes != mes || _data.dia != dia)
		return(false);
	return(true);
}

ostream& operator << (ostream& _os, const Data _data)
{
	_os << _data.dia << "/" << _data.mes << "/" << _data.ano;

	return _os;
}

istream& operator >> (istream& _is, Data& _data)
{
	int aux;

	cout << "Dia: ";
	_is >> aux;
	//is>>data.dia;
	_data.SetDia(aux);
	cout << "Mês: ";
	_is >> _data.mes;
	cout << "Ano: ";
	_is >> _data.ano;

	return _is;
}

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

void Data::SaveFile(ofstream& _os)
{
	_os << dia << "/" << mes << "/" << ano << ";" << "\n";
}

void Data::ReadFile(ifstream& _is)
{
	char aux[10];

	_is.getline(aux, 10, '/');
	dia = atoi(aux);
	_is.getline(aux, 10, '/');
	mes = atoi(aux);
	_is.getline(aux, 10, ';');
	ano = atoi(aux);
}