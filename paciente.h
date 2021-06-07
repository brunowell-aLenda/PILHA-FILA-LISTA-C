#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED


typedef struct paciente Paciente;//Estrutura do paciente
//Tem o campo do nome(Char) e o campo tempo(int)

Paciente *CriaPaciente(char* nome, int tempo);//Recebe um Char* e um int como parâmetro
//Cria um novo Paciente* e seta o campo do nome com o nome do parâmetro e o tempo com o tempo da parâmetro da mesma forma
//Logo em seguida o Paciente* preenchido é retornado

char* retorna_nome(Paciente* p);//Recebe um Paciente* como parâmetro
//Retorna o nome do pacienC:\Users\flavi\Desktop\Hospital\paciente.cte

int retorna_tempo(Paciente* p);//Recebe um Paciente* como parâmetro
//Retorna o nome do paciente

#endif // PACIENTE_H_INCLUDED
