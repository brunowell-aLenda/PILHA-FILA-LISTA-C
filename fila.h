#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct listano Listano;//Estrutura do nó da lista
//Contém o campo da informação(Paciente*) e também o campo para o próximo(Listano*)

typedef struct nofi noFila;//Estrutura do nó da fila
//Contém o campo da informação(Paciente*) e também o campo para o próximo(noFila*)

typedef struct fila Fila;//Estrutura da fila em si
//Contém o campo para o início(noFila*) e o campo para o próximo(noFila*)

Fila* cria_fila(void);//Não recebe nenhum parâmetro
//Cria uma estrutura do tipo Fila e depois seta o ínicio e o fim como NULL

int fila_vazia(Fila* f);//Recebe uma Fila* como parâmetro
//Retorna o início da fila igual a NULL

void insere_na_fila(Fila* f, Paciente* p);//Recebe uma Fila* e um Paciente* como parâmetro
//Cria um novo nó de fila e seta o campo info como o paciente e o campo prox como NULL
//Se o campo f->fim for diferente de NULL campo f->fim->prox recebe o novo nó
//Se não o campo f->inicio é quem recebe
//Por fim o campo f->fim é atualizado para o novo nó

void printa_fila(Fila* f);//Recebe uma Fila* como um parâmetro
//Uma variável auxiliar recebe o campo f->inicio
//Se a fila não estiver vazia, enquanto a variável auxiliar não for NULL
//É printado o nome e o tempo do paciente por meio das funções retorna_nome e retorna_tempo
//Passando o campo aux->info nas duas
//Logo em seguida a variável aux é atualizada para aux->prox, assim pode "andar" na fila e não perdemos a referência original

Paciente* retira_fila(Fila* f);//Recebe uma Fila* como parâmetro
//Se a fila não estiver vazia um noFila* aux recebe o inicio da fila
//E um Paciente* p recebe o campo da informação contida em aux->info
//O ínicio da fila (f->inicio) recebe o campo (aux->prox)
//Depois há uma verificação, se o início da fila for vazio o campo f->fim recebe NULL também
//Logo em seguida a variável aux é liberada e o Paciente* p é retornado
//Se a fila estiver vazia é printada uma mensagem informando isso e o retorno é NULL

void fila_libera(Fila* fi);//Recebe uma Fila* como parâmetro
//São criadas duas variáveis auxiliares,-auxINI & auxANDA- uma-auxINI- recebendo o campo fi->inicio
//Enquanto a variável auxINI for diferente de NULL auxANDA recebe o campo auxINI->prox
//A variável auxINI é liberada por meio da função free
//A variável auxANDA recebe a variável auxANDA
//Ao sair do laço a variável auxANDA também é liberada por meio da função free

#endif // FILA_H_INCLUDED
