#include "auto.c"

int main(){
    AUTOMATO tmp;
    char str[MAX];
    char word[MAX];
    int choice;

    while(1){
        printf("Escolha a opção desejada: \n");
        printf("(1) Adicionar automato: \n");
        printf("(2) Remover automato: \n");
        printf("(3) Testar palavra: \n");
        printf("(4) Fechar programa: \n");

        printf("opção:");
        scanf("%d", &choice);
        scanf("%*c");

        switch(choice){
        case 1:
            system("cls");
            printf("Escreva o nome arquivo do automato(.txt): \n");
            scanf("%[^\n]%*c", str);
            adc_automato(str, &tmp);

            break;

        case 2:
            system("cls");
            if(!testa_vazio(&tmp)){
                remove_automato(&tmp);
                printf("AUTOMATO REMOVIDO\n");
            }
            else printf("AUTOMATO JA REMOVIDO OU INEXISTENTE\n");

            break;

        case 3:
            system("cls");
            printf("Escreva a palavra que deseja testar: \n");
            scanf("%[^\n]%*c", word);
            if(testa_palavra(word, &tmp)){ 
                
                printf("ACEITA\n");}
            else printf("REJEITA\n");

            break;
        
        case 4:
            system("cls");
            return 1;
            break;
        }
    }

    return 0;
}