#include "Pessoa.h"
#include "Funcionario.h"
#include "Data.h"
#include "Operario.h"
#include "Administrativo.h"

#define N 100

int main()
{
	// alinea 6.5 a)
	ifstream ifile;
	ofstream ofile;
	char aux[100], op;
	char id;
	int i, j, num, novo_ord, size = 0;
	bool flag = false;
	Funcionario* P[N];
	Operario* O;
	Administrativo* A;

	//6a
	ifile.open("Funcionario.txt");
	if (!ifile) {
		cout << "ERRO: não é possível abrir o ficheiro Funcionario.txt" << '\n';
		exit(0);
	}

	while (ifile.peek() != EOF)
	{
		ifile.getline(aux, 2, ':');
		id = aux[0];
		if (id == 'O')
			P[size] = (Operario*) new Operario;
		else
			P[size] = (Administrativo*) new Administrativo;
		P[size]->ReadFile(ifile);
		ifile.get();
		size++;
	}
	ifile.close();

	for (i = 0; i < size; i++)
		P[i]->Show();

	// Em alternativa ao Show() poderíamos usar
	//cout << (*P[i]); 


    //aliena 6.5 b)
	cout << "Alinea 6.5 b): ordenado de todos os funcionários: " << endl;
	for (i = 0; i < size; i++)
	{
		cout << P[i]->GetNome() << ": " << P[i]->Calc_Ordenado() << " euros" << endl;
	}

	//6.c
	cout << "Numero do funcionario a procurar: ";
	cin >> num;
	for (i = 0; i < size; i++)
		if (num == P[i]->GetNum())
		{
			flag = true;
			cout << "Funcionario encontrado: ";
			cout << P[i]->GetNome() << endl;
		}
	if (!flag)
		cout << "Funcionario nao encontrado!" << endl;

	//6.d
	flag = false;
	cout << "Numero do funcionario a alterar ordenado: ";
	cin >> num;
	for (i = 0; i < size; i++)
		if (num == (P[i])->GetNum())
		{
			flag = true;
			cout << "Insira o novo ordenado do funcionario/a " << P[i]->GetNome() << ": ";
			cin >> novo_ord;
			P[i]->SetOrdenado(novo_ord);
		}
	if (!flag)
		cout << "Funcionario nao encontrado!" << endl;

	//6.e
	cout << "Adicionar no funcionario:  1- Operário 2 - Administrativo:  ";
	cin >> op;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	switch (op) {
	case '1': P[size] = (Operario*) new Operario;
		P[size]->ReadK();
		size++;
		break;

	case '2': P[size] = (Administrativo*) new Administrativo;
		P[size]->ReadK();

		size++;
		break;

	default: cout << "Opcao incorreta";
	}

	for (i = 0; i < size; i++)
		P[i]->Show();


	//6.f
	cout << endl << "Operarios que trabalham por turnos " << endl;
	for (i = 0; i < size; i++)
	{
		if (O = dynamic_cast <Operario*> (P[i]))
			if (O->GetFTurno() == true)
				P[i]->Show();
	}

	//6.g
	flag = false;
	cout << "Numero do funcionario a eliminar: ";
	cin >> num;
	for (i = 0; i < size; i++)
		if (num == P[i]->GetNum())
		{
			flag = true;
			delete P[i];
			P[i] = NULL;
			for (j = i; j < size - 1; j++)
				P[j] = P[j + 1];
			size--;
		}
	if (!flag)
		cout << "Funcionario nao encontrado!" << endl;

	//6.h
	ofile.open("Administrativos.txt");
	if (!ofile) {
		cout << "ERRO: não é possível criar o ficheiro Saida.txt" << '\n';
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		if (A = dynamic_cast <Administrativo*> (P[i]))
		{
			P[i]->SaveFile(ofile);
			ofile << "Ordenado Final: " << A->Calc_Ordenado() << endl;
		}
	}
	ofile.close();

	//6.i
	ofile.open("Operarios.txt");
	if (!ofile) {
		cout << "ERRO: não é possível criar o ficheiro Saida.txt" << '\n';
		exit(0);
	}
	for (i = 0; i < size; i++)
	{
		if (O = dynamic_cast <Operario*> (P[i]))
		{
			P[i]->SaveFile(ofile);
			ofile << "Ordenado Final: " << O->Calc_Ordenado() << endl;
		}
	}
	ofile.close();

	for (i = 0; i < size; i++)
	{
		delete P[i];
		P[i] = NULL;
	}
	size = 0;

	fflush(stdin);
	cin.get();

	return 0;
}
