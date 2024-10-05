#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <fcntl.h>  // Para _setmode()
#include <io.h>     // Para _setmode()
#include <time.h>

void tabuleiro(int c[9][9], char opcao_borda);
void imprimir_campos(int campos[9][9]);
void limpar_tabuleiro();

int main() {
    // Inicializa variáveis e matriz
    int campos[9][9] = { // matriz campos
        {1, 2, 3, 4, 5, 6, 7, 8, 9},
        {2, 3, 4, 5, 6, 7, 8, 9, 1},
        {3, 4, 5, 6, 7, 8, 9, 1 ,2},
        {4, 5, 6, 7, 8, 9, 1, 2, 3},
        {5, 6, 7, 8, 9, 1, 2, 3, 4},
        {6, 7, 8, 9, 1, 2, 3, 4, 5},
        {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {9, 1, 2, 3, 4, 5, 6, 7, 8},
    };
    char opcao_borda = 'S';
    char player_entrada [2];
    // Definindo a localidade
    setlocale(LC_ALL, "");
    // Mudando o modo de saída para suportar UTF-8
    _setmode(_fileno(stdout), _O_U16TEXT);  // Habilita UTF-16 no Windows
    // Define a borda
    do {
        wprintf(L"Qual tipo de borda deseja? Simples = [S] | Dupla = [D]: ");
        scanf(" %c", &opcao_borda);
        if(opcao_borda == 'S' || opcao_borda == 's' || opcao_borda == 'D' || opcao_borda == 'd') {
            break;
        }
        else {
            wprintf(L"Entrada inválida! Tente novamente.\n");
        }
    } while(1);
    // Exibe o tabuleiro
    tabuleiro(campos, opcao_borda);
    printf("\n\n");
    //imprimir_campos(campos);
    // Fim do programa
    return 0;
}

void tabuleiro(int c[9][9], char opcao_borda) {
    int linha = 0;
    // Definindo os caracteres da borda
    wchar_t b_h, b_v, b_hv,
            b_ce, b_cd, b_cs, b_ci,
            b_cse, b_csd, b_cie, b_cid;
    // Definindo os caracteres da borda simples
    wchar_t b_simples_h = L'─', b_simples_v = L'│', b_simples_hv = L'┼',
            b_simples_ce = L'├', b_simples_cd = L'┤', b_simples_cs = L'┬', b_simples_ci = L'┴',
            b_simples_cse = L'┌', b_simples_csd = L'┐', b_simples_cie = L'└', b_simples_cid = L'┘';
    // Definindo os caracteres da borda duplas
    wchar_t b_dupla_h = L'═', b_dupla_v = L'║', b_dupla_hv = L'╬',
            b_dupla_ce = L'╠', b_dupla_cd = L'╣', b_dupla_cs = L'╦', b_dupla_ci = L'╩',
            b_dupla_cse = L'╔', b_dupla_csd = L'╗', b_dupla_cie = L'╚', b_dupla_cid = L'╝';
    // Definindo borda de escolha
    if(opcao_borda == 'S' || opcao_borda == 's') {
        b_h = b_simples_h; b_v = b_simples_v; b_hv = b_simples_hv;
        b_ce = b_simples_ce; b_cd = b_simples_cd; b_cs = b_simples_cs; b_ci = b_simples_ci;
        b_cse = b_simples_cse; b_csd = b_simples_csd; b_cie = b_simples_cie; b_cid = b_simples_cid;
    }
    else if (opcao_borda == 'D' || opcao_borda == 'd') {
        b_h = b_dupla_h; b_v = b_dupla_v; b_hv = b_dupla_hv;
        b_ce = b_dupla_ce; b_cd = b_dupla_cd; b_cs = b_dupla_cs; b_ci = b_dupla_ci;
        b_cse = b_dupla_cse; b_csd = b_dupla_csd; b_cie = b_dupla_cie; b_cid = b_dupla_cid;
    }
    // Imprimindo o tabuleiro no formato UTF-16
    for(int i = 0; i < 19; i++){
        if(i == 0) {
            wprintf(L"\n\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
                    b_cse, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h,
                    b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_csd);
        }
        if(i == 18) {
            wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
                    b_cie, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h,
                    b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_cid);
        }
        if(i % 2) {
            wprintf(L"\t%ld %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n", linha + 1,
                    b_v, ' ', c[linha][0], ' ', b_v, ' ', c[linha][1], ' ', b_v, ' ', c[linha][2], ' ', b_v, ' ', c[linha][3], ' ', b_v, ' ', c[linha][4], ' ',
                    b_v, ' ', c[linha][5], ' ', b_v, ' ', c[linha][6], ' ', b_v, ' ', c[linha][7], ' ', b_v, ' ', c[linha][8], ' ', b_v);
            linha++;
        }

        if(!(i % 2) && i != 0 && i != 18) {
            wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
                    b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
                    b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);
        }
    }

    /*
    wprintf(L"\n\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_cse, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h,
        b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_cs, b_h, b_h, b_h, b_csd);

    wprintf(L"\t9 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[0][0], ' ', b_v, ' ', c[0][1], ' ', b_v, ' ', c[0][2], ' ', b_v, ' ', c[0][3], ' ', b_v, ' ', c[0][4], ' ',
        b_v, ' ', c[0][5], ' ', b_v, ' ', c[0][6], ' ', b_v, ' ', c[0][7], ' ', b_v, ' ', c[0][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t8 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[1][0], ' ', b_v, ' ', c[1][1], ' ', b_v, ' ', c[1][2], ' ', b_v, ' ', c[1][3], ' ', b_v, ' ', c[1][4], ' ',
        b_v, ' ', c[1][5], ' ', b_v, ' ', c[1][6], ' ', b_v, ' ', c[1][7], ' ', b_v, ' ', c[1][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t7 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[2][0], ' ', b_v, ' ', c[2][1], ' ', b_v, ' ', c[2][2], ' ', b_v, ' ', c[2][3], ' ', b_v, ' ', c[2][4], ' ',
        b_v, ' ', c[2][5], ' ', b_v, ' ', c[2][6], ' ', b_v, ' ', c[2][7], ' ', b_v, ' ', c[2][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t6 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[3][0], ' ', b_v, ' ', c[3][1], ' ', b_v, ' ', c[3][2], ' ', b_v, ' ', c[3][3], ' ', b_v, ' ', c[3][4], ' ',
        b_v, ' ', c[3][5], ' ', b_v, ' ', c[3][6], ' ', b_v, ' ', c[3][7], ' ', b_v, ' ', c[3][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t5 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[4][0], ' ', b_v, ' ', c[4][1], ' ', b_v, ' ', c[4][2], ' ', b_v, ' ', c[4][3], ' ', b_v, ' ', c[4][4], ' ',
        b_v, ' ', c[4][5], ' ', b_v, ' ', c[4][6], ' ', b_v, ' ', c[4][7], ' ', b_v, ' ', c[4][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t4 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[5][0], ' ', b_v, ' ', c[5][1], ' ', b_v, ' ', c[5][2], ' ', b_v, ' ', c[5][3], ' ', b_v, ' ', c[5][4], ' ',
        b_v, ' ', c[5][5], ' ', b_v, ' ', c[5][6], ' ', b_v, ' ', c[5][7], ' ', b_v, ' ', c[5][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t3 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[6][0], ' ', b_v, ' ', c[6][1], ' ', b_v, ' ', c[6][2], ' ', b_v, ' ', c[6][3], ' ', b_v, ' ', c[6][4], ' ',
        b_v, ' ', c[6][5], ' ', b_v, ' ', c[6][6], ' ', b_v, ' ', c[6][7], ' ', b_v, ' ', c[6][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t2 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[7][0], ' ', b_v, ' ', c[7][1], ' ', b_v, ' ', c[7][2], ' ', b_v, ' ', c[7][3], ' ', b_v, ' ', c[7][4], ' ',
        b_v, ' ', c[7][5], ' ', b_v, ' ', c[7][6], ' ', b_v, ' ', c[7][7], ' ', b_v, ' ', c[7][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_ce, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h,
        b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_hv, b_h, b_h, b_h, b_cd);

    wprintf(L"\t1 %lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc%lc%ld%lc%lc\n",
        b_v, ' ', c[8][0], ' ', b_v, ' ', c[8][1], ' ', b_v, ' ', c[8][2], ' ', b_v, ' ', c[8][3], ' ', b_v, ' ', c[8][4], ' ',
        b_v, ' ', c[8][5], ' ', b_v, ' ', c[8][6], ' ', b_v, ' ', c[8][7], ' ', b_v, ' ', c[8][8], ' ', b_v);

    wprintf(L"\t  %lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc%lc\n",
        b_cie, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h,
        b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_ci, b_h, b_h, b_h, b_cid);
*/
    wprintf(L"\t    a   b   c   d   e   f   g   h   i \n");
}

void imprimir_campos(int campos[9][9]) {
    wprintf(L"\n\t");
    for(int linha = 0; linha < 9; linha++) {
        for(int coluna = 0; coluna < 9; coluna++) {
            wprintf(L" %d ", campos[linha][coluna]);
        }
        wprintf(L"\n\t");
    }
}

void limpar_tabuleiro() {
    system("cls");
}




