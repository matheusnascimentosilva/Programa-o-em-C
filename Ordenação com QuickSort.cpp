#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
	PROGRAMACAO FEITA EM C POR MATHEUS NASCIMENTO SILVA
	Github: https://github.com/matheusnascimentosilva
*/
//PROTOTIPOS___________________________________
void quick_sort(int *vetor,int left, int right);
void imprime_vetor(int *vetor,int tam);

int main(){
    srand(time(NULL));
    int x,tam;
    int *vetor;
        printf("Qual o tamanho do vetor ?\n");
        scanf("%d",&tam);
        vetor = (int *) malloc(tam * sizeof(int));//ALOCACAO DINAMICA

        for(x=0;x<tam;x++){
            vetor[x] = rand() % 100;
        }
        //MOSTRANDO OS RESULTADOS
        printf("Valores aleatorios:\n\n");
        imprime_vetor(vetor,tam);
        quick_sort(vetor,0,tam-1);
        printf("\n\n");
        printf("Valores ordenados:\n");
        imprime_vetor(vetor,tam);
		
		//LIBERAR ESPACO NA MEMORIA
        free(vetor);
    return 0;
}

//IMPLEMENTACOES DAS FUNCOES
void imprime_vetor(int *vetor,int tam){
    int x; 
        for(x=0;x<tam;x++){
            printf("[%d] ",vetor[x]);
        }
}
//IMPLEMENTACAO DO QUICKSORT
/*
	IMPLEMENTACAO BASEADA DO SITE: http://www.programasprontos.com/algoritmos-de-ordenacao/algortimo-quick-sort/
*/
void quick_sort(int *vetor,int left, int right){
    int i, j, x, y;
     
    i = left;
    j = right;
    x = vetor[(left + right) / 2];
     
    while(i <= j) {
        while(vetor[i] < x && i < right) {
            i++;
        }
        while(vetor[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(vetor, left, j);
    }
    if(i < right) {
        quick_sort(vetor, i, right);
    }
}
