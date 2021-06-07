#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "fila.h"
#include "paciente.h"


int main()
{
    char nome[41];
    int tempo;
    int controlMENU;
    int controlCASE1, controlCASE2, controlCASE3;
    int tentativas = 0;

    Fila* f = cria_fila();

    Lista* li = cria_lista();

    Pilha* pi = cria_pilha();

    system("title HOSPITAL - UFERSA");
    do
    {
        int aux;
        printf("================= MENU ===================\n");
        printf("|               1- Paciente              |\n");
        printf("|-------- Cadastrar novo paciente -------|\n");
        printf("|--- Visualizar pacientes cadastrados ---|\n");
        puts("|                                        |");
        printf("|             2- Atendimento             |\n");
        printf("|- Encaminhar paciente para atendimento -|\n");
        printf("|- Mostrar pacientes a serem atendidos --|\n");
        printf("|--- Atender paciente com maior tempo ---|\n");
        printf("|---- Pesquisar paciente pelo tempo -----|\n");
        puts("|                                        |");
        printf("|              3- Relatorio              |\n");
        printf("|------ Mostar pacientes atendidos ------|\n");
        printf("|------------ Gerar relatorio -----------|\n");
        puts("|                                        |");
        printf("|                 4- Sair                |\n");
        printf("==========================================\n");

        printf("Digite sua opcao: ");
        scanf("%d", &controlMENU);
        system("cls");

        setbuf(stdin, NULL);

        switch(controlMENU)
        {
        case 1:
            do
            {
                printf("[1] - Cadastar novo paciente\n[2] - Visualizar pacientes cadastrados\n[3] - Voltar para o menu\n");
                printf("Digite sua opcao: ");
                scanf("%d", &aux);
                system("cls");
                if(aux==1)
                {

                    system("cls");
                    printf("---- Cadastro De Paciente ----\n\n");

                    printf("Insira o nome do paciente: ");

                    fflush(stdin);

                    scanf("%40[^\n]s", nome);

                    printf("Insira o tempo de exame: ");

                    fflush(stdin);
                    scanf("%d", &tempo);

                    Paciente* p = CriaPaciente(nome, tempo);

                    insere_na_fila(f, p);

                    printf("\n--- O PACIENTE FOI CADASTRADO ---\n");

                    Sleep(3000);
                    system("cls");

                    printf("[1] - Voltar para as opcoes\n[2] - Voltar para o menu\n");
                    printf("Digite sua opcao: ");
                    scanf("%d",&controlCASE1);
                    if(controlCASE1 == 2)
                    {
                        aux = 3;
                    }
                    system("cls");
                }
                if(aux==2)
                {
                    printa_fila(f);

                    printf("[1] - Voltar para as opcoes\n[2] - Voltar para o menu\n");
                    printf("Digite sua opcao: ");
                    scanf("%d",&controlCASE1);
                    if(controlCASE1 == 2)
                    {
                        aux = 3;
                    }
                    system("cls");
                }
                if(aux == 3){
                    break;
                }
            }
            while((controlCASE1 != 2 && controlCASE1 != 1) || aux != 3);
            system("cls");
            break;


        case 2:
            do
            {
                printf("[1] - Encaminhar paciente para o atendimento\n[2] - Mostrar pacientes a serem atendidos\n");
                printf("[3] - Atender paciente com maior tempo\n[4] - Pesquisar paciente pelo menor tempo\n[5] - Voltar para o menu\n");
                printf("Digite sua opcao: ");
                scanf("%d",&controlCASE2);
                if(controlCASE2 == 1)
                {
                    int i = 1;
                    atendeFilaHospital(pi, f);
                    Sleep(3000);
                    i++;
                }

                else if(controlCASE2 == 2)
                {
                    printa_pilha(pi);
                    Sleep(3000);

                }

                else if(controlCASE2 == 3 )
                {

                    if(!pilha_vazia(pi))
                    {
                        Paciente* p = retorna_topo(pi);

                        lstInsere(li, p);

                        printf("\nPaciente Atendido: %s %dmin\n",retorna_nome(p), retorna_tempo(p));

                        Sleep(3000);
                    }
                    else
                    {
                        printf("Impossivel atender paciente, pilha vazia\n");
                        Sleep(3000);
                    }
                    puts("");
                }
                else if(controlCASE2 == 4)
                {
                    int tempoAUX;
                    printf("Informe o tempo desejado: ");
                    scanf("%d",&tempoAUX);
                    displayPrimeiroMenorTempo(li, tempoAUX);
                    Sleep(3000);
                }
                system("cls");
            }
            while(controlCASE2 != 5);
            break;


        case 3:
            do
            {
                printf("[1] - Mostrar pacientes atendidos\n[2] - Voltar ao menu\n");
                printf("Digite sua opcao: ");
                scanf("%d", &controlCASE3);

                if(controlCASE3==1)
                {
                    system("cls");
                    printf("---- Lista de pacientes atendidos ----\n\n");
                    lstPrint(li);

                    printf("[1] - Gerar relatorio\n[2] - Voltar ao menu\n");
                    printf("Digite sua opcao: ");
                    scanf("%d",&controlCASE3);
                    if(controlCASE3 == 1)
                    {
                        if(!lista_vazia(li))
                        {
                            FILE* arq = fopen("RELATORIO HOSPITAL - UFERSA.txt","wt");
                            if(arq == NULL)
                            {
                                printf("Erro ao imprimir relatorio.\n");
                            }

                            faz_relatorio(li, arq);
                            Sleep(3000);
                            fclose(arq);
                        }
                        else
                        {
                            printf("Impossivel gerar relatorio, lista vazia.\n");
                            Sleep(3000);
                        }
                    }
                    else
                    {
                        system("cls");
                    }

                }
                else
                {
                    system("cls");
                    break;
                }
                system("cls");
            }
            while(controlCASE3 != 2);
            break;


        case 4:
            printf("OBRIGADO POR FAZER PARTE DO NOSSO HOSPITAL - UFERSA :)\n");
            printf("Pressione qualquer tecla...\n");
            fila_libera(f);
            pilha_libera(pi);
            lista_libera(li);
            break;
        default:
            printf("Opcao invalida, tente novamente\n");
            Sleep(1000);
            system("cls");
            tentativas++;
            if(tentativas == 7)
            {
                printf("Infelizmente voce chegou no limite maximo de tentativas incorretas.\n");
                Sleep(2500);
                exit(1);
            }
        }
    }
    while(controlMENU != 4);

    return 0;
}
