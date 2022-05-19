#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#define TAM 10

using namespace std; //para utilizar cout

void imprime_vetor(int vetor[TAM]){

    //Auxiliar contador
    int cont;

     //Imprime o vetor
    for(cont = 0; cont < TAM; cont++){
        cout << vetor[cont] << " - ";
    }

}

int busca_binaria(int vetor[TAM], int valorProcurado, int *posicaoEncontrada){

    int esquerda = 0;           //Limite da esquerda
    int direita = TAM - 1;      //Limite da direita
    int meio;                   //O meio onde fica o cursor

    while(esquerda <= direita){

        //Encontra o meio da an�lise
        meio = (esquerda + direita)/2;

        //Quando o valor do meio � encontrado
        if(valorProcurado == vetor[meio]){
            *posicaoEncontrada = meio;
            return 1;
        }

        //Ajustando os limites laterais
        if(vetor[meio] < valorProcurado){
            esquerda = meio + 1;
        }else{
            direita = meio - 1;
        }

    }

    return -1;

}

int main(){

    int vetor[TAM] = {1,23,44,56,63,72,84,90,98};
    int valorProcurado;
    int posicao, posicaoEncontrada;

    //Auxiliar contador
    int cont;

    //Imprime o vetor na tela
    imprime_vetor(vetor);

    //Lendo o n�mero buscado
    printf("Qual numero deseja encontrar?");
    scanf("%d", &valorProcurado);


    if(busca_binaria(vetor, valorProcurado, &posicaoEncontrada) == 1){
        cout << "O valor foi encontrado na posicao:" << posicaoEncontrada;
    }else{
        cout << "Valor nao encontrado";
    }

    return 0;

}

