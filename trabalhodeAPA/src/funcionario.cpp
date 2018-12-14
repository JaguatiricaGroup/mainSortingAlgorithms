#include "funcionario.h"
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>

using namespace std;


funcionario::funcionario()
{

}

funcionario::funcionario(int chave,int nome,float salario)
{
    this->chave=chave;
    this->nome=nome;
    this->salario=salario;
}

funcionario::~funcionario()
{
    //dtor
}

void funcionario::BubbleSortItr(funcionario* vet, int tam){
	bool swapped = true;
	while(swapped){
		swapped = false;
		for (int i=0; i<tam-1; i++){
			if (vet[i].getChave() > vet[i+1].getChave()){
				funcionario aux = vet[i+1];
				vet[i+1] = vet[i];
				vet[i] = aux;
				swapped = true;
			}
		}
	}
}

void funcionario::insertionSortItr(funcionario* array, int tam){
	for (int i=1; i<tam; i++){
		funcionario atual = array[i];
		int j;
		for (j=i-1; j>=0 && array[j].getChave() > atual.getChave(); j--){
			array[j+1] = array[j];
		}
		array[j+1] = atual;
	}
}


void funcionario::quickSort(funcionario* array,int init, int fim){
	int i, j, meio;
	i = init;
	j = fim;
	meio = (int) (i+j)/2;
	funcionario p = array[meio], aux;
	while(i <= j){
		while (array[i].getChave() < p.getChave())	i = i+1;
		while (array[j].getChave() > p.getChave())	j = j-1;

		if (i <= j){
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
            i = i+1;
            j = j-1;
		}

	}
	if (j > init)	quickSort(array, init, j);
	if (i < fim)	quickSort(array, j+1, fim);
}


void funcionario::heapSort(funcionario* a, int n) {
    if (n == 0) return; //verifica se o vetor está vazio
    int i = n / 2, j, k; // indices do heap
    funcionario t; //auxiliar, para trocas
    while(true) {
        if (i > 0) {
            i--; // --- primeiro passo, montando o heap
            t = a[i]; //salvando o valor em t
        } else {
            n--; // --- segundo passo, colocando valores no lugar // diminuindo o heap
            if (n == 0) return; //quando termina o algoritmo
            t = a[n]; // salvando valor num temporario
            a[n] = a[0]; //colocando a raiz no inicio
        }
        j = i; // começa no pai
        k = i * 2 + 1; // pega o filho a esquerda
        while (k < n) {
            if ((k + 1 < n)  &&  (a[k + 1].getChave() > a[k].getChave())) //escolhe o maior filho
                k++;
            if (a[k].getChave() > t.getChave()) {
                a[j] = a[k]; // realoca o filho
                j = k; // move o indice para o do filho
                k = j * 2 + 1; // pega o filho a esquerda para recomeçar
            } else {
                break; //ja esta no lugar
            }
        }
            a[j] = t; // realoca o valor temporario em sua nova posição
    }
}
/*
void funcionario::heapSort2(funcionario* a, int n){
    a->constroiHeap(a, n);
    funcionario aux;
    for (int m = n; m>=2; m--){
        aux = a[1];
        a[1] = a[m];
        a[m] = aux;
        a->max_heap(a,1, m-1);
    }
}

void funcionario::constroiHeap(funcionario* a, int n){
    for (int k = n/2; k>=1; k--){
        max_heap(a, k, n);
    }
}

void funcionario::max_heap(funcionario* a, int i, int n){
    int l,r,largest;
    funcionario aux;
    l=2*i;
    r=(2*i+1);
    if((l<=n)&&a[l].getChave()>a[i].getChave())
       largest=l;
    else
       largest=i;
    if((r<=n)&&(a[r].getChave()>a[largest].getChave()))
       largest=r;
    if(largest!=i)
    {
         aux=a[i];
         a[i]=a[largest];
         a[largest]=aux;
         max_heap(a, largest,n);
    }

}
*/

void funcionario::heapSort2(funcionario* a, int n){
    a->constroiHeap(a, n);
    funcionario aux;
    for (int m = n; m>=1; m--){
        aux = a[0];
        a[0] = a[m];
        a[m] = aux;
        a->corrige(a, m-1);
    }
}

void funcionario::constroiHeap(funcionario* a, int m){
    int k;
    funcionario aux;
    for (k = 0; k<m; k++){
        int f = k+1;
        while (f>0 && a[f/2].getChave() < a[f].getChave()){
            aux = a[f/2];
            a[f/2] = a[f];
            a[f] = aux;
            f/=2;
        }
    }
}

void funcionario::corrige(funcionario* a, int m){
    int p =0, f =1;
    funcionario t = a[0];
    while (f <=m){
        if (f < m && a[f].getChave() < a[f+1].getChave())   f++;
        if (t.getChave() >= a[f].getChave())    break;
        a[p] = a[f];
        p = f; f = 2*p;
    }
    a[p] = t;
}
void funcionario::selectionSort(funcionario* array, int tam){
	int min;
	funcionario aux;

	for (int i=0; i<tam-1; i++){
		min = i;
		for (int j=i+1; j<tam; j++)
			if (array[j].getChave() < array[min].getChave())
				min = j;
		if (min != i){
			aux = array[min];
			array[min] = array[i];
			array[i] = aux;
		}
	}
}

void funcionario::mergeSort(funcionario *array, int init, int fim){
    if (init < fim){
        int meio = (init+fim)/2;
        mergeSort(array, init, meio);
        mergeSort(array, meio + 1, fim);
        mergeArray(array, init, meio, fim);
    }
}

void funcionario::mergeArray(funcionario* array,int init,int meio,int fim){
    int com = init, mid = meio+1, aux = 0;
    funcionario vetAux[fim-init+1];

    while (com<=meio && mid<=fim){
        if (array[com].getChave() <= array[mid].getChave()){
            vetAux[aux] = array[com];
            com++;
        }else{
            vetAux[aux] = array[mid];
            mid++;
        }
        aux++;
    }

    while (com<=meio){
        vetAux[aux] = array[com];
        aux++; com++;
    }
    while (mid<=fim){
        vetAux[aux] = array[mid];
        aux++; mid++;
    }

    for (aux = init; aux <= fim; aux++){
        array[aux] = vetAux[aux - init];
    }
}

bool funcionario::estaOrdenado(funcionario* array, int tam){
    int i = 0;
    while (i<tam-1){
        if (array[i].chave > array[i+1].chave)
            return false;
        i++;
    }
    return true;
}

void funcionario::printArray(funcionario* array, int tam){
	cout<<"\n";
	for (int i=0; i<tam; i++){
		cout<<array[i].getChave()<<" ";
	}
	cout<<"\n";
}
