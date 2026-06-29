#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inimigos.h"
#include "cores.h"

/* =============================================
   EXECUÇÃO DAS FUNÇÕES DE MANIPULAÇÃO DA HORDA
   =============================================*/ 

Horda* criarHorda() {
    
    Horda *horda = (Horda *)malloc(sizeof(Horda));

    if (horda == NULL) return NULL; // Correção: Tratamento de erro de memória

    horda -> comeco = NULL;
    horda -> fim = NULL;

    return horda;
}

void enfileirarInimigo(Horda *horda, char *nome, int vida, int dano) {

    // O 'malloc', constrói um espaço temporário na  memória RAM só para guardar a ficha do monstro.
    NoHorda *novoNo = (NoHorda *)malloc(sizeof(NoHorda)); //

    if (novoNo == NULL) return; // Correção: Tratamento de erro de memória

    strcpy(novoNo -> inimigo.nome, nome); // Chama a si mesmo

    novoNo -> inimigo.vida = vida;
    novoNo -> inimigo.dano = dano;
    novoNo -> proximo = NULL;

    // Se o monstro era o único que sobrava, a fila se esvazia completamente
    if (horda -> fim == NULL) {

        horda -> comeco = horda -> fim = novoNo;

    } else {

        horda -> fim -> proximo = novoNo;
        horda -> fim = novoNo;
    }
}

Inimigo* desenfileirarInimigo(Horda *horda) {

    NoHorda *noRemovido;
    Inimigo *inimigoMorto;

    if (horda -> comeco == NULL) {

        return NULL;
    }

    noRemovido = horda -> comeco;
    inimigoMorto = malloc(sizeof *inimigoMorto);

    if (inimigoMorto == NULL) return NULL; // Tratamento de erro de memória

    strcpy(inimigoMorto -> nome, noRemovido -> inimigo.nome);
    inimigoMorto -> vida = noRemovido -> inimigo.vida;
    inimigoMorto -> dano = noRemovido -> inimigo.dano;

    // O monstro que estava em segundo lugar é puxado para o primeiro
    horda -> comeco = horda -> comeco -> proximo;

    if (horda -> comeco == NULL) {

        horda -> fim = NULL;
    }

    free(noRemovido);

    return inimigoMorto;
}

int hordaVazia(Horda *horda) {

    return (horda -> comeco == NULL);
}

void exibirHorda(Horda *horda) {

    if (hordaVazia(horda)) {

        printf(COR_VERDE "=====================================================\n" COR_RESET);
        printf(COR_VERDE "|                     HORDA VAZIA                    |\n" COR_RESET);
        printf(COR_VERDE "=====================================================\n" COR_RESET);
        
    } else {

        NoHorda *atual = horda -> comeco;

        printf(COR_VERDE "==============================================================\n" COR_RESET);
        printf(COR_VERDE "|                     HORDA DE INIMIGOS                      |\n" COR_RESET);
        printf(COR_VERDE "==============================================================\n" COR_RESET);

        while (atual != NULL) {

            printf(COR_VERDE "| " COR_RESET "%-18s - Vida: %-4d - Dano: %-4d               " COR_VERDE "|\n" COR_RESET, atual -> inimigo.nome, atual -> inimigo.vida, atual -> inimigo.dano);
            atual = atual -> proximo;
        }

        printf(COR_VERDE "==============================================================\n" COR_RESET);
    }
}



