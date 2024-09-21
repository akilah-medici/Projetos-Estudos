#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

int regra1(char*);
int regra2(char*);
int regra3(char*);
int regra4(char*);
int regra5(char*);
int regra6(char*);
int regra7(char*,int);
int regra8(char*);
int regra9(char*,int);
int regra10(char*);

int regra1(char *s){
    if(strlen(s)<5){//verifica se a string da senha tem 5 caracteres
        printf("A senha precisa conter 5 caracteres.\n");
        return 0;
    }
    else{
        printf("A senha contem 5 caracteres\n");
        return 1;
    }
}
int regra2(char *s){
    int contem = 1;
    for (int i = 0; i <strlen(s); i++){//verifica cada caractere da string pra ver se ha numeros
        if(!isdigit(s[i])){// se nao houver contem é falso
            contem = 0;
        }
        else{
            printf("A senha contem ao menos um numero\n");//se houver contem é verdadeiro
            return 1;// retorna verdadeiro se houver numero
        }
    }
    if(!contem){
        printf("a senha precisa conter ao menos um numero.\n");
        return 0;
    }
    
    
}
int regra3(char *s){
    int contem = 1;
    for (int i = 0; i <strlen(s); i++){//verifica cada caractere da string para ver se ha Uppercase
        if(!isupper(s[i])){
            contem = 0;
        }
        else{
            printf("A senha contem ao menos uma letra maiuscula\n");
            return 1;
        }
    }
    if(!contem){
        printf("a senha precisa conter ao menos uma letra maiuscula.\n");
        return 0;
    }
}
int regra4(char *s){
    int contem = 1;
    for (int i = 0; i <strlen(s); i++){
        if(isalnum(s[i])){// verifica se o caractere é um alfanumerico(letra e numero)
            contem = 0;
        }
        else{
            printf("A senha contem ao menos um caractere especial.\n");// se nao for alfanumerico é caractere especial
            return 1;
        }
    }
    if(!contem){
        printf("a senha precisa conter ao menos um caractere especial.\n");
        return 0;
    }   
}
int regra5(char *s){
    int soma = 0;
    char numero[20] = "";
    char t[2] = "";
    
    for (int i = 0; i < strlen(s); i++){
        if(isdigit(s[i])){//verifica se carcatere atual é digito
            t[0] = s[i];// quando for ele slava caractere em string concatena com outra e transfora a string em numero para adicionar a soma
            strcat(numero, t); 
            soma = soma+atoi(numero);
            numero[0] ='\0'; 
        }
    }
    if(strlen(numero)>0){
        soma = soma+atoi(numero);// ultima verificação para caso sobre algo em numero
    }

    if(soma!=25){
        printf("a senha deve conter a soma de seus numeros igual a 25.\n");
        return 0;
    }
    else if(soma==25){
        printf("A senha contem a soma de seus numeros igual a 25.\n");
        return 1;
    }   
}
int regra6(char *s){
    int contem = 0;
    char roman_un[] = {'I','V','X','L','C','D','M'};    
       for(int i = 0;i<strlen(s);i++){//verifica e compara as duas strings, se houver algo igual a roman_un ent a senha tem numero romano
        for(int j = 0;j<strlen(roman_un);j++){
                if(s[i]==roman_un[j]){
                    printf("A senha contem numeros romanos.\n");
                    return 1;
                }
                else{
                    contem = 0;
                }
            }
        }
    if(!contem){
        printf("a senha deve conter numeros romanos.\n");
        return 0;
    }
        
}
int regra7(char *s,int n){
    char numero[20] = "";
    char t[2] = "";
    int soma = 0;
    int contem  = 0;
    for (int i = 0; i < strlen(s); i++){
        if(isdigit(s[i])){
            t[0] = s[i];
            strcat(numero, t);//monta a string com um numero de 2 digitos
        }
        if(strlen(numero)==2){// se houver 2 numeros ele compara com o numero aleatorio fornecido na função
            if(atoi(numero)==n){
                contem = 1;
            }
            else{
                numero[0] = '\0';
            }
        }
    }
    //printf("%d",atoi(numero));
    if(contem){
        printf("A senha contem o numero sorteado de: %d.\n",n);
        return 1;
    }
    else{
        printf("a senha deve conter o numero sorteado de: %d.\n",n);
        return 0;
    }

}
int regra8(char *s){
    char numero[20] = "";
    char t[2] = "";
    int soma = 0;
    int contem  = 0;
    for (int i = 0; i < strlen(s); i++){
        if(isdigit(s[i])){
            t[0] = s[i];
            strcat(numero, t);
        }
        if(strlen(numero)==4){//salva um ano de 4 digitos 
            if((atoi(numero)%4) == 0){// checa se o ano é bissexto
                contem = 1;
            }
            else{
                numero[0] = '\0';
            }
        }
    }
    //printf("%d",atoi(numero));
    if(contem){
        printf("A senha contem um ano bissexto.\n");
        return 1;
    }
    else{
        printf("a senha deve conter um ano bissexto.\n");
        return 0;
    }

    
}
int regra9(char *s,int c){
    char *cores_hex[] = {
        "#FF0000",  // Vermelho
        "#00FF00",  // Verde
        "#0000FF",  // Azul
        "#FFFF00",  // Amarelo
        "#FF00FF",  // Magenta
        "#00FFFF",  // Ciano
        "#FFFFFF",  // Branco
        "#000000",  // Preto
        "#FF4500",  // Laranja
        "#800080"   // Roxo
    };
     char *cores[] = {
        "Vermelho",
        "Verde",
        "Azul",
        "Amarelo",
        "Magenta",
        "Ciano",
        "Branco",
        "Preto",
        "Laranja",
        "Roxo"
    };
    char cor[9] = "";
    char t[2] = "";
    int contem = 0;

    for (int i = 0; i < strlen(s); i++){
        if(s[i] == '#'){//so salva a cor hexa decimal a partir do #
            if(strlen(cor)<8){
                for (int j = 0; j < 7; j++){
                    t[0] = s[i+j];
                    strcat(cor,t);
                }       
            }
            break;
        }   
    }
    //printf("%s\n",cor);

    if((strcmp(cor,cores_hex[c]))==0){//usa o strcmp para comparar a string obtida com a da lista
        contem = 1;
    }
    
    if(contem){
        printf("A senha contem a cor hexadecimal: %s.\n",cores[c]);// imprime o nome da cor correspondente a cor hexa decimal
        return 1;
    }
    else{
        printf("a senha nao contem a cor hexadecimal: %s.\n",cores[c]);
        return 0;
    }
}
int regra10(char *s){
    if(strlen(s)==30){// verifica se a senha tem tamano igual a 30
        printf("A senha contem 30 caracteres\n");
        return 1;
    }
    else{
        
        printf("A senha precisa conter 30 caracteres.\n");
        return 0;
    }
}

void main(){
    srand(time(NULL));
    int sort,cor;
    sort = rand() % 89 + 11;
    cor =  rand() % 8;
    char senha[40] = "";
    int ganhou = 0;

    while(!ganhou){
        int cond = 0;
        printf("Senha: ");
        scanf("%s",senha);
        if(regra1(senha)){
            cond+=1;// se a regra for satisfeita soma em condição 
            if(regra2(senha)){
                cond+=1;
                if(regra3(senha)){
                    cond+=1;
                    if(regra4(senha)){
                        cond+=1;
                        if(regra5(senha)){
                            cond+=1;
                            if(regra6(senha)){
                                cond+=1;
                                if(regra7(senha,sort)){
                                    cond+=1;
                                    if(regra8(senha)){
                                        cond+=1;
                                        if(regra9(senha,cor)){
                                            cond+=1;
                                            if(regra10(senha)){
                                                cond+=1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(cond == 10){//se todas a regras forem satisfeitas condição igual a 10 e ganha o jogo
            ganhou = 1;
        }
        printf("Senha atual: %s\n",senha);
    }
    printf("Parabens! agora voce possui a senha mais poderosa em territorio nacional!.\n");
}
/*
Regras a serem implementadas:
1) Your password must be at least 5 characters.
2) Your password must include a number.
3) Your password must include an uppercase letter.
4) Your password must include a special character.
5) The digits in your password must add up to 25.
6) Your password must include a roman numeral.
7) Incluir número sorteado (11..99)
8) a senha precisa conter um ano bissexto
9) a senha precisa conter o nome de um mes
10) a senha precisa conter 30 caracteres
*/