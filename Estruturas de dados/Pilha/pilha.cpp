#include <iostream>
#include "pilha.h"

using namespace std;

    pilha::pilha() //construtora
    {
        tamanho = 0;
        estrutura = new TipoItem[max_itens];
    }

    pilha::~pilha() //destrutora
    {
        delete [] estrutura;
    }

    bool pilha::estacheia()
    {
        return (tamanho == max_itens);
    }

    bool pilha::estavazia()
    {
        return(tamanho == 0);
    }

    void pilha::inserir(TipoItem item) //push inserir item
    {
        if(estacheia()){
            cout << "A pilha esta cheia\n";
            cout << "Nao e possivel inserir este elemento!\n";
        } else {
            estrutura[tamanho] = item;
            tamanho++;
        }
    }

    TipoItem pilha::remover()// pop 
    { 
        if(estavazia()){
            cout << "A pilha esta vazia!\n";
            cout << "Nao tem elemento para ser removido!\n";
            return 0;
        } else {
            tamanho--;
            return estrutura[tamanho];
        }
    }

    void pilha::imprimir()
    {
        cout << "Pilha: [ ";
        for(int i = 0; i < tamanho; i++){
            cout << estrutura[i] << " ";
        }
        cout << "]\n";
    }

    int pilha::qualtamanho()
    { 
        return tamanho;
    }