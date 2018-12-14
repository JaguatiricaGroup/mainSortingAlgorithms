#include <math.h>
#include <iostream>
#include <stdlib.h>


#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


class funcionario
{
    public:
        funcionario();
        funcionario(int chave,int nome,float salario);
        virtual ~funcionario();
        void BubbleSortItr(funcionario* vet, int tam);
        void insertionSortItr(funcionario* array, int tam);
        void quickSort(funcionario* array,int init, int fim);
        void heapSort(funcionario* a, int n);
        void heapSort2(funcionario* a, int n);
        void constroiHeap(funcionario* a, int m);
        void max_heap(funcionario* a,int i, int n);
        void corrige(funcionario* a, int m);

        void selectionSort(funcionario* array, int tam);
        void printArray(funcionario* array, int tam);
        void mergeSort(funcionario* array, int init, int fim);
        void mergeArray(funcionario* array, int init, int meio, int fim);
        void mergeArray2(funcionario* array, int init, int meio, int fim);
        funcionario* sortArray(int tam);
        bool estaOrdenado(funcionario* array, int tam);
        void setChave(int k){ this->chave=k;};
        int getChave(){ return this->chave; };
        void setNome(int k){ this->nome=k;};
        int getNome(){ return this->nome; };
        void setChave(float k){ this->salario=k;};
        float getSalario(){ return this->salario; };

    private:
    int chave;
	int nome;
	float salario;
};

#endif // FUNCIONARIO_H
