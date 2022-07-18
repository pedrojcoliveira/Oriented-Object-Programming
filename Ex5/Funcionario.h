#pragma once
#include "Pessoa.h"

class Funcionario 
	: public Pessoa
{
private:
	string setor;
	int num;
public:
	// aliena 5.1 e 5.2
	Funcionario();
	Funcionario(int _num, string _setor, string _nome, string _morada, Data _data);
	Funcionario(int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Funcionario();

	// alinea 5.3
	void SetNum(int _num) { num = _num; }
	void SetSetor(string _setor) { setor = _setor; }
	int GetNum(void) { return num; }
	string GetSetor(void) { return setor; }

	// alinea 5.5
	void Show(void);
	void ReadK(void);

	// alinea 5.8
	friend ostream& operator << (ostream& _os, const Funcionario _F);
	friend istream& operator >> (istream& _is, Funcionario& _F);

	// alinea 5.10
	void SaveFile(ofstream& _os);

	// alinea 5.12
	void ReadFile(ifstream& _is);

};
