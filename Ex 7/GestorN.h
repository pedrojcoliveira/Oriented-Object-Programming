#include<list>

using namespace std;
class GestorN //Gestor_Num
{
private:
	list<int> lista;

public:
	//construtor e destrutor
	GestorN();
	~GestorN();

	//médodos de acesso
	void SetLista(list<int> _lista);
	list<int> GetLista();

	//métodos para manipular a lista (Exercício 7)
	void InserirInicio(int num); //alinea a
	void InserirFinal(int num); // alinea a
	void Remover(int num); // alinea b
	void Show(); //alinea c

	int EncontrarIndice(int num); //alinea d

	//código extra ao exercício
	friend ostream& operator << (ostream& os, GestorN& g);
	friend istream& operator >> (istream& is, GestorN& g);
	void ReadFile(ifstream& is);
	void SaveFile(ofstream& os);

};