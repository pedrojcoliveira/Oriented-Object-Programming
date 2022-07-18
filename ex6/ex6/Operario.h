#pragma once
#include "Funcionario.h"

// alinea 6.2
class Operario :
	// alinea 6.2
	public Funcionario
{
private:
	// alinea 6.2
	bool f_turno;

public:
	// alinea 6.2
	Operario();
	Operario(bool _f_turno, float _p_h_extra, int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, Data _data);
	Operario(bool _f_turno, float _p_h_extra, int _h_extra, float _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Operario();

	// alinea 6.3
	void SetFTurno(bool _f_turno) { f_turno = _f_turno; }
	bool GetFTurno(void) { return f_turno; }

	// alinea 6.4
	float Calc_Ordenado(void);

	void Show(void);
	void ReadK(void);

	friend ostream& operator << (ostream& os, const Operario O);
	friend istream& operator >> (istream& is, Operario& O);

	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);

};