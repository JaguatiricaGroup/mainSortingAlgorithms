#include <iostream>=

using namespace std;

#include <stdio.h>
#include <iostream>




void merge_sort(int v[],int esq,int m,int dir){
    int t1= m-esq+1;
    int t2= dir-m;
    int E[t1], D[t2];

    for(int i=0;i<t1;i++){
        E[i]=v[esq+i];

    }
    for(int j=0;j<t2;j++){
       D[j]=v[m+1+j];
    }

    int i=0, j=0,k=esq;

    while(i<t1 && j<t2){
        if(E[i]<=D[j]){
            v[k]=E[i];
            i++;
          }
        else{
            v[k]=D[j];
            j++;
        }
        k++;
    }

    while(i<t1){
        v[k]=E[i];
        i++;
        k++;
    }

    while(j<t2){
        v[k]=D[j];
        j++;
        k++;
    }

}

void merge_sort2(int v[],int inicio,int fim){

    if(inicio<fim){
    int e=(inicio +fim)/2;

    merge_sort2(v,inicio,e);
    merge_sort2(v,e+1,fim);

    merge_sort(v,inicio,e,fim);
    }


}

void print_vetor(int v[],int o){
    for(int i=0;i<o;i++){
        std::cout<< v[i] <<" ";
    }

}


int main(int argc, char** argv) {
    int l[8]={4,15,16,50,8,23,42,108};
    //int l[8]={8,2,6,5,4,3,7,1};
    

    merge_sort2(l,0,7);
    print_vetor(l,8);
    return 0;
}
