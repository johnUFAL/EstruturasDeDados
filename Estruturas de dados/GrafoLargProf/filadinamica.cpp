#include <iostream>
#include "filadinamica.h"
#include <cstddef> //NULL
#include <new>

using namespace std;

    filadinamica::filadinamica()
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica()
    {
        No* temp;
        while (primeiro != NULL){
            temp = primeiro;
            primeiro = primeiro -> proximo;
            delete temp;
        }
    }	
    
    bool filadinamica::estavazio()
    {
        return (primeiro == NULL);
    }
    
    bool filadinamica::estacheio()
    {
        No* temp;
        try{
            temp = new No;
            delete temp;
            return false;
        } catch (bad_alloc exception){
            return true;
        }
    }
    
    void filadinamica::inserir(TipoItem item)
    {
        if (estacheio()){
            cout << "A fila esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else {
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NULL;
            if (primeiro == NULL){
                primeiro = NoNovo;
            } else {
                ultimo->proximo = NoNovo;
            }
            ultimo = NoNovo;
        }
    }
    
    TipoItem filadinamica::remover()
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nao foi possivel remover nenhum elemento!\n";
            return 0;
        } else {
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if (primeiro == NULL){
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }
    
    void filadinamica::imprimir()
    {
        No* NoTemp = primeiro;
        cout << "Fila: [ ";
        while (NoTemp != NULL){
            cout << NoTemp->valor << " ";
            NoTemp = NoTemp->proximo;
        }
        cout << "]\n";
    }
