#include "Pessoa.h"
#include "Funcionario.h"
#include "Data.h"

void BubbleSort(Funcionario* A, int size);
void SelectionSort(Funcionario* A, int size);
void InsertionSort(Funcionario* A, int size);
void Swap(Funcionario* x, Funcionario* y);

int main()
{
	// alinea 5.4
	Funcionario a(25023, "Pintura", "Joca Gaio", "Rua da direita n2", 20, 9, 1987);
	Funcionario b(25024, "Comercial", "Ana Rola", "Rua da esquerda n3", 4, 2, 1990);

	// alinea 5.5
	cout << "Apenas dados da pessoa" << endl;
	((Pessoa)a).Show(); // para invocar o método Show da classe Pessoa
	cout << "Todos os dados do funcionario" << endl;
    a.Show(); // para invocar o método Show da classe Funcionario
	cin.get();

	// alinea 5.6
	a.SetMorada("Rua do meio n4");
	a.SetSetor("Ferragem");
	a.Show();
	cin.get();

	// alinea 5.7
	Data dtn = b.GetData();
	dtn.SetDia(23);
	b.SetData(dtn);
	b.Show();
	cin.get();

	// alinea 5.9
	Funcionario c, d;
	fflush(stdin);
	cin >> c;
	//c.ReadK();
	fflush(stdin);
	cin.get();
	cin >> d;
	//d.ReadK();
	c.Show();
	d.Show();
	cin.get();

	// alinea 5.11
	ofstream ofile;
	ifstream ifile;
	string str;
	int i, contador;

	//cout << "Nome do ficheiro: ";
	//cin >> str;
	str= "funcionarios.txt";

	ofile.open(str);
	if (ofile)
	{
		a.SaveFile(ofile);
		b.SaveFile(ofile);
		c.SaveFile(ofile);
		d.SaveFile(ofile);
		ofile.close();
		cout << "Ficheiro " << str << " foi criado com sucesso!" << endl;
	}
	else
		cout << "ERRO: não é possível abrir o ficheiro " << str << '\n';

	fflush(stdin);
	cin.get();
	
	// alinea 5.13
	Funcionario vetor[4];

	ifile.open(str);
	if (ifile)
	{
		//for (int i = 0; i < 4; i++)
		//	vetor[i].ReadFile(ifile);
		contador = 0;
		while (ifile.peek() != EOF) {
			vetor[contador].ReadFile(ifile);
			contador++;
		}

		ifile.close();
		cout << "Ficheiro " << str << " lido com sucesso!" << endl;
	}
	else
		cout << "ERRO: não é possível abrir o ficheiro " << str << '\n';

	for (int i = 0; i < contador; i++)
		cout << vetor[i] << "\n";

	fflush(stdin);
	cin.get();

	// alinea 5.14
	SelectionSort(vetor, 4);

	for (int i = 0; i < contador; i++)
		cout << vetor[i] << "\n";

	fflush(stdin);
	cin.get();

	return 0;
}

void BubbleSort(Funcionario* A, int size)
{
	bool swaped;
	int i, j;

	i = size;
	do {
		swaped = false;
		for (j = 1; j < i; j++)
			if ((A + j - 1)->GetData() < (A + j)->GetData())
			{
				Swap(A + j - 1, A + j);
				swaped = true;
			}
		i--;
	} while (i > 0 && swaped);
}

void SelectionSort(Funcionario* A, int size)
{
	int i, j, aux;

	for (i = 0; i < size - 1; i++)
	{
		aux = i;
		for (j = i + 1; j < size; j++)
			if ((A + j)->GetData() < (A + aux)->GetData())
				aux = j;
		Swap(A + aux, A + i);
	}
}

void InsertionSort(Funcionario* A, int size)
{
	int i, j;
	Funcionario aux;

	for (i = 1; i < size; i++)
	{
		aux = *(A + i);
		j = i;
		while (j > 0 && (A + j - 1)->GetNome() > aux.GetNome())
		{
			*(A + j) = *(A + j - 1);
			j = j - 1;
		}
		*(A + j) = aux;
	}
}

void Swap(Funcionario* x, Funcionario* y)
{
	Funcionario	aux;

	aux = *x;
	*x = *y;
	*y = aux;
}
