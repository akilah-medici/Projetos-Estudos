#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int mostra_vidas(int);
int verifica_palavra(char*,char*,char*,char*);
void limpa_tela();
void monta_palavra(char*,char*,char*);

int mostra_vidas(int v){//mostra as vidas imprimindo o boneco
    if(v == 0){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=     |---|     \n");
        printf("=     | | |     \n");
        printf("=       |       \n");
        printf("=      |-|      \n");
        printf("=      | |      \n");
        printf("=      | |      \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
    else if(v == 1){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=     |---|     \n");
        printf("=     | | |     \n");
        printf("=       |       \n");
        printf("=      |-|      \n");
        printf("=        |      \n");
        printf("=        |      \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
    else if(v == 2){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=     |---|     \n");
        printf("=     | | |     \n");
        printf("=       |       \n");
        printf("=      |-|      \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
    else if(v == 3){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=     |---|     \n");
        printf("=       | |     \n");
        printf("=       |       \n");
        printf("=      |-|      \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
    else if(v == 4){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=     |---|     \n");
        printf("=       |       \n");
        printf("=       |       \n");
        printf("=      |-|      \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
    else if(v == 5){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=      ( )      \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
      else if(v == 6){
        printf("=========       \n");
        printf("=       +       \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("=               \n");
        printf("~~~~~~~~~~      \n");
        printf("~~~~~~~~~~~~~   \n");
        printf("~~~~~~~~~~~~~~~ \n");
        printf("~~~~~~~~~~~~~~~~\n");
    }
}

int verifica_palavra(char *pl1,char *pl2,char *lc,char *le){
    int index = 0;
    int encontrado  = 0;
    int igual = 0;
    char c[50] = {0};
    for (int i = 0; i < strlen(pl1); i++){//verifica se as letras de pl2 chao iguais as letras da palavra aleatoria
        for (int j = 0; j < strlen(pl2); j++){
            if(toupper(pl1[i])==toupper(pl2[j])){
                c[index++] = pl2[j];
                c[index+1] ='\0' ;
                encontrado = 1;//true se encontra letras certas
            }
        }
    }
    if(!encontrado){//verifica se a letra de pl2 é igual a de pl1 pelo encontrado se nao retotna 1
        strcat(le,pl2);
        return 0;
    }
    for (int i = 0; i< strlen(lc); i++){//verifica se a letra de pl1 ja existe na lista C, se existir nao adiciona
        for(int j = 0;j<strlen(c);j++){ 
            igual = 0;
            if(lc[i]!=c[j]){
                igual = 0;
                //printf("adicionado\n");    
            }
            else{
                //printf("não adicionado\n");
                igual = 1;
                return 1;
            }
        }
    }
    if(!igual){//se pl2 nao é igual a alguma letra em letras certas adiciona essa letra a letras certas;
        strcat(lc,c);
    }
    return 1;
}

void limpa_tela(){
    for (int i = 0; i < 100; i++)
    {
        printf("\n");
    }
    
}

void monta_palavra(char*l1,char *l2,char*c){
    for (int i = 0; i <=strlen(l1); i++){
        for(int j = 0;j<=strlen(l2);j++){
            if(toupper(l1[i])==toupper(l2[j])){
                c[i] = toupper(l2[j]);//verifica se as letras correspondem com a respectiva posição da palavra chave, se sim é adicionado na respectiva posição do vetor
            }
        }
    }
    printf("%s\n",c);    
} 

int main()
{
    srand(time(NULL));
    char letras_certas[50] = {0};
    char letras_erradas[50] = {0};
    char *personagens[] = {"scoobydoo", "jackiechan", "finn", "bobesponja", "jarry", "tom", "pernalonga", "picapau", "popeye", "minnie", "mickey", "mulan", "peterpan", "dumbo", "tartaruganinja", "pikachu", "snoopy", "pluto", "patolino", "batman"};
    char *frutas[] = {"maca", "banana", "uva", "pera", "abacaxi", "ameixa", "jabuticaba", "manga", "melancia", "morango", "laranja", "kiwi", "goiaba", "limao", "cereja", "pessego", "tangerina", "melao", "framboesa", "caju"};
    char e[50];
    int vida = 6;
    int pos = rand()%21;
    int op;
    char palavra[50];

    while(1){//menu e definição da palavra
        printf("===============\n");
        printf(" Jogo da forca \n");
        printf(" 0 - Sair\n");
        printf(" 1 - Tema: Personagens de desenho animado\n");
        printf(" 2 - Tema: Frutas\n");
        printf("===============\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);
        
        if(op ==1){
            strcpy(palavra,personagens[pos]);//strcpy copia uma string para outra
            break;
        }
        else if(op ==2){
            strcpy(palavra,frutas[pos]);
            break;
        }
        else if(op!=0&&op!=1&&op!=2){
            printf("\n");
            printf("Digite uma opção válida!\n");
            printf("\n");
        }
        else{
            return 0;
        }
    }

    char s[strlen(palavra) + 1];//montagem da palavra em branco  
    for (int i = 0; i < strlen(palavra)+1; i++) {
        s[i] = '_';
       
    }
    s[strlen(palavra)] = '\0'; 

    while(1){//codigo principal
        
        printf("Digite uma letra: ");
        scanf("%s", e);

        limpa_tela();
        for (int i = 0; e[i]; i++){//transforma a string em letras meiusculas
            e[i] = toupper(e[i]);
        }

        int verif = (verifica_palavra(palavra,e,letras_certas,letras_erradas));
        
        if(!verif){
            vida--;
        }
       
        printf("Letras certas: %s\n",letras_certas);
        printf("Letras erradas: %s\n",letras_erradas);
        printf("Vidas= %d\n",vida);
        monta_palavra(palavra,letras_certas,s);
        
        mostra_vidas(vida);

        //printf("%ld\n",strlen(letras_certas));
        //printf("%ld\n",strlen(palavra));
        
        if(vida == 0){
            printf("Perdeu! A palavra era: %s\n", palavra);
            break;
        }
        else if(strlen(letras_certas) == strlen(palavra)){
            printf("Ganhou! A palavra era: %s\n", palavra);
            break;
        }
    }
          
    return 0;
}
