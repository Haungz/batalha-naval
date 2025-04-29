#include <stdio.h>

// Imprime o tabuleiro de batalha naval
void imprimirTabuleiro(int tabuleiro[10][10]) {
	printf("  A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Coloca um navio horizontalmente no tabuleiro
void colocarNavioHorizontalmente(int linha1, int coluna1, int *navio1, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha1][coluna1 + i] = navio1[i];
	}
}

// Coloca um navio verticalmente no tabuleiro
void colocarNavioVerticalmente(int linha1, int coluna1, int *navio2, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha1 + i][coluna1] = navio2[i];
	}
}

int main() {
	int tabuleiro[10][10] = {0};            // Inicializa o tabuleiro com 0 (vazio)

	printf("Tabuleiro inicial:\n");
	imprimirTabuleiro(tabuleiro);          // Imprime o tabuleiro inicial

    // Variáveis para armazenar a escolha do jogador (Coluna = A = 1, B = 2... J = 10 ; Linha = 1 a 10)

	int navio1[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int navio2[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int escolhaLinha1, escolhaLinha2, escolhaColuna1, escolhaColuna2; // Variáveis para armazenar a linha e coluna escolhidas pelo jogador
	escolhaLinha1 = 2, escolhaColuna1 = 4; // Exemplo de escolha de linha e coluna para o primeiro navio
	escolhaLinha2 = 5, escolhaColuna2 = 6; // Exemplo de escolha de linha e coluna para o segundo navio

	colocarNavioHorizontalmente(escolhaLinha1 - 1, escolhaColuna1 - 1, navio1, tabuleiro); // Coloca o primeiro navio no tabuleiro
	colocarNavioVerticalmente(escolhaLinha2 - 1, escolhaColuna2 - 1, navio2, tabuleiro); // Coloca o segundo navio no tabuleiro

	imprimirTabuleiro(tabuleiro);          // Imprime o tabuleiro após colocar o navio
}