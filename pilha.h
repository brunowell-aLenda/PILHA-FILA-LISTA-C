#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED


typedef struct fila Fila;//Estrutura do nó da fila
//Contém o campo da informação(Paciente*) e também o campo para o próximo(noFila*)

typedef struct listano Listano;//Estrutura do nó da lista
//Contém o campo da informação(Paciente*) e também o campo para o próximo(Listano*)

typedef struct pilha Pilha;//Estrutura da pilha em si
//Contém o campo para o primeiro da pilha(Listano*)

Pilha* cria_pilha(void);//Não recebe nenhum parâmetro
//Cria uma estrutura do tipo Pilha e depois seta o campo prim como NULL

int pilha_vazia(Pilha* pi);//Recebe uma estrutura do tipo Pilha* como parâmetro
//Retorna o campo pi->prim como NULL

void atendeFilaHospital(Pilha* pi, Fila* fi);//Recebe uma Pilha* e uma Fila* como parâmetro
//Um Paciente* aux recebe o retorno da função retira_fila
//E se esse aux for diferente de NULL um novo nó de lista é criado e no campo da informação de novo nó e setado aux
//O campo prox do novo é setado como pi->prim(Primeiro elemento da pilha)
//E o campo pi->prim recebe o novo nó
//Por fim uma mensagem é printada informando que tudo deu certo
//Caso aux seja == NULL a função não faz nada

void printa_pilha(Pilha* pi);//Recebe uma Pilha* como um parâmetro
//Uma variável auxiliar recebe o campo pi->prim
//Se a pilha não estiver vazia, enquanto a variável auxiliar não for NULL
//É printado o nome e o tempo do paciente por meio das funções retorna_nome e retorna_tempo
//Passando o campo pi->prim nas duas
//Logo em seguida a variável aux é atualizada para aux->prox, assim pode "andar" na pilha e não perdemos a referência original

Paciente* retorna_topo(Pilha* pi);//Recebe uma Pilha* como parâmetro
//Se a pilha não estiver vazia uma variável auxiliar recebe o campo pi->prim(topo)
//Um Paciente* recebe o campo aux->info(informações do paciente que está no topo)
//O campo pi->prim é atualizado para aux->prox, ou seja, o topo é o próximo da pilha agora
//A variável aux é liberada e o Paciente*(informação do topo) é retornado
//Caso a pilha for vazia é retornado NULL

void pilha_libera(Pilha* pi);//Recebe uma Pilha* como parâmetro
//São criadas duas variáveis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo pi->prim
//Enquanto a variável auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A variável auxINI é liberada por meio da função free
//A variável auxANDA recebe a variável auxANDA
//Ao sair do laço a variável auxANDA também é liberada por meio da função free

#endif // PILHA_H_INCLUDED
