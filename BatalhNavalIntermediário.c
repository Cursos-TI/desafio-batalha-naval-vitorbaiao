#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Inicializa o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verifica se navio pode ser posicionado na horizontal ou vertical
int podePosicionarNavioHV(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if(orientacao == 'H') {
        if(coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites horizontais
        for(int c = coluna; c < coluna + TAM_NAVIO; c++) {
            if(tabuleiro[linha][c] == 3) return 0; // Sobreposição
        }
    } else if(orientacao == 'V') {
        if(linha + TAM_NAVIO > TAM_TABULEIRO) return 0; // Fora dos limites verticais
        for(int l = linha; l < linha + TAM_NAVIO; l++) {
            if(tabuleiro[l][coluna] == 3) return 0; // Sobreposição
        }
    } else {
        return 0; // Orientação inválida
    }
    return 1;
}

// Posiciona navio horizontal ou vertical
void posicionarNavioHV(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if(orientacao == 'H') {
        for(int c = coluna; c < coluna + TAM_NAVIO; c++) {
            tabuleiro[linha][c] = 3;
        }
    } else if(orientacao == 'V') {
        for(int l = linha; l < linha + TAM_NAVIO; l++) {
            tabuleiro[l][coluna] = 3;
        }
    }
}

// Verifica se navio pode ser posicionado na diagonal
// direcaoDiagonal = 1 para diagonal principal (\), -1 para diagonal inversa (/)
int podePosicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcaoDiagonal) {
    // Verifica limites:
    int colunaFinal = coluna + (TAM_NAVIO - 1) * direcaoDiagonal;
    if(linha + TAM_NAVIO > TAM_TABULEIRO) return 0;
    if(colunaFinal < 0 || colunaFinal >= TAM_TABULEIRO) return 0;

    // Verifica sobreposição
    for(int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + i;
        int c = coluna + i * direcaoDiagonal;
        if(tabuleiro[l][c] == 3) return 0;
    }
    return 1;
}

// Posiciona navio na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcaoDiagonal) {
    for(int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i * direcaoDiagonal] = 3;
    }
}

// Imprime o tabuleiro formatado
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval (0=agua, 3=navio):\n\n");
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas fixas dos navios
    // Dois horizontais/verticais
    int linhaNavioH = 1, colunaNavioH = 1;
    int linhaNavioV = 4, colunaNavioV = 7;

    // Dois diagonais
    int linhaNavioD1 = 6, colunaNavioD1 = 2; // diagonal principal (\)
    int linhaNavioD2 = 0, colunaNavioD2 = 9; // diagonal inversa (/)

    // Posicionar navios horizontais/verticais
    if(podePosicionarNavioHV(tabuleiro, linhaNavioH, colunaNavioH, 'H')) {
        posicionarNavioHV(tabuleiro, linhaNavioH, colunaNavioH, 'H');
    } else {
        printf("Erro ao posicionar navio horizontal.\n");
    }

    if(podePosicionarNavioHV(tabuleiro, linhaNavioV, colunaNavioV, 'V')) {
        posicionarNavioHV(tabuleiro, linhaNavioV, colunaNavioV, 'V');
    } else {
        printf("Erro ao posicionar navio vertical.\n");
    }

    // Posicionar navios diagonais
    if(podePosicionarNavioDiagonal(tabuleiro, linhaNavioD1, colunaNavioD1, 1)) {
        posicionarNavioDiagonal(tabuleiro, linhaNavioD1, colunaNavioD1, 1);
    } else {
        printf("Erro ao posicionar navio diagonal principal.\n");
    }

    if(podePosicionarNavioDiagonal(tabuleiro, linhaNavioD2, colunaNavioD2, -1)) {
        posicionarNavioDiagonal(tabuleiro, linhaNavioD2, colunaNavioD2, -1);
    } else {
        printf("Erro ao posicionar navio diagonal inversa.\n");
    }

    imprimirTabuleiro(tabuleiro);

    return 0;
}