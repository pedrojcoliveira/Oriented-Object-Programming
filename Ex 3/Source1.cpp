#include "Data.h"

int main()
{
	//alinea e)
	Data da; //construtor por omissão
	Data db(1, 1, 2014);  // construtor por parâmetros

	cout << "Data do construtor por omissao/defeito" << endl;
	da.Show();
	cout << "Data do construtor por parametros" << endl;
	db.Show();

	int dia, mes, ano;
	/*cout << "Introduza o novo dia: " << endl;
	cin >> dia;
	cout << "Introduza o novo mes: " << endl;
	cin >> mes;
	cout << "Introduza o novo ano: " << endl;
	cin >> ano;*/
	da.SetDia(dia);
	da.SetMes(mes);
	da.SetAno(ano);
	db.Update(dia, mes, ano);
	cout << "Nova data do construtor por omissao/defeito" << endl;
	da.Show();
	cout << "Nova data do construtor por parametros" << endl;
	db.Show();

	// alinea f)
	cout << "alinea f)" << endl;
	if (db.Igual(da))
		cout << "Datas iguais" << endl;
	else
		cout << "Datas diferentes" << endl;

	// ou 
	// alinea g)
	cout << "alinea g)" << endl;
	if (da == db)
		cout << "Datas iguais" << endl;
	else
		cout << "Datas diferentes" << endl;

	// aliena h)
	cout << "alinea h)" << endl;
	if (da != db)
		cout << "Datas diferentes" << endl;
	else
		cout << "Datas iguais" << endl;

	// alinea i)
	Data dc;
	cin >> dc;

	cout << "alinea i) --  novo objeto lido com o operador >>" << endl;
	dc.Show();

	cout << "alinea j)" << endl;
	cout << da << "\n" << db << endl << dc << endl;

	//fflush(stdin);
	//cin.get();

	// aliena k)
	cout << "alinea k)" << endl;
	Data my_data;
	my_data.Update(2, 3, 2021);

	ofstream os;

	os.open("datas.txt");
	if (!os)
	{
		cout << "ERRO: nao e possivel abrir o ficheiro datas.txt" << '\n';
		exit(1);
	}

	my_data.SaveFile(os);

	os.close();

	ifstream is;

	is.open("datas.txt");
	if (!is) {
		cout << "ERRO: nao e possivel abrir o ficheiro datas.txt" << '\n';
		exit(1);
	}
	Data nova_data;

	nova_data.ReadFile(is);
	cout << nova_data;
	os.close();

	cin.get();

	return 0;
}
