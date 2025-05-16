#include <stdio.h>
#include <stdlib.h>

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

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
		if (coluna + 3 > 10) return 0;
		for (int i = 0; i < 3; i++) {
			if (tabuleiro[linha][coluna + i] != AGUA) return 0;
		}
	} else if (orientacao == 'V') {
		if (linha + 3 > 10) return 0;
		for (int i = 0; i < 3; i++) {
			if (tabuleiro[linha + i][coluna] != AGUA) return 0;
		}
	} else if (orientacao == 'D') {
		if (linha + 3 > 10 || coluna + 3 > 10) return 0;
		for (int i = 0; i < 3; i++) {
			if (tabuleiro[linha + i][coluna + i] != AGUA) return 0;
		}
	} else if (orientacao == 'A') {
		if (linha + 3 > 10 || coluna - 2 < 0) return 0;
		for (int i = 0; i < 3; i++) {
			if (tabuleiro[linha + i][coluna - i] != AGUA) return 0;
		}
	}
	return 1;
}

void colocarNavioHorizontalmente(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha][coluna + i] = navio[i];
	}
}

void colocarNavioVerticalmente(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha + i][coluna] = navio[i];
	}
}

void colocarNavioDiagonalDesc(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha + i][coluna + i] = navio[i];
	}
}

void colocarNavioDiagonalAsc(int linha, int coluna, int *navio, int tabuleiro[10][10]) {
	for (int i = 0; i < 3; i++) {
		tabuleiro[linha + i][coluna - i] = navio[i];
	}
}

// Aplica uma matriz de habilidade no tabuleiro centrada em (centroLinha, centroColuna)
void aplicarHabilidade(int tabuleiro[10][10], int habilidade[5][5], int centroLinha, int centroColuna) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (habilidade[i][j] == 1) {
				int linhaTab = centroLinha - 2 + i;
				int colunaTab = centroColuna - 2 + j;
				if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
					if (tabuleiro[linhaTab][colunaTab] == AGUA) {
						tabuleiro[linhaTab][colunaTab] = HABILIDADE;
					}
				}
			}
		}
	}
}

int main() {
	int tabuleiro[10][10] = {AGUA};  // Inicializa com AGUA

	printf("Tabuleiro inicial:\n");
	imprimirTabuleiro(tabuleiro);

	// Navios
	int navio1[3] = {NAVIO, NAVIO, NAVIO};
	int navio2[3] = {NAVIO, NAVIO, NAVIO};
	int navio3[3] = {NAVIO, NAVIO, NAVIO};
	int navio4[3] = {NAVIO, NAVIO, NAVIO};

	// Coloca os navios
	if (podeColocarNavio(1, 3, tabuleiro, 'H')) {
		colocarNavioHorizontalmente(1, 3, navio1, tabuleiro);
	}
	if (podeColocarNavio(7, 8, tabuleiro, 'V')) {
		colocarNavioVerticalmente(7, 8, navio2, tabuleiro);
	}
	if (podeColocarNavio(0, 0, tabuleiro, 'D')) {
		colocarNavioDiagonalDesc(0, 0, navio3, tabuleiro);
	}
	if (podeColocarNavio(4, 4, tabuleiro, 'A')) {
		colocarNavioDiagonalAsc(4, 4, navio4, tabuleiro);
	}

	// Mostra o tabuleiro após colocar os navios
	printf("\nTabuleiro após colocar os navios:\n");
	imprimirTabuleiro(tabuleiro);

	// Matrizes das habilidades
	int habilidadeCone[5][5];
	int habilidadeCruz[5][5];
	int habilidadeOctaedro[5][5];

	// Cone (ponta no topo, base expandindo)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			habilidadeCone[i][j] = (j >= 2 - i && j <= 2 + i) ? 1 : 0;
		}
	}

	// Cruz (linha e coluna central)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			habilidadeCruz[i][j] = (i == 2 || j == 2) ? 1 : 0;
		}
	}

	// Octaedro (losango)
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			habilidadeOctaedro[i][j] = (abs(i - 2) + abs(j - 2) <= 2) ? 1 : 0;
		}
	}

	// Aplica as habilidades no tabuleiro em posições fixas
	aplicarHabilidade(tabuleiro, habilidadeCone, 2, 2);
	aplicarHabilidade(tabuleiro, habilidadeCruz, 5, 5);
	aplicarHabilidade(tabuleiro, habilidadeOctaedro, 7, 2);

	// Mostra o resultado final
	printf("\nTabuleiro após habilidades:\n");
	imprimirTabuleiro(tabuleiro);

	return 0;
}