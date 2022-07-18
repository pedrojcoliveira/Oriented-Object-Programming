
#include <iostream>
#include <fstream>

using namespace std;

class Data
{
private:
	int ano, mes, dia;

public:
	//alinea a)
	Data();
	Data(int _dia, int _mes, int _ano);
	virtual ~Data();

	//alinea b)
	void SetDia(int _dia) { dia = _dia; }
	void SetMes(int _mes) { mes = _mes; }
	void SetAno(int _ano) { ano = _ano; }
	// para ver a diferença entre métodos inline e normal
	int GetDia(void);
	//int GetDia(void) { return dia; }
	int GetMes(void) { return mes; }
	int GetAno(void) { return ano; }

	// alinea c)
	void Show(void);

	// alinea d)
	void Update(int _dia, int _mes, int _ano);

	// alinea f)
	bool Igual(const Data data);

	// alinea g)
	bool operator == (const Data data) const;

	// alinea h)
	bool operator != (const Data data) const;
	friend ostream& operator << (ostream& os, Data data);
	friend istream& operator >> (istream& is, Data& data);
	bool operator < (const Data data) const;
	bool operator > (const Data data) const;

	// alinea k)
	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);

};