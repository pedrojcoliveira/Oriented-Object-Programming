#pragma once
#include "Funcionario.h"

// alinea 6.2
class Administrativo :
	// alinea 6.2
	public Funcionario
{
public:
	// alinea 6.2
	Administrativo();
	Administrativo(float _p_h_extra, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data);
	Administrativo(float _p_h_extra, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Administrativo();

	// alinea 6.4
	float Calc_Ordenado(void);

	void Show(void);
	void ReadK(void);

	friend ostream& operator << (ostream& os, const Administrativo A);
	friend istream& operator >> (istream& is, Administrativo& A);

	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);

};