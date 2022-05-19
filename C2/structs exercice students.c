#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _alunos{
    char nome[100];
    int numero;
    float nota;
} aluno;

aluno* create_aluno(const char *nome, int numero, float nota){
    aluno* estudante = (aluno*)calloc(1,sizeof(aluno));
    strcpy(estudante->nome, nome);
    estudante->numero = numero;
    estudante->nota = nota;

    return estudante;
}

void print_aluno(const aluno* estudante){
    printf("%s\n", estudante->nome);
    printf("numero do aluno: %i\n", estudante->numero);
    printf("nota do aluno: %.2f\n", estudante->nota);
}

void destroy_aluno(aluno** ref_alun){
    aluno* ref = *ref_alun;
    free(ref);
    *ref_alun = NULL;
}

int main(){

    aluno** aluno1 = create_aluno("marcos", 34, 8.5);
    print_aluno(aluno1);
    destroy_aluno(&aluno1);
    printf("destroyed: %i", aluno1 == NULL);
    
    return 0;
}