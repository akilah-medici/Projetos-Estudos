#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#define MAX_COL 4
#define MAX_LIN 4
void print_m(int [][MAX_COL]);
int move(char,int [][MAX_COL]);
int verifica_m_baixo(int [][MAX_COL]);
int verifica_m_cima(int [][MAX_COL]);
int verifica_m_dir(int [][MAX_COL]);
int verifica_m_esq(int [][MAX_COL]);
int verifica_vitoria(int [][MAX_COL]);
int verifica_derrota(int [][MAX_COL]);
int append_num_matriz(int [][MAX_COL]);
int soma_cima(int [][MAX_COL]);
int soma_baixo(int [][MAX_COL]);
int soma_esquerda(int [][MAX_COL]);
int soma_direita(int [][MAX_COL]);

void print_m(int m[][MAX_COL]){
    for (int i = 0; i < MAX_LIN; i++){
        for (int j = 0; j < MAX_COL; j++){
            printf(" %*d ",2,m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int verifica_m_baixo(int m[][MAX_COL]){
    for(int i = 0; i<MAX_LIN-1; i++){
        for(int j = 0;j <=MAX_COL-1 ;j++){
            if(m[i][j]!=0){// verifica se ha um elemento nao nulo, se houver verifica se o proximo elemento é zero, se for retorna um
                if(m[i+1][j]==0){
                    return 1;
                }
            }
        }
    }
    return 0;
    
}
int verifica_m_cima(int m[][MAX_COL]){
    for(int i = MAX_LIN-1; i>0; i--){
        for(int j = MAX_COL-1; j>=0; j--){
            if(m[i][j]!=0){// verifica se ha um elemento nao nulo, se houver verifica se o proximo elemento é zero, se for retorna um
                if(m[i-1][j]==0){
                    return 1;
                }
            }
        }
    }
    return 0; 
}
int verifica_m_dir(int m[][MAX_COL]){
    for(int i = 0; i<=MAX_LIN-1; i++){
        for(int j = 0;j <MAX_COL-1; j++){
            if(m[i][j] != 0) {// verifica se ha um elemento nao nulo, se houver verifica se o proximo elemento é zero, se for retorna um
                if(m[i][j+1] == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int verifica_m_esq(int m[][MAX_COL]){
    for(int i = MAX_LIN - 1; i >= 0; i--) {
        for(int j = MAX_COL - 1; j > 0; j--) {
            if(m[i][j] != 0) {// verifica se ha um elemento nao nulo, se houver verifica se o proximo elemento é zero, se for retorna um
                if(m[i][j-1] == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int soma_cima(int m[][MAX_COL]){
    int pont = 0;
    for(int k = 0; k<=MAX_COL-1; k++){// ele precisa somar cada elemento da linha L com seus respectivos elementos da linha L-1
        for(int l = 0; l<=MAX_LIN-1; l++){// na proxima iteração ele ira para linha L-1 e ira somar com a L-2
            if(m[k][l]!=0){
                if(m[k][l]==m[k-1][l]&&k-1>=0){                                                
                    int s = m[k][l]+m[k-1][l];
                    m[k][l] = s;
                    m[k-1][l] = 0;
                    pont = pont+s;
                }
            }
        }                             
    }
    return pont;                 
}
int soma_baixo(int m[][MAX_COL]){
    int pont = 0;                 
    for(int k = MAX_COL - 1; k >= 0; k--){
        for(int l = MAX_LIN - 1; l >= 0; l--){
            if(m[k][l]!=0){
                if(m[k][l]==m[k-1][l]){
                    int s = m[k][l]+m[k-1][l];
                    m[k][l] = s;
                    m[k-1][l] = 0;
                    pont = pont+s;              
                }
            }
        }
    }
    return pont;
}
int soma_esquerda(int m[][MAX_COL]){
    int pont = 0;
    for(int k = 0; k<=MAX_COL-1; k++){
        for(int l = 0; l<=MAX_LIN-1; l++){
            if(m[k][l]!=0){
                if(m[k][l]==m[k][l-1]&&l-1>=0){
                    int s = m[k][l]+m[k][l-1];
                    m[k][l] = s;
                    m[k][l-1] = 0;
                    pont = pont+s;
                }
            }
        }
    }
    return pont;                   
}
int soma_direita(int m[][MAX_COL]){
    int pont = 0;
    for(int k = MAX_COL-1; k>0-1; k--){
        for(int l = MAX_LIN-1; l>=0; l--){
            if(m[k][l]!=0){
                if(m[k][l]==m[k][l-1]&&l-1>=0){
                    int s = m[k][l]+m[k][l-1];
                    m[k][l] = s;
                    m[k][l-1] = 0;
                    pont = pont+s;
                }
            }
        }
    }
    return pont;
}

int move(char dir, int m[][MAX_COL]){
    //printf("Movendo elemento (%d)m[%d][%d] para (%d)m[%d][%d]\n",m[i][j],i,j,m[i][k],i,k);
    int somado;
    int pont;
    switch (dir){
    case 'W':
        do{
            for(int i = MAX_LIN-1; i>0; i--){
                for(int j = MAX_COL; j>=0; j--){
                    if(m[i][j]!=0){// quando um elemento diferente de zero for encontrado ele sera trocado de posição com o proximo elemento
                        //printf("Movendo elemento (%d)m[%d][%d] para (%d)m[%d][%d]\n\n",m[i][j],i,j,m[i-1][j],i-1,j);
                        // movimento dos elementos
                        if(i-1>=0&&m[i-1][j]==0){// fazer a troca apenas se o elemento tiver elementos nulos na frente
                            int temp1 = m[i][j];// salva elemento atual
                            int temp2 = m[i-1][j];// salva proximo elemento
                            m[i][j] = temp2;
                            m[i-1][j] = temp1;
                        }
                    }
                }
                //printf("fim da iteração %d\n",i);
            }
        }while(verifica_m_cima(m));// verificação extra para ver se todos os elementos foram movidos
    
    break;

    case 'S':
        do{
            for(int i = 0; i<MAX_LIN-1; i++){
                for(int j = 0;j <MAX_COL ;j++){
                    if(m[i][j]!=0){// quando um elemento diferente de zero for encontrado ele sera trocado de posição com o proximo elemento
                        //printf("Movendo elemento (%d)m[%d][%d] para (%d)m[%d][%d]\n\n",m[i][j],i,j,m[i+1][j],i+1,j);
                        // movimento dos elementos
                        int temp1 = m[i][j];// salva elemento atual
                        int temp2 = m[i+1][j];// salva proximo elemento 
                        if(i+1<MAX_LIN&&m[i+1][j]==0){// fazer a troca apenas se o elemento tiver elementos nulos na frente
                            m[i][j] = temp2;
                            m[i+1][j] = temp1;
                        }
                    }   
                }
                //printf("fim da iteração %d\n",i);
            }
        }while(verifica_m_baixo(m));// verificação extra para ver se todos os elementos foram movidos
    break;

    case 'A':
        do{
            for(int i = MAX_LIN-1; i>=0; i--){
                for(int j = MAX_COL-1; j>=0;j--){
                    if(m[i][j]!=0){// quando um elemento diferente de zero for encontrado ele sera trocado de posição com o proximo elemento
                        //printf("Movendo elemento (%d)m[%d][%d] para (%d)m[%d][%d]\n\n",m[i][j],i,j,m[i][j+1],i,j+1); 
                        
                        // movimento dos elemnto
                        int temp1 = m[i][j];// salva elemento atual
                        int temp2 = m[i][j-1];// salva proximo elemento
                        if(j-1>=0&&m[i][j-1]==0){// fazer a troca apenas se o elemento tiver elementos nulos na frente
                            m[i][j] = temp2;
                            m[i][j-1] = temp1;
                        }
                    }
                }
                //printf("fim da iteração %d\n",i);
            }
        }while(verifica_m_esq(m));// verificação extra para ver se todos os elementos foram movidos
    break;

    case 'D':
        do{
            for(int i = 0; i<MAX_LIN; i++){
                for(int j = 0;j <MAX_COL-1;j++){
                    if(m[i][j]!=0){// quando um elemento diferente de zero for encontrado ele sera trocado de posição com o proximo elemento
                        //printf("Movendo elemento (%d)m[%d][%d] para (%d)m[%d][%d]\n\n",m[i][j],i,j,m[i][j+1],i,j+1);
                        // movimento dos elementos
                        int temp1 = m[i][j];// salva elemento atual
                        int temp2 = m[i][j+1];// salva proximo elemento 
                        if(j+1<MAX_COL&&m[i][j+1]==0){// fazer a troca apenas se o elemento tiver elementos nulos na frente
                            m[i][j] = temp2;
                            m[i][j+1] = temp1;
                        } 
                    }
                }
                //printf("fim da iteração %d\n",i);
            }
        }while(verifica_m_dir(m));// verificação extra para ver se todos os elementos foram movidos
        break;    
    
    default:
        break;
    }
        
}

int verifica_vitoria(int m[][MAX_COL]){
    for (int i = 0; i <=MAX_COL-1; i++){
        for (int j = 0; j <=MAX_LIN-1; j++){
            if(m[i][j] == 2048){
                return 1;
            }
        }
    }
    return 0;   
}

int append_num_matriz(int m[][MAX_COL]){
    int num = (rand()%10==0)? 4:2;
    int pos_x = (rand()%4);
    int pos_y = (rand()%4);
    int tamanho = 0 ;
    int appendou = 0;
    while(!appendou){
        if(m[pos_x][pos_y] == 0 ){
            m[pos_x][pos_y] = num;
            appendou = 1;
        }
        if(tamanho==16){
            return 0;
        }
        else{
            pos_x = (rand()%3);
            pos_y = (rand()%3);
            tamanho++;
        } 
    }
}
int verifica_derrota(int m[][MAX_COL]){
    for (int i = 0; i < MAX_LIN; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            if (m[i][j] != 0) {
                if (j > 0 && (m[i][j] == m[i][j-1] || m[i][j-1] == 0)) {
                    return 0;
                }
                if (j < MAX_COL - 1 && (m[i][j] == m[i][j+1] || m[i][j+1] == 0)) {
                    return 0;
                }
                if (i > 0 && (m[i][j] == m[i-1][j] || m[i - 1][j] == 0)) {
                    return 0;
                }
                if (i < MAX_LIN - 1 && (m[i][j] == m[i+1][j] || m[i+1][j] == 0)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));
    //matriz teste cima baixo int m[MAX_LIN][MAX_COL] = {{4,0,8,2},{2,8,0,2},{2,8,0,2},{2,8,8,2}};
    //matriz teste esquerda direita int m[MAX_LIN][MAX_COL] = {{4,4,4,4},{8,8,8,0},{4,2,2,2},{4,2,0,2}};
    //matriz teste vitoria 
    int m[MAX_LIN][MAX_COL] = {{0,0,0,1024},{0},{0,0,0,0},{0,0,0,1024}};
    //matriz teste derrota int m[MAX_LIN][MAX_COL] = {{64,2,8,4},{128,8,2,16},{64,128,1024,2},{16,64,128,4}};
    //int m[MAX_LIN][MAX_COL] ={0};
    char d = ' ';
    int pontos = 0;
    int op = 0;
    //menu
    while(1){
        system("clear");
        printf("===============\n");
        printf(" Jogo 2048 \n");
        printf(" 0 - Sair\n");
        printf(" 1 - Jogar\n");
        printf(" Use W A S D para mover as celulas em suas respectivas direções.\n");
        printf(" Consiga uma celula com o numero 2048 para ganhar o jogo.\n");
        printf("===============\n");
        printf("Digite sua opção: ");
        scanf("%d",&op);
        getchar();
        if(op == 1){
            break;
        }else if(op==0){
            printf("Encerrando o jogo...\n");
            exit(1);
        }else{
            printf("Digite uma opção valida.\n");
        }
    }
    //jogo  
    append_num_matriz(m);
    while(!verifica_vitoria(m)){
        //system("clear");
        append_num_matriz(m);
        print_m(m);
        printf("Pontuação Atual: %d \n\n",pontos);
        printf("Escolha uma direção(W/A/S/D): ");
        printf("\n");
        scanf("%c",&d);
        if(toupper(d)=='W'){
            move(toupper(d),m);
            pontos = pontos + soma_cima(m);
            move(toupper(d),m);
        }
        if(toupper(d)=='S'){
            move(toupper(d),m);
            pontos = pontos+ soma_baixo(m);
            move(toupper(d),m);
        }
        if(toupper(d)=='A'){
            move(toupper(d),m);
            pontos = pontos + soma_esquerda(m);
            move(toupper(d),m);
        }
        if(toupper(d)=='D'){
            move(toupper(d),m);
            pontos  = pontos + soma_direita(m);
            move(toupper(d),m);
        }
        
        getchar();//limpa buffer teclado
        if(verifica_derrota(m)){
            system("clear");
            printf("Voce perdeu!\n");
            exit(1);
        }
    }
    system("clear");
    print_m(m);
    printf("Parabens! Voce venceu!\n");
    printf("Pontuação: %d\n",pontos);
    return 0;
}
