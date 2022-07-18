#include<list>
#include<map>
#include "Func.h"

using namespace std;

class Gestor_Func
{
private:
	list<Func*> lista;
	map<int, float> map_of_salarios; //exercicio 9
public:
	
	// 8.1
	Gestor_Func();
	~Gestor_Func();

	void SetLista(list<Func*> _lista);
	list<Func*> GetLista(void);

	// 8.2
	void ReadFile(string filename); //alinea a
	void ShowFunc(void); //alinea b
	void AddFunc(string tipo); //alinea c
	void RemoveFunc(int num); //alinea d
	friend ostream& operator << (ostream& os, Gestor_Func& GF); //alinea e
	friend istream& operator >> (istream& is, Gestor_Func& GF); //alinea e
	void SaveFile(ofstream& os); //alinea f

	// extra
	void SetFunc(Func*, int posicao); // inserir um funcionário na "posicao"
	Func* GetFunc(string nome); // retorna um dado funcionário -- pesquisa por nome

	// ******* EXERCICIO 9 *******
	void GenerateMap();
	void ShowMapValue(int num);
};
