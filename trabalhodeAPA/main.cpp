#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "funcionario.h"
#include <ctime>
#include <string>

using namespace std;

void geraChaves(funcionario *funcionarios, int val, int tipo) { //tipo 1 = ordenada, 2 = semiordenada, 3 = aleatoria, 4 = ordenada inversamente
    srand (time(NULL));

    if (tipo == 1) {
        for (int i=0; i<val; i++){
            funcionarios[i].setChave(i);
        }
    }

    if (tipo == 2) {
        int quant;
        for (int i=0; i<val; i++){
            quant = i;
            if (i!=0 && i%7==0)
                quant = rand() %10000;
            funcionarios[i].setChave(quant);
        }
    }

    if (tipo == 3) {
        for (int i=0; i<val; i++)
            funcionarios[i].setChave(rand() %10000);
    }

    if (tipo == 4) {
        int quant = val;
        for (int i=0; i<val; i++){
            funcionarios[i].setChave(quant);
            quant--;
        }
    }
}

//alg 1=bubble, 2=insertion, 3=selection, 4=quick, 5=heap, 6=merge
//tipo 1 = ordenada, 2 = semiordenada, 3 = aleatoria, 4 = ordenada inversamente
void callAlgoritmo(funcionario *funcionarios, int val, int tipo, int alg) { //chama os algoritmos e calcula o tempo de execução
    clock_t t1, t2;

    string type;
    if (tipo ==1)
        type = "ORDENADOS";
    else if (tipo ==2)
        type = "SEMIORDENADOS";
    else if (tipo ==3)
        type = "ALEATORIOS";
    else
        type = "ORDENADOS INVERSAMENTE";

    switch (alg) {
        case 1:
            cout<< "BUBBLE SORT"<<endl;
            cout<< type <<endl;
            t1 = clock();
            funcionarios->BubbleSortItr(funcionarios, val);
            t2 = clock();
            break;
        case 2:
            cout<< "INSERTION SORT" << endl;
            cout << type<<endl;
            t1 = clock();
            funcionarios->insertionSortItr(funcionarios, val);
            t2 = clock();
            break;
        case 3:
            cout<< "SELECTION SORT" << endl;
            cout << type<<endl;
            t1 = clock();
            funcionarios->selectionSort(funcionarios, val);
            t2 = clock();
            break;
        case 4:
            cout<< "QUICK SORT" << endl;
            cout << type<<endl;
            t1 = clock();
            funcionarios->quickSort(funcionarios,0, val-1);
            t2 = clock();
            break;
        case 5:
            cout<< "HEAP SORT"<< endl;
            cout << type<<endl;
            t1 = clock();
            funcionarios->heapSort(funcionarios,val);
            t2 = clock();
            break;
        case 6:
            cout<< "MERGE SORT"<< endl;
            cout << type<<endl;
            t1 = clock();
            funcionarios->mergeSort(funcionarios, 0, val-1);
            t2 = clock();
            break;
    }

    float diff = ((float)(t2 - t1) / CLOCKS_PER_SEC  ); //calculando tempo de execução
    cout << diff<<endl;
}


int main(int argc, char* argv[]){
    int quant = 3, //quantidade inicial
        multi = 1, //multiplicador
        tipo = 1;
    funcionario* funcionarios;

//variando algoritmo, tipo de ordenação e quantidade de elementos
//    for (multi = 1; multi < 100000; multi = multi*10) {
        quant = atoi(argv[1]);
        //string::argv[1];//*quant
        funcionarios = (funcionario*) malloc(quant*sizeof(funcionario));
        for(tipo = 1; tipo <= 4; tipo++) { //tipo 1 = ordenada, 2 = semiordenada, 3 = aleatoria, 4 = ordenada inversamente
            geraChaves(funcionarios, quant, tipo);
            for (int alg = 1; alg<=6; alg++) //1=bubble, 2=insertion, 3=selection, 4=quick, 5=heap, 6=merge
                callAlgoritmo(funcionarios, quant, tipo, alg);
        }
//	}
}
