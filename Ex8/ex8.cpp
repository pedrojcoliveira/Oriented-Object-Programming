#include "Gestor_Func.h"
#include "Opera.h"
#include "Admin.h"
#include "Data.h"

using namespace std;

int main()
{
	Gestor_Func gestor;
	string filename;

	//alinea a
	cout << "A ler dados dos funcinarios a partir de ficheiro de dados...\n\n";
	filename = "funcionarios.txt";

	gestor.ReadFile(filename);

	//alinea b
	cout << " *** LISTA DE FUNCIONARIOS ***\n";
	gestor.ShowFunc();

	//alinea c

	Opera op1(false, 15, 1100, 25050, "Pintura", "Zeca Estacionancio", "Rua A n9", Data(1, 1, 1985));
	Admin ad1(0, 900, 25051, "Rec Humanos", "Adrusila Lopes", "Rua E n6", Data(6, 6, 1996));

	gestor.SetFunc(&op1, 0);
	gestor.SetFunc(&ad1, 0);
	//gestor.AddFunc("A");
	cout << "\nAdicionados 2 funcionarios.\n";

	cout << "\n";
	cout << " *** LISTA DE FUNCIONARIOS ***\n";

	gestor.ShowFunc();


	//alinea d

	gestor.RemoveFunc(25023); //Joca Gaio

	cout << "\n";
	cout << "Fucionario Joca Gaio removido.\n\n";
	gestor.ShowFunc();

	//alinea e

	ofstream ofile;
	ofile.open("funcionarios_out.txt");
	if (!ofile)
	{
		cout << "Erro ao gravar ficheiro...\n";
	}
	else
	{
		gestor.SaveFile(ofile);
		cout << "\nFuncionarios gravados em ficheiro...\n\n";

	}

	system("pause");
	return 0;
}
