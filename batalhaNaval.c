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

// Verifica se é possível colocar o navio no tabuleiro (sem sair dos limites ou sobrepor)
int podeColocarNavio(int linha, int coluna, int tabuleiro[10][10], char orientacao) {
    if (orientacao == 'H') {
        if (coluna + 3 > 10) return 0; // Passaria do limite à direita
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Já tem algo na posição
        }
    } else if (orientacao == 'V') {
        if (linha + 3 > 10) return 0; // Passaria do limite inferior
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0; // Já tem algo na posição
        }
    } else if (orientacao == 'D') {
        if (linha + 3 > 10 || coluna + 3 > 10) return 0; // Passaria do limite inferior ou direito
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha + i][coluna + i] != 0) return 0; // Já tem algo na posição
        }
    } else if (orientacao == 'A') {
        if (linha + 3 > 10 || coluna - 2 < 0) return 0; // Passaria do limite inferior ou esquerdo
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha + i][coluna - i] != 0) return 0; // Já tem algo na posição
        }
    }
    return 1;
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

// Coloca um navio na diagonal descendente (↘) no tabuleiro
void colocarNavioDiagonalDesc(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha + i][coluna + i] = navio[i];
	}
}

// Coloca um navio na diagonal ascendente (↗) no tabuleiro
void colocarNavioDiagonalAsc(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha + i][coluna - i] = navio[i];
	}
}

int main() {
	int tabuleiro[10][10] = {0};            // Inicializa o tabuleiro com 0 (vazio)

	printf("Tabuleiro inicial:\n");
	imprimirTabuleiro(tabuleiro);          // Imprime o tabuleiro inicial

    // Variáveis para armazenar a escolha do jogador (Coluna = A = 1, B = 2... J = 10 ; Linha = 1 a 10)

	int navio1[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int navio2[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int navio3[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int navio4[3] = {3, 3, 3};         // Navio de tamanho 3 (representado por 3 no tabuleiro)
	int escolhaLinha1, escolhaLinha2, escolhaLinha3, escolhaLinha4;
	int escolhaColuna1, escolhaColuna2, escolhaColuna3, escolhaColuna4;

	escolhaLinha1 = 2, escolhaColuna1 = 4; // Exemplo de escolha de linha e coluna para o primeiro navio
	escolhaLinha2 = 8, escolhaColuna2 = 9; // Exemplo de escolha de linha e coluna para o segundo navio
	escolhaLinha3 = 1, escolhaColuna3 = 1; // Exemplo de escolha de linha e coluna para o navio diagonal
	escolhaLinha4 = 5, escolhaColuna4 = 5; // Exemplo de escolha de linha e coluna para o navio diagonal

	if (podeColocarNavio(escolhaLinha1 - 1, escolhaColuna1 - 1, tabuleiro, 'H')) {
		colocarNavioHorizontalmente(escolhaLinha1 - 1, escolhaColuna1 - 1, navio1, tabuleiro); // Coloca o primeiro navio no tabuleiro
	} else {
		printf("Não foi possível colocar o navio 1 na posição escolhida.\n");
	}

	if (podeColocarNavio(escolhaLinha2 - 1, escolhaColuna2 - 1, tabuleiro, 'V')) {
		colocarNavioVerticalmente(escolhaLinha2 - 1, escolhaColuna2 - 1, navio2, tabuleiro); // Coloca o segundo navio no tabuleiro
	} else {
		printf("Não foi possível colocar o navio 2 na posição escolhida.\n");
	}

	if (podeColocarNavio(escolhaLinha3 - 1, escolhaColuna3 - 1, tabuleiro, 'D')) {
		colocarNavioDiagonalDesc(escolhaLinha3 - 1, escolhaColuna3 - 1, navio3, tabuleiro); // Coloca o navio na diagonal
	} else {
		printf("Não foi possível colocar o navio 3 na posição diagonal escolhida.\n");
	}

	if (podeColocarNavio(escolhaLinha4 - 1, escolhaColuna4 - 1, tabuleiro, 'A')) {
		colocarNavioDiagonalAsc(escolhaLinha4 - 1, escolhaColuna4 - 1, navio4, tabuleiro); // Coloca o navio na diagonal
	} else {
		printf("Não foi possível colocar o navio 4 na posição diagonal escolhida.\n");
	}
	
	imprimirTabuleiro(tabuleiro);          // Imprime o tabuleiro após colocar os navios

	return 0;
}
