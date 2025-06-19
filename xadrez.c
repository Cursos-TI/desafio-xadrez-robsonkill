#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Simula os movimentos de peças de xadrez usando estruturas de repetição e funções.
// Nível Novato: Bispo, Torre e Rainha
// Nível Aventureiro: Cavalo com loops aninhados
// Nível Mestre: Bispo com recursão, Cavalo com loops avançados (break/continue)

void mover_bispo() {
    printf("Nível Novato - Movimento do Bispo (diagonais):\n");
    for (int i = 1; i <= 8; i++) {
        printf("Diagonal inferior direita: +%d linha / +%d coluna\n", i, i);
        printf("Diagonal superior esquerda: -%d linha / -%d coluna\n", i, i);
    }
    printf("\n");
}

void mover_torre() {
    printf("Nível Novato - Movimento da Torre (linha reta para direita):\n");
    for (int i = 1; i <= 8; i++) {
        printf("Mover %d casas para a direita\n", i);
    }
    printf("\n");
}

void mover_rainha() {
    printf("Nível Novato - Movimento da Rainha (linha reta para esquerda):\n");
    for (int i = 1; i <= 8; i++) {
        printf("Mover %d casas para a esquerda\n", i);
    }
    printf("\n");
}

void mover_cavalo() {
    printf("Nível Aventureiro - Movimento do Cavalo (em L):\n");
    int movimentos[8][2] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
    };

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 1; j++) { // loop aninhado simples
            printf("Mover para linha %+d, coluna %+d\n", movimentos[i][0], movimentos[i][1]);
        }
    }
    printf("\n");
}

// Função recursiva para movimento do Bispo (avançado)
void bispo_recursivo(int passo, int maximo) {
    if (passo > maximo) return;
    printf("Bispo recursivo: +%d linha / +%d coluna\n", passo, passo);
    bispo_recursivo(passo + 1, maximo);
}

// Movimento do Cavalo com break e continue
void cavalo_mestre() {
    printf("Nível Mestre - Movimento do Cavalo com condições e break/continue:\n");

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        if (dx[i] == 0 && dy[i] == 0) continue; // pula movimentos inválidos (não tem nesse caso, mas serve de exemplo)
        if (i == 6) break; // exemplo de uso de break
        printf("Cavalo avança para linha %+d, coluna %+d\n", dx[i], dy[i]);
    }

    printf("\n");
}

int main() {
    // Nível Novato
    mover_bispo();
    mover_torre();
    mover_rainha();

    // Nível Aventureiro
    mover_cavalo();

    // Nível Mestre
    printf("Movimento do Bispo com Recursão:\n");
    bispo_recursivo(1, 8);

    cavalo_mestre();

    return 0;
}
