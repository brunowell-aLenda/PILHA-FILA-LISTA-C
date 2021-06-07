#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDE


typedef struct pilha Pilha;//Estrutura da pilha em si
//Cont�m o campo para o primeiro da pilha(Listano*)

typedef struct paciente Paciente;//Estrutura do paciente
//Tem o campo do nome(Char) e o campo tempo(int)

typedef struct noli noLista;//Estrutura do n� da lista
//Cont�m o campo info(Paciente*), o campo ant(noLista*) tamb�m o campo prox(noLista*)

typedef struct lista Lista;//Estrutua da lista em si
//Possui o campo prim(noLista*) e o campo ult(noLista*)

Lista* cria_lista(void);//N�o recebe nenhum par�metro
//Cria uma estrutura do tipo Lista e depois seta o �nicio e o fim como NULL

void lstInsere(Lista* li, Paciente* p);//Recebe uma Lista*, um Paciente* e uma Pilha* como par�metro
//Cria um novo n� de lista e seta o campo novo->info como p(Paciente*)
//O campo novo->ant recebe o campo li->ult, ou seja, o anterior do novo n� aponta para o �ltimo da lista
//O campo novo->prox recebe NULL indicando que ele fica no final da lista
//Se o campo li->ult for valido o campo li->ult->prox recebe as informa��es do novo n�
//Se n�o quem recebe � o li->prim
//Por fim, o campo li->ult recebe o novo n�

int lista_vazia(Lista* li);//Recebe uma Lista* como par�metro
//Retorna o primeiro campo da lista como NULL

void lstPrint(Lista* li);//Recebe uma Lista* como par�metro
//Uma vari�vel aux recebe o campo li->prim
//Se a lista n�o estiver vazia, enquanto a vari�vel aux for diferente de NULL � printado o nome e o tempo do paciente
//Usando as fun��es retorna_nome e retorna_tempo, passando aux->info nas duas
//Logo em seguida aux � atualizada para aux->prox, assim n�o perdemos a refer�ncia original
//Caso a lista esteja vazia, uma mensagem aparece na tela informando que n�o ser� possivel imprimir a lista

void faz_relatorio(Lista* li, FILE* arq);//Recebe uma Lista* e um FILE* como par�metro
//Uma vari�vel auxiliar recebe a lista como um todo
//Enquanto o campo aux->prim for diferente de NULL
//� usado a fun��o fprintf para inserir o nome e o tempo do paciente de forma formatada no arquivo
//Usando as fun��es retorna_nome e retorna_tempo passando aux->prim->info nas duas
//Logo ap�s aux-> recebe aux->prim->prox
//No final uma mensagem � imprimida na tela dizendo que tudo deu certo

void displayPrimeiroMenorTempo(Lista* li, int tempoAUX);//Recebe uma Lista* e um int como par�metro
//� uma fun��o recurvisa que chama outra fun��o est�tica
//Que recebe um noLista* e um int como par�metro
//Se esse n� for igual a NULL � printada uma mensagem dizendo que nenhum paciente possui um tempo menor do que o informado
//Se n�o, se o retorno da chamada retorna_tempo passando o campo no->info for menor do que o informado
//� printado o nome do paciente e o tempo, chamando de novo a fun��o retorna_nome e a retorna_tempo
//Passando no->info nas duas
//Se n�o, a fun��o chama ela mesma, s� que agora passando o campo no->prox e o campo do tempo desejado
//Garantindo que a verifica��o ser� feita no pr�ximo n�

void lista_libera(Lista* li);//Recebe uma Lista* como par�metro
//S�o criadas duas vari�veis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo li->inicio
//Enquanto a vari�vel auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A vari�vel auxINI � liberada por meio da fun��o free
//A vari�vel auxANDA recebe a vari�vel auxANDA
//Ao sair do la�o a vari�vel auxANDA tamb�m � liberada por meio da fun��o free

#endif // LISTA_H_INCLUDED
