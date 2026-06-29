#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turnos.h"
#include "cores.h"

/* ================================================
   EXECUÇÃO DAS FUNÇÕES DE MANIPULAÇÃO DOS COMBATES
   ================================================*/ 

Combatentes* iniciarCombatentes() {

    //O 'malloc' foi utilizado para alocar espaço na memória RAM, para controlar a roda de combatentes
    Combatentes *combatentes = (Combatentes *)malloc(sizeof(Combatentes));
    if (combatentes == NULL) return NULL; // Correção: Tratamento de erro de memória
    
    combatentes -> inicio = NULL;
}

// Aloca os combatentes no círculo de combate
void inserirCombatente(Combatentes *combatentes, char *nome, char *frase, int vida, int dano, int nivel) {

    //O 'sizeof', foi utilizado para fazer a contagem dos bytes
    NoCombatente *novoCombatente = (NoCombatente *)malloc(sizeof(NoCombatente));

    strcpy(novoCombatente -> nome, nome);
    strcpy(novoCombatente -> frase, frase); // Copia a frase para o novo combatente

    novoCombatente -> vida = vida;
    novoCombatente -> dano = dano;
    novoCombatente -> nivel = nivel;
    novoCombatente -> proximo = combatentes->inicio;

    if (combatentes -> inicio == NULL) {

        novoCombatente -> proximo = novoCombatente; // Aponta para si mesmo, formando um ciclo
        combatentes -> inicio = novoCombatente;

    } else {

        NoCombatente *atual = combatentes->inicio;

        // É necesário percorrer a lista inteira, até o último combatente
        while (atual -> proximo != combatentes->inicio) {

            atual = atual -> proximo;
        }
       // Quem era o último, passa a apontar para o novo combatente 
        atual -> proximo = novoCombatente;
        // Para evitar a quebra do ciclo, o novo combatente deve apontar novamente para o principal
        novoCombatente -> proximo = combatentes -> inicio;
        
        printf(COR_VERDE "==========================================\n");
        printf("| Combatente inserido: %-18s |\n", novoCombatente->nome);
        printf("==========================================\n" COR_RESET);
    }

    combatentes -> tamanho++;
}

int removerCombatente(Combatentes *combatentes, char *nome) {

    if (combatentes -> inicio == NULL) {

        return 0; // Lista vazia, nada a remover
    }
        NoCombatente *atual = combatentes -> inicio;
        NoCombatente *anterior = NULL;
        
        int encontrado = 0;

        // Procuramos o nome do inimigo derrotado
        do{

           if (strcmp(atual->nome, nome) == 0) {
                encontrado = 1;
                break;
            }

            anterior = atual;
            atual = atual -> proximo;

        } while (atual != combatentes -> inicio);

        if (encontrado) {

            if (anterior == NULL) { // Removendo o primeiro combatente

                if (atual->proximo == atual) { // Apenas um combatente na lista
                    combatentes -> inicio = NULL;
                } else {

                    NoCombatente *ultimo = combatentes -> inicio;

                    while (ultimo -> proximo != combatentes->inicio) {
                        ultimo = ultimo -> proximo;
                    }

                    ultimo->proximo = atual -> proximo; // o último combatente pula o combatente derrotado e passa para o próximo da lista que esteja vivo
                    combatentes->inicio = atual -> proximo;
                }

            } else { // Removendo um combatente que não é o primeiro

                anterior -> proximo = atual -> proximo;
            }

            free(atual);
            combatentes -> tamanho--;

            return 1; // Combatente removido com sucesso
        }

    return 0; // Combatente não encontrado
}

NoCombatente* buscarCombatente(Combatentes *combatentes, char *nome) {

    if (combatentes -> inicio == NULL) {

        return NULL; // Lista vazia, nada a buscar
    }

    NoCombatente *atual = combatentes -> inicio;

    do {
        
        if (strcmp(atual -> nome, nome) == 0) {

            return atual; // Combatente encontrado
        }

        atual = atual -> proximo;

    } while (atual != combatentes -> inicio);

    return NULL; // Combatente não encontrado
}

int combatentesVazios(Combatentes *atual) {

    return (atual -> inicio == NULL);
}

void exibirCombatentes(Combatentes *combatentes) {

    if (combatentesVazios(combatentes)) {
        
        printf(COR_VERMELHA "=====================================================\n" COR_RESET);
        printf(COR_VERMELHA "|                 ARENA VAZIA                       |\n" COR_RESET);
        printf(COR_VERMELHA "=====================================================\n" COR_RESET);

    } else {

        NoCombatente *atual = combatentes -> inicio;

        printf(COR_VERDE "=====================================================\n" COR_RESET);
        printf(COR_VERDE "|                  LISTA DE COMBATENTES              |\n" COR_RESET);
        printf(COR_VERDE "=====================================================\n" COR_RESET);

        do {

            printf(COR_VERDE "| " COR_RESET "%-12s - Vida: %-3d - Dano: %-3d - Nivel: %-4d" COR_VERDE "|\n" COR_RESET, atual -> nome, atual -> vida, atual -> dano, atual -> nivel);
            atual = atual -> proximo;

        } while (atual != combatentes -> inicio);

        printf(COR_VERDE "=====================================================\n" COR_RESET);
    }
}