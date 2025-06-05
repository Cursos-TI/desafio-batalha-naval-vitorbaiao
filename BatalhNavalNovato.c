#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função para inicializar o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for(int i = 0; i < TAM_TABULEIRO; i++) {
        for(int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para verificar se um navio pode ser colocado no tabuleiro (sem sair dos limites e sem sobrepor)
int podePosicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    // orientacao: 'H' para horizontal, 'V' para vertical

    if(orientacao == 'H') {
        if(coluna + TAM_NAVIO > TAM_TABULEIRO) return 0; // Passou do limite horizontal
        // Verifica se já tem navio no caminho
        for(int c = coluna; c < coluna + TAM_NAVIO; c++) {
            if(tabuleiro[linha][c] == 3) return 0;  // Já tem navio
        }
    } else if(orientacao == 'V') {
        if(linha + TAM_NAVIO > TAM_TABULEIRO) return 0; // Passou do limite vertical
        // Verifica se já tem navio no caminho
        for(int l = linha; l < linha + TAM_NAVIO; l++) {
            if(tabuleiro[l][coluna] == 3) return 0;  // Já tem navio
        }
    } else {
        return 0; // Orientação inválida
    }

    return 1; // Pode posicionar
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, char orientacao) {
    if(orientacao == 'H') {
        for(int c = coluna; c < coluna + TAM_NAVIO; c++) {
            tabuleiro[linha][c] = 3;  // 3 representa navio
        }
    } else if(orientacao == 'V') {
        for(int l = linha; l < linha + TAM_NAVIO; l++) {
            tabuleiro[l][coluna] = 3;
        }
    }
}

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval (0=água, 3=navio):\n\n");
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

    // Definindo coordenadas fixas para os navios (linha, coluna)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

    // Tentar posicionar navio horizontal
    if(podePosicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, 'H')) {
        posicionarNavio(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal, 'H');
    } else {
        printf("Erro: nao foi possivel posicionar o navio horizontal nessas coordenadas.\n");
    }

    // Tentar posicionar navio vertical
    if(podePosicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, 'V')) {
        posicionarNavio(tabuleiro, linhaNavioVertical, colunaNavioVertical, 'V');
    } else {
        printf("Erro: nao foi possivel posicionar o navio vertical nessas coordenadas.\n");
    }

    // Exibir o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}