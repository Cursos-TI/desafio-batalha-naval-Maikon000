#include <stdio.h>

int main() {
    // --- DEFINIÇÃO DE VARIÁVEIS DE CONFIGURAÇÃO ---
    int tamanhoTabuleiro = 10;
    int tamanhoNavio = 3;
    int valorAgua = 0;
    int valorNavio = 3;

    // --- 1. INICIALIZAÇÃO DO TABULEIRO ---
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = valorAgua;
        }
    }

    // --- 2. POSICIONAMENTO DOS NAVIOS ---

    // Coordenadas Iniciais - Definidas para evitar sobreposição
    int linhaH = 2, colunaH = 1; // Horizontal
    int linhaV = 5, colunaV = 7; // Vertical
    int linhaD1 = 0, colunaD1 = 5; // Diagonal 1 (Desce-Direita)
    int linhaD2 = 7, colunaD2 = 2; // Diagonal 2 (Sobe-Direita / Desce-Esquerda)

    // A. Posicionamento do Navio Horizontal
    // (Linha constante, Coluna aumenta)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = valorNavio;
    }

    // B. Posicionamento do Navio Vertical
    // (Linha aumenta, Coluna constante)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = valorNavio;
    }

    // C. Posicionamento do Navio Diagonal 1 (Descendo para a Direita)
    // Lógica: Tanto a linha quanto a coluna aumentam (+i, +i)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = valorNavio;
    }

    // D. Posicionamento do Navio Diagonal 2 (Descendo para a Esquerda)
    // Lógica: A linha aumenta e a coluna diminui (+i, -i)
    // Coordenada inicial (7,2) ocupará: (7,2), (8,1) e (9,0)
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = valorNavio;
    }

    // --- 3. EXIBIÇÃO DO TABULEIRO ---
    printf("=========================================\n");
    printf("       TABULEIRO DE BATALHA NAVAL        \n");
    printf("=========================================\n\n");

    // Cabeçalho das colunas (Letras)
    printf("     "); 
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        printf("%c ", 'A' + j); 
    }
    printf("\n");

    // Corpo do tabuleiro
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%2d | ", i); 

        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\nLegenda: %d = Água | %d = Navio\n", valorAgua, valorNavio);

    return 0;
}