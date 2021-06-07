#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"
#include "fila.h"
#include "pilha.h"
#include "lista.h"

struct paciente
{
    char nome[40];
    int tempo;
};


Paciente *CriaPaciente(char *nome, int tempo)
{
    Paciente *p = (Paciente*) malloc(sizeof(Paciente));

    if(p == NULL)
    {
        printf("Memoria cheia\n");
        exit(1);
    }

    strcpy(p->nome,nome);
    p->tempo = tempo;

    return p;
}


char* retorna_nome(Paciente* p)
{
    return p->nome;
}


int retorna_tempo(Paciente* p)
{
    return p->tempo;
}
