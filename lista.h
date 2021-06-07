#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDE


typedef struct pilha Pilha;//Estrutura da pilha em si
//Contém o campo para o primeiro da pilha(Listano*)

typedef struct paciente Paciente;//Estrutura do paciente
//Tem o campo do nome(Char) e o campo tempo(int)

typedef struct noli noLista;//Estrutura do nó da lista
//Contém o campo info(Paciente*), o campo ant(noLista*) também o campo prox(noLista*)

typedef struct lista Lista;//Estrutua da lista em si
//Possui o campo prim(noLista*) e o campo ult(noLista*)

Lista* cria_lista(void);//Não recebe nenhum parâmetro
//Cria uma estrutura do tipo Lista e depois seta o ínicio e o fim como NULL

void lstInsere(Lista* li, Paciente* p);//Recebe uma Lista*, um Paciente* e uma Pilha* como parâmetro
//Cria um novo nó de lista e seta o campo novo->info como p(Paciente*)
//O campo novo->ant recebe o campo li->ult, ou seja, o anterior do novo nó aponta para o último da lista
//O campo novo->prox recebe NULL indicando que ele fica no final da lista
//Se o campo li->ult for valido o campo li->ult->prox recebe as informações do novo nó
//Se não quem recebe é o li->prim
//Por fim, o campo li->ult recebe o novo nó

int lista_vazia(Lista* li);//Recebe uma Lista* como parâmetro
//Retorna o primeiro campo da lista como NULL

void lstPrint(Lista* li);//Recebe uma Lista* como parâmetro
//Uma variável aux recebe o campo li->prim
//Se a lista não estiver vazia, enquanto a variável aux for diferente de NULL é printado o nome e o tempo do paciente
//Usando as funções retorna_nome e retorna_tempo, passando aux->info nas duas
//Logo em seguida aux é atualizada para aux->prox, assim não perdemos a referência original
//Caso a lista esteja vazia, uma mensagem aparece na tela informando que não será possivel imprimir a lista

void faz_relatorio(Lista* li, FILE* arq);//Recebe uma Lista* e um FILE* como parâmetro
//Uma variável auxiliar recebe a lista como um todo
//Enquanto o campo aux->prim for diferente de NULL
//É usado a função fprintf para inserir o nome e o tempo do paciente de forma formatada no arquivo
//Usando as funções retorna_nome e retorna_tempo passando aux->prim->info nas duas
//Logo após aux-> recebe aux->prim->prox
//No final uma mensagem é imprimida na tela dizendo que tudo deu certo

void displayPrimeiroMenorTempo(Lista* li, int tempoAUX);//Recebe uma Lista* e um int como parâmetro
//É uma função recurvisa que chama outra função estática
//Que recebe um noLista* e um int como parâmetro
//Se esse nó for igual a NULL é printada uma mensagem dizendo que nenhum paciente possui um tempo menor do que o informado
//Se não, se o retorno da chamada retorna_tempo passando o campo no->info for menor do que o informado
//É printado o nome do paciente e o tempo, chamando de novo a função retorna_nome e a retorna_tempo
//Passando no->info nas duas
//Se não, a função chama ela mesma, só que agora passando o campo no->prox e o campo do tempo desejado
//Garantindo que a verificação será feita no próximo nó

void lista_libera(Lista* li);//Recebe uma Lista* como parâmetro
//São criadas duas variáveis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo li->inicio
//Enquanto a variável auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A variável auxINI é liberada por meio da função free
//A variável auxANDA recebe a variável auxANDA
//Ao sair do laço a variável auxANDA também é liberada por meio da função free

#endif // LISTA_H_INCLUDED
