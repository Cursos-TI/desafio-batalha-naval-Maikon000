#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    // Programa: Simulação de Batalha Naval (Nível Novato)
// Descrição: Cria um tabuleiro 10x10, posiciona dois navios (horizontal e vertical)
// e exibe o resultado no console com coordenadas de letras e números.

    // == DEFINIÇÃO DE VARIÁVEIS DE CONFIGURAÇÃO ==
    int tamanhoTabuleiro = 10; // Define a dimensão da matriz (10x10)
    int tamanhoNavio = 3;      // Define quantas casas cada navio ocupará
    int valorAgua = 0;         // Representação numérica da água no tabuleiro
    int valorNavio = 3;        // Representação numérica do navio no tabuleiro

    // = 1. INICIALIZAÇÃO DO TABULEIRO =
    // Criamos a matriz bidimensional para o tabuleiro
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    // Loops aninhados para percorrer cada linha (i) e coluna (j)
    // Inicializamos todas as posições com 0 (água)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = valorAgua;
        }
    }

    // --- 2. CRIAÇÃO E POSICIONAMENTO DOS NAVIOS ---
    // Declaramos os vetores que representam os navios
    int navioHorizontal[tamanhoNavio];
    int navioVertical[tamanhoNavio];

    // Preenchemos os vetores com o valor que representa o navio (3)
    for (int i = 0; i < tamanhoNavio; i++) {
        navioHorizontal[i] = valorNavio;
        navioVertical[i] = valorNavio;
    }

    // Definimos as coordenadas iniciais de onde cada navio começará
    // Importante: As coordenadas devem permitir que o navio caiba no tabuleiro
    int linhaInicialH = 2, colunaInicialH = 1; // Navio Horizontal
    int linhaInicialV = 5, colunaInicialV = 7; // Navio Vertical

    // Posicionamento do Navio Horizontal:
    // Mantemos a linha fixa e incrementamos a coluna para "deitar" o navio
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaInicialH][colunaInicialH + i] = navioHorizontal[i];
    }

    // Posicionamento do Navio Vertical:
    // Mantemos a coluna fixa e incrementamos a linha para "erguer" o navio
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaInicialV + i][colunaInicialV] = navioVertical[i];
    }

    // --- 3. EXIBIÇÃO DO TABULEIRO ---
    printf("=========================================\n");
    printf("       TABULEIRO DE BATALHA NAVAL        \n");
    printf("=========================================\n\n");

    // Imprime o cabeçalho das colunas usando LETRAS (A, B, C...)
    // O espaço inicial serve para alinhar as letras com o corpo do tabuleiro
    printf("     "); 
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        // 'A' + j converte o índice numérico no caractere correspondente da tabela ASCII
        printf("%c ", 'A' + j); 
    }
    printf("\n");

    // Imprime o conteúdo do tabuleiro linha por linha
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        // %2d garante que números de 1 dígito fiquem alinhados com os de 2 dígitos
        // O caractere '|' serve como uma borda visual para separar a coordenada do mapa
        printf("%2d | ", i); 

        for (int j = 0; j < tamanhoTabuleiro; j++) {
            // Imprime o valor da célula (0 para água, 3 para navio) seguido de um espaço
            printf("%d ", tabuleiro[i][j]);
        }
        // Pula para a próxima linha após completar as colunas
        printf("\n");
    }

    printf("\nLegenda: %d = Água | %d = Navio\n", valorAgua, valorNavio);

    return 0;
}
