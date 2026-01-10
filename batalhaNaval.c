#include <stdio.h>

/**
 * PROJETO: BATALHA NAVAL - SISTEMA DE HABILIDADES ESPECIAIS
 * OBJETIVO: Demonstrar matrizes bidimensionais, loops aninhados e lógica geométrica.
 */

int main() {
    // --- DEFINIÇÃO DE VARIÁVEIS DE CONFIGURAÇÃO ---
    int tamanhoTabuleiro = 10;   // Dimensão do mapa (10x10)
    int tamanhoNavio = 3;       // Comprimento dos navios
    int valorAgua = 0;          // Representação visual da água
    int valorNavio = 3;         // Representação visual do navio
    int valorHabilidade = 1;    // Representação visual da área de efeito (AoE)

    // --- 1. INICIALIZAÇÃO DO TABULEIRO ---
    int tabuleiro[tamanhoTabuleiro][tamanhoTabuleiro];

    // Preenche o tabuleiro inteiro com "Água" (0)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            tabuleiro[i][j] = valorAgua;
        }
    }

    // --- 2. POSICIONAMENTO DOS NAVIOS ---
    // Definimos pontos estratégicos para evitar sobreposição entre navios e habilidades
    int linhaH = 2, colunaH = 1; 
    int linhaV = 3, colunaV = 9; 
    int linhaD1 = 0, colunaD1 = 2; 
    int linhaD2 = 3, colunaD2 = 3; 

    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = valorNavio;       // Navio Horizontal
        tabuleiro[linhaV + i][colunaV] = valorNavio;       // Navio Vertical
        tabuleiro[linhaD1 + i][colunaD1 + i] = valorNavio; // Diagonal Principal (\)
        tabuleiro[linhaD2 + i][colunaD2 - i] = valorNavio; // Diagonal Secundária (/)
    }

    // --- 3. CRIAÇÃO DINÂMICA DAS MATRIZES DE HABILIDADE (5x5) ---
    int tamanhoHabilidade = 5;
    int centroHabilidade = tamanhoHabilidade / 2; // O centro da matriz 5x5 é o índice [2][2]
    int matrizCone[5][5], matrizCruz[5][5], matrizOctaedro[5][5];

    // Este loop constrói as formas geométricas dentro de matrizes menores de 5x5
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            matrizCone[i][j] = 0;
            matrizCruz[i][j] = 0;
            matrizOctaedro[i][j] = 0;

            // LÓGICA DO CONE:
            // O cone começa no topo central e expande uma casa para cada lado ao descer.
            // Condição: a coluna (j) deve estar no intervalo [centro-linha, centro+linha]
            if (i >= 0 && i <= centroHabilidade) {
                if (j >= centroHabilidade - i && j <= centroHabilidade + i) {
                    matrizCone[i][j] = 1;
                }
            }

            // LÓGICA DA CRUZ:
            // Ativa todas as casas onde a linha OU a coluna é igual ao índice central.
            if (i == centroHabilidade || j == centroHabilidade) {
                matrizCruz[i][j] = 1;
            }

            // LÓGICA DO OCTAEDRO (LOSANGO):
            // Baseado na Distância de Manhattan: a soma da distância absoluta da linha 
            // e da coluna até o centro não pode ultrapassar o raio definido (centroHabilidade).
            int distI = (i > centroHabilidade) ? i - centroHabilidade : centroHabilidade - i;
            int distJ = (j > centroHabilidade) ? j - centroHabilidade : centroHabilidade - j;
            if (distI + distJ <= centroHabilidade) {
                matrizOctaedro[i][j] = 1;
            }
        }
    }

    // --- 4. SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO ---
    // Definimos onde o CENTRO de cada habilidade será aplicado no mapa principal
    int origemConeL = 2, origemConeC = 7; 
    int origemCruzL = 7, origemCruzC = 7; 
    int origemOctaL = 5, origemOctaC = 4; 

    // O loop percorre a matriz de habilidade e a "carimba" no tabuleiro
    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            // deslocamentoL/C calcula a posição relativa ao centro (ex: -2, -1, 0, 1, 2)
            int deslocamentoL = i - centroHabilidade; 
            int deslocamentoC = j - centroHabilidade;

            // Lógica de aplicação com Verificação de Bordas (Boundary Check)
            // Garante que a habilidade não tente acessar índices fora do tabuleiro (0-9)
            
            // Aplicar Cone
            int tLCone = origemConeL + deslocamentoL, tCCone = origemConeC + deslocamentoC;
            if (tLCone >= 0 && tLCone < tamanhoTabuleiro && tCCone >= 0 && tCCone < tamanhoTabuleiro) {
                if (matrizCone[i][j] == 1) tabuleiro[tLCone][tCCone] = valorHabilidade;
            }

            // Aplicar Cruz
            int tLCruz = origemCruzL + deslocamentoL, tCCruz = origemCruzC + deslocamentoC;
            if (tLCruz >= 0 && tLCruz < tamanhoTabuleiro && tCCruz >= 0 && tCCruz < tamanhoTabuleiro) {
                if (matrizCruz[i][j] == 1) tabuleiro[tLCruz][tCCruz] = valorHabilidade;
            }

            // Aplicar Octaedro
            int tLOcta = origemOctaL + deslocamentoL, tCOcta = origemOctaC + deslocamentoC;
            if (tLOcta >= 0 && tLOcta < tamanhoTabuleiro && tCOcta >= 0 && tCOcta < tamanhoTabuleiro) {
                if (matrizOctaedro[i][j] == 1) tabuleiro[tLOcta][tCOcta] = valorHabilidade;
            }
        }
    }

    // --- 5. EXIBIÇÃO DO RESULTADO ---
    printf("=========================================\n"); 
    printf("       TABULEIRO DE BATALHA NAVAL        \n");
    printf("=========================================\n\n"); 

    // Exibe cabeçalho de letras (A-J)
    printf("     "); 
    for (int j = 0; j < tamanhoTabuleiro; j++) {
        printf("%c ", 'A' + j); 
    }
    printf("\n"); 

    // Exibe o conteúdo do tabuleiro
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%2d | ", i); // Coordenada numérica lateral

        for (int j = 0; j < tamanhoTabuleiro; j++) {
            // Imprime o valor da célula (0, 1 ou 3)
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); 
    }

    printf("\nLEGENDA: 0 = Água | 3 = Navio | 1 = Área de Efeito\n");

    return 0;
}