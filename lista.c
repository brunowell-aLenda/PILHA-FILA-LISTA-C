#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "paciente.h"


struct noli
{
    Paciente* info;
    noLista* ant;
    noLista* prox;
};


struct lista
{
    noLista* prim;
    noLista* ult;
};


Lista* cria_lista(void)
{
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if(l == NULL)
    {
        printf("Erro ao criar a lista!\n\n");
        exit(1);
    }

    l->prim = l->ult = NULL;
    return l;
}


void lstInsere(Lista* li, Paciente* p)
{
    noLista* novo = (noLista*) malloc(sizeof(noLista));
    if(novo == NULL)
    {
        printf("Erro ao inserir elemento na lista!\n");
        exit(1);
    }

    novo->info = p;

    novo->ant = li->ult;

    novo->prox = NULL;


    if(li->ult != NULL)
    {
        li->ult->prox = novo;
    }
    else
    {
        li->prim = novo;
    }
    li->ult = novo;
}


int lista_vazia(Lista* l)
{
    return l->prim == NULL;
}


void lstPrint(Lista* l)
{
    noLista* aux = l->prim;
    int i = 1;
    if(!lista_vazia(l))
    {
        while(aux != NULL)
        {
            printf("-------%d Paciente da lista-------\n",i);
            printf("Nome: %s \t Tempo: %dmin\n\n",retorna_nome(aux->info), retorna_tempo(aux->info));
            aux = aux->prox;
            i++;
        }
    }
    else
    {
        printf("Nenhum paciente foi cadastrado ainda!\n\n");
    }
}


void faz_relatorio(Lista* li, FILE* arq)
{
    int i = 1;
    Lista* aux = li;
    while(aux->prim != NULL)
    {
        fprintf(arq,"%d paciente atendido:\n",i);
        fprintf(arq,"Nome: %s\tTempo: %d\n\n",retorna_nome(aux->prim->info), retorna_tempo(aux->prim->info));
        aux->prim = aux->prim->prox;
        i++;
    }
    printf("Relatorio gerado.\n\n");
}


static void auxiliar_func(noLista* no, int t)
{

    if(no==NULL)
    {
        printf("Nenhum paciente possui o tempo menor que %dmin.\n",t);
        return;
    }
    else if(retorna_tempo(no->info) < t)
    {
        printf("%s %d",retorna_nome(no->info), retorna_tempo(no->info));
        return;
    }
    else
    {
        auxiliar_func(no->prox, t);
    }

}


void displayPrimeiroMenorTempo(Lista* l, int t)
{
    auxiliar_func(l->prim, t);
}


void lista_libera(Lista* li)
{
    noLista* auxINI = li->prim;
    noLista* auxANDA;
    while(auxINI != NULL)
    {
        auxANDA = auxINI->prox;
        free(auxINI);
        auxINI = auxANDA;
    }
    free(li);
}
