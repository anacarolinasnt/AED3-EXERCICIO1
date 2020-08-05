#include <iostream>

using namespace std;

struct celula
{
	string nome;
	celula *proxima;
};

void imprimir(celula *l)
{
	while(l != NULL)
	{
		cout<< l-> nome << "  " <<endl; // para dar espaço tem que concatenar (colocar <<) 
		l = l-> proxima;
	}
}

int main ()
{
	celula *lista = NULL;
	celula *nova = new celula;
	nova -> nome = " Ana ";
	nova->proxima = NULL;
	lista = nova;
	
	nova = new celula; 
	nova->nome = " Adriano ";
	nova -> proxima = lista;
	lista = nova;
	
	imprimir(lista);
	
	return 0;
}