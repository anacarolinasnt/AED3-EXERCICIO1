#include <iostream>

using namespace std;

class celula
{
private:
    string nome;
    celula *proxima;
public:
    celula(){
        proxima = NULL;
    }
    
	celula(string _nome, celula* _proxima){
        nome = _nome;
        proxima = _proxima;
    }
    
    void setNome(string n){
        nome = n;
    }
    
    string getNome(){
        return nome;
    }
    
    void setProxima(celula *c){
        proxima = c;
    }
    
    celula * getProxima(){
        return proxima;
    }
};

 

class lista
{
private:
    celula * inicio;
    string nome;
	string reverencia;
public:
	lista(){
        inicio = NULL;
    }
    
    lista(string _nome, string _reverencia){
        inicio = NULL;
        nome = _nome;
        reverencia = _reverencia;
    }
    
    celula * getInicio(){
        return inicio;
    }
    
    void inserirInicio(string nome){
        celula * nova = new celula();
        //celula * nova2 = new celula(nome, nova);
        nova->setNome(nome);
        nova->setProxima(inicio);
        inicio = nova;
    }
    
    void inserirInicioConstrutor(string nome, celula *proxima){
        celula * nova = new celula(nome, proxima);
        inicio = nova;
    }
    
    void imprimir(){
        if(inicio == NULL){
            cout << "Lista vazia" << endl;
        }
        else{
            celula *aux = inicio;
            while(aux != NULL){
                cout << aux->getNome() << endl;
                aux = aux->getProxima();
            }
        }
    }
    
};

int main()
{
	cout << "Construtor sem parametros.\n" << endl;
    lista alunos;
    alunos.inserirInicio("Mailson");
    alunos.inserirInicio("Queiroz");
    alunos.inserirInicio("Miguel");
    alunos.imprimir();
    
    cout << "\nConstrutor com parametros.\n" << endl;
    lista alunos2;
    alunos2.inserirInicioConstrutor("Carolina", alunos2.getInicio());
    alunos2.inserirInicioConstrutor("Ana", alunos2.getInicio());
    alunos2.imprimir();
    return 0;
}