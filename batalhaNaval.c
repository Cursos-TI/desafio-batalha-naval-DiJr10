#include <stdio.h>
#include <stdlib.h> // <--- INCLUSÃO NECESSÁRIA PARA USAR A FUNÇÃO abs()

// Definições para o tamanho máximo do tabuleiro (Nível Aventureiro/Mestre)
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NOVATO 5
#define OCUPADO 3
#define AFETADO 1

// Função auxiliar para exibir uma matriz
void exibir_matriz(int matriz[][TAMANHO_TABULEIRO], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("****************************************\n");
    printf("     Desafio Batalha Naval - MateCheck  \n");
    printf("****************************************\n\n");
    
    // --- Nível Novato - Posicionamento dos Navios ---
    printf("--- NÍVEL NOVATO: Tabuleiro 5x5 e Coordenadas ---\n");
    
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro_novato[TAMANHO_NOVATO][TAMANHO_NOVATO] = {0};

    // Navio 1 (Vertical - 2 posições: (1, 2) e (2, 2))
    int navio1_coords[2][2] = {{1, 2}, {2, 2}};
    tabuleiro_novato[1][2] = OCUPADO;
    tabuleiro_novato[2][2] = OCUPADO;

    // Navio 2 (Horizontal - 3 posições: (4, 0), (4, 1) e (4, 2))
    int navio2_coords[3][2] = {{4, 0}, {4, 1}, {4, 2}};
    tabuleiro_novato[4][0] = OCUPADO;
    tabuleiro_novato[4][1] = OCUPADO;
    tabuleiro_novato[4][2] = OCUPADO;

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("\nCoordenadas do Navio 1 (Vertical):\n");
    for (int i = 0; i < 2; i++) {
        printf("(%d, %d) ", navio1_coords[i][0], navio1_coords[i][1]);
    }
    printf("\nCoordenadas do Navio 2 (Horizontal):\n");
    for (int i = 0; i < 3; i++) {
        printf("(%d, %d) ", navio2_coords[i][0], navio2_coords[i][1]);
    }
    printf("\n");
    
    // --------------------------------------------------------------------------------

    // --- Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal ---
    printf("\n--- NÍVEL AVENTUREIRO: Tabuleiro 10x10 com Diagonais ---\n");
    
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    int tabuleiro_avent[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    
    // Posicionamento dos 4 navios (0 = Vazio, 3 = Ocupado)
    
    // Navio A (Vertical - 3 posições)
    tabuleiro_avent[1][1] = OCUPADO;
    tabuleiro_avent[2][1] = OCUPADO;
    tabuleiro_avent[3][1] = OCUPADO;

    // Navio B (Horizontal - 4 posições)
    tabuleiro_avent[8][3] = OCUPADO;
    tabuleiro_avent[8][4] = OCUPADO;
    tabuleiro_avent[8][5] = OCUPADO;
    tabuleiro_avent[8][6] = OCUPADO;

    // Navio C (Diagonal Descendente - 3 posições)
    tabuleiro_avent[5][5] = OCUPADO;
    tabuleiro_avent[6][6] = OCUPADO;
    tabuleiro_avent[7][7] = OCUPADO;
    
    // Navio D (Diagonal Ascendente - 2 posições)
    tabuleiro_avent[0][8] = OCUPADO;
    tabuleiro_avent[1][7] = OCUPADO;

    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
    printf("\nTabuleiro 10x10:\n");
    exibir_matriz(tabuleiro_avent, TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);

    // --------------------------------------------------------------------------------

    // --- Nível Mestre - Habilidades Especiais com Matrizes ---
    printf("\n--- NÍVEL MESTRE: Habilidades Especiais (3x5) ---\n");
    
    const int HABILIDADE_LINHAS = 3;
    const int HABILIDADE_COLUNAS = 5; // A variável em si está correta.
    const int CENTRO_LINHA = 1; // Para matriz 3x5
    const int CENTRO_COLUNA = 2; // Para matriz 3x5
    
    // Matriz para simular a área de efeito da habilidade (3x5 é um exemplo)
    int habilidade[HABILIDADE_LINHAS][HABILIDADE_COLUNAS] = {0};

    // 1. Habilidade em Cruz (Centro: [1][2])
    printf("\nHabilidade em Cruz (1 = Atingido):\n");
    
    // Reinicia a matriz
    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            habilidade[i][j] = 0;
        }
    }
    
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas.
    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            // Condição para Cruz: i é o centro (1) OU j é o centro (2)
            if (i == CENTRO_LINHA || j == CENTRO_COLUNA) {
                habilidade[i][j] = AFETADO;
            }
        }
    }
    exibir_matriz(habilidade, HABILIDADE_LINHAS, HABILIDADE_COLUNAS);


    // 2. Habilidade em Cone (Crescimento a partir da linha superior)
    printf("\nHabilidade em Cone (1 = Atingido):\n");

    // Reinicia a matriz
    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            habilidade[i][j] = 0;
        }
    }

    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            // Lógica para Cone
            if (j >= CENTRO_COLUNA - i && j <= CENTRO_COLUNA + i) {
                habilidade[i][j] = AFETADO;
            }
        }
    }
    exibir_matriz(habilidade, HABILIDADE_LINHAS, HABILIDADE_COLUNAS);


    // 3. Habilidade em Octaedro (ou "Losango" no 2D)
    printf("\nHabilidade em Octaedro (1 = Atingido):\n");
    
    // Reinicia a matriz
    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            habilidade[i][j] = 0;
        }
    }

    for (int i = 0; i < HABILIDADE_LINHAS; i++) {
        for (int j = 0; j < HABILIDADE_COLUNAS; j++) {
            // Lógica para Octaedro (usando Distância de Manhattan)
            // A função abs() exige #include <stdlib.h>
            int dist_manhattan = abs(i - CENTRO_LINHA) + abs(j - CENTRO_COLUNA);
            
            if (dist_manhattan <= 1) { 
                habilidade[i][j] = AFETADO;
            }
        }
    }
    exibir_matriz(habilidade, HABILIDADE_LINHAS, HABILIDADE_COLUNAS);

    printf("\n****************************************\n");
    printf("Fim do Desafio Batalha Naval - Mestre.\n");
    printf("****************************************\n");

    return 0;
}