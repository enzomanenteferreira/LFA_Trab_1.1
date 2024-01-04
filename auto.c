#include "auto.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//pre-requisito: ponteiro nao nulo para AUTOMATO, ponteiro nao nulo para um array de caracteres
//pos-requisito: adciona o automato desejado a variavel do tipo AUTOMATO
void adc_automato(char str[], AUTOMATO *aut){
    int count, temp, num;
    char line[MAX];

    FILE *arq; // arq auto.txt;
    arq = fopen(str, "rt");
    
    // no transitions;
    for(count=0; count<3; count++){
        fgets(line, MAX, arq);
        if(count==0){ // alphabet;
            temp=0;
            num=0;
            // while not end of line;
            while(line[temp]!='\n'){
                // printf("%c", line[temp]);
                // found {
                if(line[temp]=='{'){
                    // while not }
                    while(line[temp]!='}'){
                        // if is element, not ',';
                        if(isalnum(line[temp])){
                            aut->alpha[num] = line[temp];
                            // printf("%c ", aut->alpha[num]);
                            aut->tamanho.alphatam=num;
                            //printf("%d ", aut->tamanhos.alphatam=num);
                            num++;
                            temp++;
                        }
                        else temp++;
                    }
                }
                else temp++;
            }
            // printf("\n");
        }
        if(count==1){ // stages;
            temp=0;
            num=0;
            // while not end of line;
            while(line[temp]!='\n'){
                // printf("%c", line[temp]);
                // found {
                if(line[temp]=='{'){
                    // while not }
                    while(line[temp]!='}'){
                        // if is element, not ',';
                        if(isdigit(line[temp])){
                            aut->stages[num] = line[temp];
                            // printf("%c ", aut->stages[num]);
                            aut->tamanho.stagetam=num;
                            //printf("%d ", aut->tamanho.stagetam=num);
                            num++;
                            temp++;
                        }
                        else temp++;
                    }
                }
                else temp++;
            }
            // printf("\n");
        }
        if(count==2){ // finals;
            temp=0;
            num=0;
            // while not end of line;
            while(line[temp]!='\n'){
                // printf("%c", line[temp]);
                // found {
                if(line[temp]=='{'){
                    // while not }
                    while(line[temp]!='}'){
                        // if is element, not ',';
                        if(isdigit(line[temp])){
        
                            aut->finals[num] = line[temp];
                            // printf("%c ", aut->finals[num]);
                            aut->tamanho.finalstam=num;
                            //printf("%d ", aut->tamanhos.finalstam=num);
                            num++;
                            temp++;
                        }
                        else temp++;
                    }
                }
                else temp++;
            }
            // printf("\n");
        }
    }
    aut->finals_count = num;
    // fill transitions;
    num=0;
    temp=0;
    while(fgets(line, MAX, arq)){ // transitions;
        // is a valid line;
        if(line[0]=='('){
            sscanf(line, "%*c%*c%d%*c%c%*c%*c%*c%d", &aut->transition[num].current, &aut->transition[num].read, &aut->transition[num].next);
            // printf("%d %c %d\n", aut->transition[num].current, aut->transition[num].read, aut->transition[num].next);
            num++;
        }
    }
    aut->transition_count = num;
}

//pre-requisito: ponteiro nao nulo para AUTOMATO
//pos-requisito: remove o automato desejado da variavel do tipo AUTOMATO
void remove_automato(AUTOMATO *aut){
    int i;

    for(i=0; i<MAX; i++){
        aut->transition[i].current = 0;
        aut->transition[i].next = 0;
        aut->transition[i].read = '\0';
        aut->finals[i] = 0;
        aut->stages[i] = 0;
        aut->alpha[i] = '\0';
    }
    aut->transition_count = 0;
}

//pre-requisito: ponteiro nao nulo para AUTOMATO, ponteiro nao nulo para um array de caracteres
//pos-requisito: testa se a palavra pertence ao alfabeto
int testa_palavra(char str[], AUTOMATO *aut){
    int i, j;
    int count;
    int out;
    AUTOMATO *temp;
    temp = (AUTOMATO*)malloc(sizeof(AUTOMATO));

    // printf("%d\n", aut->transition_count);

    for(i=0; str[i]!=0; i++){
        out=0;
        if(i==0){ // alphabet confirm;
            for(j=0; j<(int)strlen(str); j++){
                // printf("%c", str[j]);
                if(strchr(aut->alpha, str[j])==0){
                    if((str[j]=='@')&&(aut->finals[0]  == '0')){
                        printf("[q0]@\n");
                        return 1;
                    }
                    printf("[q0]%s\n", str);
                    return 0; // letter not in alphabet;
                }
                // printf("%c", str[j]);
            }
            // printf("\n%s\n", str);
            temp->transition[i].current = 0;
            // printf("%d\n", temp->transition[i].current);
        }
        printf("[q%d]%s\n", temp->transition[i].current, str+i);
        for(count=0; count<aut->transition_count; count++){
            if(aut->transition[count].current==temp->transition[i].current && aut->transition[count].read==str[i]){
                temp->transition[i+1].current = aut->transition[count].next;
                out=1;
            }
        }
        if(!out) return 0;
    }
    printf("[q%d]\n", temp->transition[i].current);

    for(count=0; count<aut->finals_count; count++){
        if(temp->transition[i].current == (aut->finals[count]-48)) return 1;
    }

    return 0;
}

//pre-requisito: ponteiro nao nulo para AUTOMATO
//pos-requisito: testa se a variavel do tipo AUTOMATO esta vazio
int testa_vazio(AUTOMATO *aut){
    int i;

    for(i=0; i<MAX; i++){
        if(aut->transition[i].current != 0) return 0;
        if(aut->transition[i].next != 0) return 0;
        if(aut->transition[i].read != '\0') return 0;
        if(aut->finals[i] != 0) return 0;
        if(aut->stages[i] != 0) return 0;
        if(aut->alpha[i] != '\0') return 0;
    }
    if(aut->transition_count!=0) return 0;

    return 1;
}