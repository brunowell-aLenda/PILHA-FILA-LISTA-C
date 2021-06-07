#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "paciente.h"


struct listano
{
    Paciente* info;
    Listano* prox;
};


struct nofi
{
    Paciente* info;
    noFila* prox;
};


struct fila
{
    noFila* inicio;
    noFila* fim;
};


Fila* cria_fila(void)
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    if(f==NULL)
    {
        printf("Erro ao criar a fila!\n\n");
        exit(1);
    }
    f->inicio = f->fim = NULL;
    return f;
}


void insere_na_fila(Fila* f, Paciente* p)
{
    noFila* novo = (noFila*) malloc(sizeof(noFila));
    if(novo== NULL)
    {
        printf("Erro ao inserir elemento na fila!\n\n");
        exit(1);
    }

    novo->info = p;
    novo->prox = NULL;

    if(f->fim != NULL)
    {
        f->fim->prox = novo;

    }else{
        f->inicio = novo;

    }
    f->fim = novo;

}


int fila_vazia(Fila* f)
{
    return f->inicio==NULL;
}


void printa_fila(Fila* f)
{

    noFila* aux = f->inicio;
    int i = 1;
    if(!fila_vazia(f))
    {
        while(aux != NULL)
        {
            printf("-------%d Paciente da fila-------\n",i);
            printf("Nome: %s \t Tempo: %dmin\n\n", retorna_nome(aux->info), retorna_tempo(aux->info));
            aux = aux->prox;
            i++;
        }
    }
    else
    {
        printf("Nenhum paciente foi cadastrado na fila!\n\n");
    }
}


Paciente* retira_fila(Fila* f)
{
    noFila* aux;
    Paciente* p;
    if(!fila_vazia(f))
    {
        aux = f->inicio;
        p = aux->info;
        f->inicio = aux->prox;
        if(f->inicio == NULL)
        {
            f->fim = NULL;
        }
        free(aux);
        return p;
    }
    else
    {
        printf("Impossivel encaminhar paciente, fila vazia\n");
        return NULL;
    }
    return NULL;
}


void fila_libera(Fila* fi)
{
    noFila* auxINI = fi->inicio;
    noFila* auxANDA;
    while(auxINI != NULL)
    {
        auxANDA = auxINI->prox;
        free(auxINI);
        auxANDA = auxINI;
    }
    free(fi);
}
