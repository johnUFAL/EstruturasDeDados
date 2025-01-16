#include <iostream>
#include "grafo.h"

using namespace std;
    
    Grafo::Grafo(int max, int valorarestanula)
    {
        numvertices = 0;
        maxvertices = 0;
        arestanula = valorarestanula;

        vertices = new TipoItem[maxvertices];

        matrizadjacencias = new int*[maxvertices];
        for (int i = 0; i < maxvertices; i++) {
            matrizadjacencias[i] = new int[maxvertices];
        }

        for (int i = 0; i<maxvertices; i++) {
            for (int j = 0; j<maxvertices; j++) {
                matrizadjacencias[i][j] = arestanula;
            }
        }

    }

    Grafo::~Grafo()
    {
        delete [] vertices;
        for (int i = 0; i < maxvertices; i++) {
            delete [] matrizadjacencias[i];
        } 
        delete [] matrizadjacencias;
    }

    int Grafo::obterindice(TipoItem item)
    {
        int indice = 0;
        while (item != vertices[indice]) {
            indice++;
        }
        return indice;
    }

    bool Grafo::estacheio()
    {
        return (numvertices == maxvertices);
    }
    
    void Grafo::inserevertice(TipoItem item)
    {
        if (estacheio()) {
            cout << "O numero maximo de vertices oi alcançado!\n";
        } else {
            vertices[numvertices] = item;
            numvertices++;
        }
    }
    
    void Grafo::inserearesta(TipoItem Nosaida, TipoItem Noentrada, int peso)
    {
        int linha = obterindice(Nosaida);
        int coluna = obterindice(Noentrada);
        matrizadjacencias[linha][coluna] = peso;
        matrizadjacencias[coluna][linha] = peso; //remover se for direcionado
    }
    
    int Grafo::obterpeso(TipoItem Nosaida, TipoItem Noentrada)
    {
        int linha = obterindice(Nosaida);
        int coluna = obterindice(Noentrada);
        return (matrizadjacencias[linha][coluna]);
    }
    
    int Grafo::obtergrau(TipoItem item)
    {
        int linha = obterindice(item);
        int grau = 0;
        for (int i = 0; i < maxvertices; i++) {
            if (matrizadjacencias[linha][i] != arestanula) {
                grau++;
            }
        }
        return grau;
    }
    
    void Grafo::imprimirmatriz()
    {
        cout << "Matriz de Adjacencias: \n";
        for (int i = 0; i < maxvertices; i++) {
            for (int j = 0; j < maxvertices; j++) {
                cout << matrizadjacencias[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void Grafo::imprimirvertices()
    {
        cout << "Lista de Vertices: \n";
        for (int i = 0; i < maxvertices; i++) {
            cout << i << " " << vertices[i] << endl;
        }
    }