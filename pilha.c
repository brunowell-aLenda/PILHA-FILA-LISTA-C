#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include <windows.h>
#include "paciente.h"

struct listano
{
    Paciente* info;
    Listano* prox;
};


struct pilha
{
    Listano* prim;
};


Pilha* cria_pilha(void)
{
    Pilha* p = (Pilha*) malloc( sizeof(Pilha));
    if(p ==NULL)
    {
        printf("Memoria cheia\n");
        exit(1);
    }
    p->prim = NULL;
    return p;
}


int pilha_vazia(Pilha* pi)
{
    return pi->prim == NULL;
}


void atendeFilaHospital(Pilha* pi, Fila* fi)
{
    Paciente* aux;
    aux = retira_fila(fi);
    int i = 1;
    if (aux != NULL)
    {
        Listano* novo = (Listano*) malloc(sizeof(Listano));
        if(novo==NULL)
        {
            printf("Memoria cheia\n");
            exit(1);
        }
        novo->info = aux;
        novo->prox = pi->prim;
        pi-> prim = novo;
        printf("%d paciente da fila encaminhado para o atendimento\n",i);
        i++;
    }
}


void printa_pilha(Pilha* pi)
{
    Listano* aux = pi->prim;
    int i = 1;
    if(!pilha_vazia(pi))
    {
        while(aux != NULL)
        {
            printf("-------%d Paciente da pilha-------\n",i);
            printf("Nome: %s \t Tempo: %dmin\n\n", retorna_nome(aux->info), retorna_tempo(aux->info));
            aux = aux->prox;
            i++;
        }
    }
    else
    {
        printf("Nenhum paciente foi cadastrado na pilha!\n");
    }
}


Paciente* retorna_topo(Pilha* pi)
{
    if(!pilha_vazia(pi))
    {
        Listano* aux = pi->prim;
        Paciente* p = aux->info;
        pi->prim = aux->prox;
        free(aux);
        return p;
    }
    else
    {
        return NULL;
    }
    return NULL;
}

void pilha_libera(Pilha* pi)
{
    Listano* auxINI = pi->prim;
    Listano* auxANDA;
    while(auxINI != NULL)
    {
        auxANDA = auxINI->prox;
        free(auxINI);
        auxINI = auxANDA;
    }
    free(pi);
}
