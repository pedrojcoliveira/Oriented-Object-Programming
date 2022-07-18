#include "Data.h"
#include "Pessoa.h"
#include <string>
#include <fstream>

using namespace std;

#define N 3

int main()
{
	// alinea b)
	Pessoa a("Jonas Culatra", "Rua da direita n2", Data(20, 9, 1987)),
		b("Joni Rato", "Rua da esquerda n3", 4, 2, 1990), c;

	//a pessoa "a" também poderia ser definida da seguinte forma:
	//Data d(20, 9, 1987);
	//Pessoa a("Jonas Culatra","Rua da direita n2",d);
	

	// alinea c)
	a.Show();
	b.Show();
	c.Show();


	// alinea d)
	char aux[100];
	cout << "Nova Morada: ";
	cin.getline(aux, sizeof aux);
	a.SetMorada(aux);
	a.Show();

	// alinea e)
	cout << "Alteração data Nascimento: " << "\n Insira nova data" << endl;
	Data data;
	cin >> data;
	b.SetData(data);
	b.Show();

	cout << "Só para ver como poderiamos apresentar apenas o ano: " << b.GetData().GetAno() << endl;
	

	// alinea f)
	cin.get();
	Pessoa d;
	d.ReadK();  
	d.Show();

	// alinea g)
	cin.get();
	Pessoa e;
	cin >> e;
	cout << e;

	/*
	// para verificar se as datas são iguais ou não
	Data a1(2, 2, 2), b1(2, 2, 2), c1(3,3,3);

	if (a1 == b1) cout << "\n As datas são iguais" << endl;
	else cout << "\nAs datas são diferentes" << endl;

	if (a1 == c1) cout << "\n As datas são iguais" << endl;
	else cout << "\nAs datas são diferentes" << endl;
	*/

	// alinea h)
	if (a == c)
		cout << "As pessoas são iguais" << endl;
	else 
		cout << "As pessoas são diferentes" << endl;

	if (a == a)
		cout << "As pessoas são iguais" << endl;
	else
		cout << "As pessoas são diferentes" << endl;

	// alinea i)
	if (a.MaisNovo(b))
		cout << a.GetNome() << " é mais novo do que " << b.GetNome() << endl;
	else
		cout << a.GetNome() << " é mais velho do que " << b.GetNome() << endl;


	// alinea j)
	string str;
	//cout << "Introduza o nome do ficheiro a abrir: ";
	//cin >> str; 

	str = "pessoas.txt";
	ofstream ofile;

	ofile.open(str);

	if (ofile)
	{
		a.SaveFile(ofile);
		b.SaveFile(ofile);
		//c.SaveFile(ofile);
		ofile.close();
		cout << "Ficheiro " << str << " criado com sucesso!" << endl << endl << endl;
	}
	else
		cout << "ERRO: não é possível abrir o ficheiro" << str << '\n';


	// alinea l)
	Pessoa P[N];      //Pessoa * P[N];
	int size = 0, i;

	ifstream ifile;

	ifile.open(str);
	if (ifile)
	{
		while (ifile.peek() != EOF)
		{
			//P[size] = (Pessoa *) new Pessoa;  //
			//P[size]->ReadFile(ifile);         // 
			P[size].ReadFile(ifile);
			ifile.get();
			size++;
		}
		ifile.close();
		cout << "Ficheiro pessoas.txt lido  para memoria (vetor), com sucesso. " << endl;
	}
	else
		cout << "ERRO: não é possível abrir o ficheiro data.txt" << '\n\n\n';

	cout << "Pessoas lidas do ficheiro" << endl << endl;
	for (i = 0; i < size; i++)
	{
		//P[i]->Show();      
		P[i].Show();
	}


	// aline m)
	cout << "Pessoas nascidas antes de 1990" << endl << endl;
	for (i = 0; i < size; i++)
	{
		if (P[i].GetData().GetAno() < 1990)
				//P[i]->Show();
				P[i].Show();
	}

	cin.get();

	return 0;
}
