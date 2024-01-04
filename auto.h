#ifndef AUTO_H
#define AUTO_H

#define MAX 100

typedef struct{
    int alphatam;
    int stagetam;
    int finalstam;
}tam;

struct transit{
    int current;
    int next;
    char read;
};

typedef struct{
    char alpha[MAX];
    int stages[MAX];
    int finals[MAX];
    struct transit transition[MAX];
    int transition_count;
    int finals_count;
    tam tamanho;
} AUTOMATO;



//pre-requisito: ponteiro nao nulo para AUTOMATO, ponteiro nao nulo para um array de caracteres
//pos-requisito: adciona o automato desejado a variavel do tipo AUTOMATO
void adc_automato(char str[], AUTOMATO *aut);

//pre-requisito: ponteiro nao nulo para AUTOMATO
//pos-requisito: remove o automato desejado da variavel do tipo AUTOMATO
void remove_automato(AUTOMATO *aut);

//pre-requisito: ponteiro nao nulo para AUTOMATO, ponteiro nao nulo para um array de caracteres
//pos-requisito: testa se a palavra pertence ao alfabeto
int testa_palavra(char str[], AUTOMATO *aut);

//pre-requisito: ponteiro nao nulo para AUTOMATO
//pos-requisito: testa se a variavel do tipo AUTOMATO esta vazio
int testa_vazio(AUTOMATO *aut);



#endif // AUTO_H