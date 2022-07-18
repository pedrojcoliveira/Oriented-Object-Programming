#pragma once
#include "Pessoa.h"

// aliena 6.1
const float Preco_h_extra_Oper = 8;
const float Preco_h_extra_Admin = 10;

class Funcionario 
	: public Pessoa
{
private:
	// aliena 6.1
	string setor;
	int num, h_extra;
	float ord_b, p_h_extra;

public:
	// aliena 6.1
	Funcionario();
	Funcionario(int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, Data _data);
	Funcionario(int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Funcionario();

	void SetNum(int _num) { num = _num; }
	void SetSetor(string _setor) { setor = _setor; }
	void SetOrdenado(float _ord_b) { ord_b = _ord_b; }
	void SetExtra(int _h_extra) { h_extra = _h_extra; }
	void SetPreco_Extra(float _p_h_extra) { p_h_extra = _p_h_extra; }

	int GetNum(void) { return num; }
	string GetSetor(void) { return setor; }
	float GetOrdenado(void) { return ord_b; }
	int GetExtra(void) { return h_extra; }
	float GetPreco_Extra(void) { return p_h_extra; }

	// ainda aliena 6.1
	virtual float Calc_Ordenado(void) = 0;



	friend ostream& operator << (ostream& os, Funcionario& F);
	friend istream& operator >> (istream& is, Funcionario& F);

	virtual void Show(void);
	virtual void ReadK(void);

	virtual void SaveFile(ofstream& os);
	virtual void ReadFile(ifstream& is);

};
