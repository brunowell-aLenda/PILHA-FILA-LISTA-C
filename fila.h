#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct listano Listano;//Estrutura do n� da lista
//Cont�m o campo da informa��o(Paciente*) e tamb�m o campo para o pr�ximo(Listano*)

typedef struct nofi noFila;//Estrutura do n� da fila
//Cont�m o campo da informa��o(Paciente*) e tamb�m o campo para o pr�ximo(noFila*)

typedef struct fila Fila;//Estrutura da fila em si
//Cont�m o campo para o in�cio(noFila*) e o campo para o pr�ximo(noFila*)

Fila* cria_fila(void);//N�o recebe nenhum par�metro
//Cria uma estrutura do tipo Fila e depois seta o �nicio e o fim como NULL

int fila_vazia(Fila* f);//Recebe uma Fila* como par�metro
//Retorna o in�cio da fila igual a NULL

void insere_na_fila(Fila* f, Paciente* p);//Recebe uma Fila* e um Paciente* como par�metro
//Cria um novo n� de fila e seta o campo info como o paciente e o campo prox como NULL
//Se o campo f->fim for diferente de NULL campo f->fim->prox recebe o novo n�
//Se n�o o campo f->inicio � quem recebe
//Por fim o campo f->fim � atualizado para o novo n�

void printa_fila(Fila* f);//Recebe uma Fila* como um par�metro
//Uma vari�vel auxiliar recebe o campo f->inicio
//Se a fila n�o estiver vazia, enquanto a vari�vel auxiliar n�o for NULL
//� printado o nome e o tempo do paciente por meio das fun��es retorna_nome e retorna_tempo
//Passando o campo aux->info nas duas
//Logo em seguida a vari�vel aux � atualizada para aux->prox, assim pode "andar" na fila e n�o perdemos a refer�ncia original

Paciente* retira_fila(Fila* f);//Recebe uma Fila* como par�metro
//Se a fila n�o estiver vazia um noFila* aux recebe o inicio da fila
//E um Paciente* p recebe o campo da informa��o contida em aux->info
//O �nicio da fila (f->inicio) recebe o campo (aux->prox)
//Depois h� uma verifica��o, se o in�cio da fila for vazio o campo f->fim recebe NULL tamb�m
//Logo em seguida a vari�vel aux � liberada e o Paciente* p � retornado
//Se a fila estiver vazia � printada uma mensagem informando isso e o retorno � NULL

void fila_libera(Fila* fi);//Recebe uma Fila* como par�metro
//S�o criadas duas vari�veis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo fi->inicio
//Enquanto a vari�vel auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A vari�vel auxINI � liberada por meio da fun��o free
//A vari�vel auxANDA recebe a vari�vel auxANDA
//Ao sair do la�o a vari�vel auxANDA tamb�m � liberada por meio da fun��o free

#endif // FILA_H_INCLUDED
