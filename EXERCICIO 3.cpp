#include <iostream>
#include <stdlib.h>

using namespace std;

class celula
{
private:

	string nome;
	string sexo;
	int idade;
	bool cerveja;
	celula * proxima;
	
public:
	celula()
	{
		proxima = NULL;
	}
	
	celula(string n)
	{
		nome = n;
	}
	
	celula(string n, celula *prox)
	{
		nome = n;
		proxima = prox;
	}
	
	celula (string n, string sex, int id, bool cerv, celula *prox)
	{
		nome = n;
		idade = id;
		sexo = sex;
		cerveja = cerv;
		proxima = prox;   	
	}
	
	string getNome()
	{
		return nome;
	}
	
	int getIdade()
	{
		return idade;
	}
	
	string getSexo()
	{
		return sexo;
	}
	
	
	bool getCerveja()
	{
		return cerveja;
	}
	
	void setNome(string n)
	{
		nome = n;
	}

	celula * getProxima()
	{
		return proxima;
	}

	void setProxima(celula * l)
	{
		proxima = l;
	}
	
};


class lista
{
private:
	celula * inicio;

public:
	lista()
	{
		inicio = NULL;
	}
	~lista(){
		esvaziar();
	}
	lista(celula *i)
	{
		inicio = i;
	}
	celula * getInicio()
	{
		return inicio;
	}

	void inserirInicio(string nome, string sexo, int idade, bool cerveja)
	{
		celula *nova = new celula(nome, sexo, idade, cerveja, inicio);
	//	nova->setNome(n);
	//	nova->setProxima(inicio);
	//	nova->setMediaFinal(m);
		inicio = nova;
	}

	void inserirFim(string nome, string sexo, int idade, bool cerveja)
	{
		if(inicio == NULL)
		{
			inserirInicio(nome, sexo, idade, cerveja);
		}
		else
		{
			celula *aux = inicio;
			while(aux->getProxima() != NULL)
			{
				aux = aux->getProxima();
			}
			celula *nova = new celula(nome, sexo, idade, cerveja, NULL);
			aux->setProxima(nova); 
		}
	}

	void imprimir()
	{
		if(inicio == NULL)
		{
			cout << "Lista vazia.\n";
		}
		else
		{
			celula *aux = inicio;
			while(aux != NULL)
			{
			cout << "Nome:"  << aux->getNome() <<endl;
			cout << "Idade: " << aux->getIdade() << endl; 
			cout << "Sexo: "  << aux->getSexo() <<endl;
			cout << "Voce bebe cerveja? "; 
				
			if(aux->getCerveja()==1)
				cout<<" Sim "<<endl;
			else
				cout<<" Nao "<<endl;

			aux = aux->getProxima();
			
			cout<< endl;
			}
		}
	}
	
	void esvaziar()
	{
		celula *aux = inicio;
		while(aux != NULL)
		{
			inicio = inicio->getProxima();
			delete aux;
			aux = inicio;
		}
		cout << "\nLista esvaziada com sucesso.";
	}
};

int main()
{
	lista listaChurrasco;
	int op=0;
	string nome, sexo;
	int idade,aux;
	bool cerveja;
	
	
	do
	{
		cout << "   CHURRASCO SISTEMAS DE INFORMACAO.    ";
		cout <<endl;
		cout << "              MENU " <<endl;
		cout <<endl; 
		cout << "1 - Cadastrar pessoas." <<endl;
		cout << "2 - Imprimir lista do churrasco." <<endl;
		cout << "3 - Apagar a lista."<<endl;
		cout << " 4 - Encerrar programa." <<endl;
		cout <<endl;
		cout << "Escolha uma opção do menu. ";
		cin >> op;
		cout <<endl;
	
		if(op == 1)
		{
		cout << " Cadastrar Pessoas" <<endl;
		cout<<"Nome: ";
		cin.ignore();cin>>nome;
		cout<<"Idade: ";
		cin>>idade;
		cout<<"Sexo: ";
		cin.ignore();cin>>sexo;
		cout<<"Voce bebe cerveja? (1) Sim (2) Nao: ";
		cin>>aux;
			
		if(aux==1)
		    cerveja = true;
	    else
			cerveja = false;
		
		cout<<endl;
		
		listaChurrasco.inserirInicio(nome,sexo,idade,cerveja);
					
	    } 
	    
		if (op == 2)
		{	
			cout << "  Imprimir Lista do Churrasco" <<endl;
			listaChurrasco.imprimir();
			cout<< endl;
		
		}
		
		if (op == 3)
		{	
			listaChurrasco.esvaziar();
			cout << "Lista apagada com sucesso!! "<<endl;

		}
		
		if (op == 4)
		{	
	       cout << "Encerrar programa " << endl;
		   cout << endl;	
		   system("pause");
		   cout<<endl;
		}
				
	}
	
	while(op!=4);
	
	return 0;
}
