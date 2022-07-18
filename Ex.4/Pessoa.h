#pragma once
#include "Data.h"
#include <string>

class Pessoa
{
private:
	string nome, morada;
	Data   data;

public:
	// alinea a) e enunciado geral
	Pessoa();
	Pessoa(string _nome, string _morada, Data _data);
	Pessoa(string _nome, string _morada, int _dia, int _mes, int _ano);
	virtual ~Pessoa();
	// alinea a) e enunciado geral e também alineas d) e e)
	void SetMorada(string _morada) { morada = _morada; }
	void SetData(Data _data) { data = _data; }
	void SetNome(string _nome) { nome = _nome; }
	string GetNome(void) { return nome; }
	string GetMorada(void) { return morada; }
	Data GetData(void) { return data; }


	// alinea c)
	void Show(void);

	// alinea f)
	void ReadK(void);

	// alinea g)
	friend ostream& operator << (ostream& os, const Pessoa P);
	friend istream& operator >> (istream& is, Pessoa& P);

	// alinea h)
	bool operator == (const Pessoa _P) const;
	bool operator != (const Pessoa _P) const;

	// alinea i)
	bool MaisNovo(Pessoa P);

	// alinea j)
	void SaveFile(ofstream& os);

	// alinea k)
	void ReadFile(ifstream& is);
};
