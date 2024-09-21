#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

void lib_mat(int **,int);
void print_m(int **,int,int);
int cont_viz(int **,int,int,int,int);
void prox_gen(int **,int,int);

void lib_mat(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void print_m(int **m, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (m[i][j] == 0) {
                printf(" ");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

int cont_viz(int **matriz, int linhas, int colunas, int l, int c) {
    int count = 0;
    for (int i = l - 1; i <= l + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < linhas && j >= 0 && j < colunas && !(i == l && j == c)) {
                count += matriz[i][j];
            }
        }
    }
    return count;
}

void prox_gen(int **matriz, int linhas, int colunas) {
    int **nova_matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        nova_matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int vizinhos_vivos = cont_viz(matriz, linhas, colunas, i, j);

            if (matriz[i][j] == 1) { // célula viva
                if (vizinhos_vivos < 2 || vizinhos_vivos > 3) {
                    nova_matriz[i][j] = 0; // morre
                } else {
                    nova_matriz[i][j] = 1; // continua viva
                }
            } else { // célula morta
                if (vizinhos_vivos == 3) {
                    nova_matriz[i][j] = 1; // se torna viva
                } else {
                    nova_matriz[i][j] = 0; // permanece morta
                }
            }
        }
    }

    // atualizar a matriz original com a nova geração
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = nova_matriz[i][j];
        }
    }

    // liberar a memória da nova matriz
    for (int i = 0; i < linhas; i++) {
        free(nova_matriz[i]);
    }
    free(nova_matriz);
}

int main() {
    //===== leitura e montagem da matriz
    system("clear");

    char *nomeArquivo;
    int n_gen;
    printf("Escolha o arquivo .vid a ser lido: ");
    scanf("%s",nomeArquivo);
    printf("Escolha o numero de gerações: ");
    scanf("%d",&n_gen);
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    int linhas, colunas;
    fscanf(arquivo, "%d", &linhas);
    fscanf(arquivo, "%d", &colunas);

    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        perror("Erro ao alocar memória para as linhas da matriz");
        fclose(arquivo);
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            perror("Erro ao alocar memória para as colunas da matriz");
            lib_mat(matriz, i);
            fclose(arquivo);
            return 1;
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fscanf(arquivo, "%1d", &matriz[i][j]);
        }
    }

    fclose(arquivo);
//======================

    while(n_gen>=0){
        system("clear");
        print_m(matriz, linhas, colunas);
        printf("\n");
        prox_gen(matriz, linhas, colunas);
        usleep(500000);// tempo de espera em micro segundos 
        n_gen--;
    }

    lib_mat(matriz, linhas);

    return 0;
}
