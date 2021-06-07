#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED


typedef struct fila Fila;//Estrutura do n� da fila
//Cont�m o campo da informa��o(Paciente*) e tamb�m o campo para o pr�ximo(noFila*)

typedef struct listano Listano;//Estrutura do n� da lista
//Cont�m o campo da informa��o(Paciente*) e tamb�m o campo para o pr�ximo(Listano*)

typedef struct pilha Pilha;//Estrutura da pilha em si
//Cont�m o campo para o primeiro da pilha(Listano*)

Pilha* cria_pilha(void);//N�o recebe nenhum par�metro
//Cria uma estrutura do tipo Pilha e depois seta o campo prim como NULL

int pilha_vazia(Pilha* pi);//Recebe uma estrutura do tipo Pilha* como par�metro
//Retorna o campo pi->prim como NULL

void atendeFilaHospital(Pilha* pi, Fila* fi);//Recebe uma Pilha* e uma Fila* como par�metro
//Um Paciente* aux recebe o retorno da fun��o retira_fila
//E se esse aux for diferente de NULL um novo n� de lista � criado e no campo da informa��o de novo n� e setado aux
//O campo prox do novo � setado como pi->prim(Primeiro elemento da pilha)
//E o campo pi->prim recebe o novo n�
//Por fim uma mensagem � printada informando que tudo deu certo
//Caso aux seja == NULL a fun��o n�o faz nada

void printa_pilha(Pilha* pi);//Recebe uma Pilha* como um par�metro
//Uma vari�vel auxiliar recebe o campo pi->prim
//Se a pilha n�o estiver vazia, enquanto a vari�vel auxiliar n�o for NULL
//� printado o nome e o tempo do paciente por meio das fun��es retorna_nome e retorna_tempo
//Passando o campo pi->prim nas duas
//Logo em seguida a vari�vel aux � atualizada para aux->prox, assim pode "andar" na pilha e n�o perdemos a refer�ncia original

Paciente* retorna_topo(Pilha* pi);//Recebe uma Pilha* como par�metro
//Se a pilha n�o estiver vazia uma vari�vel auxiliar recebe o campo pi->prim(topo)
//Um Paciente* recebe o campo aux->info(informa��es do paciente que est� no topo)
//O campo pi->prim � atualizado para aux->prox, ou seja, o topo � o pr�ximo da pilha agora
//A vari�vel aux � liberada e o Paciente*(informa��o do topo) � retornado
//Caso a pilha for vazia � retornado NULL

void pilha_libera(Pilha* pi);//Recebe uma Pilha* como par�metro
//S�o criadas duas vari�veis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo pi->prim
//Enquanto a vari�vel auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A vari�vel auxINI � liberada por meio da fun��o free
//A vari�vel auxANDA recebe a vari�vel auxANDA
//Ao sair do la�o a vari�vel auxANDA tamb�m � liberada por meio da fun��o free

#endif // PILHA_H_INCLUDED
