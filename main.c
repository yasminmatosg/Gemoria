#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mochila.h"
#include "inimigos.h"
#include "turnos.h"
#include "cores.h"

/*
 * ======================================================================================
 * PROJETO: Gemoria - MECANISMOS E INTEGRAÇÃO DO SISTEMA
 * ======================================================================================
 * Desenvolvedoras: Yasmin Gomes & Maria Luiza
 * * Linguagem: C (Padrão C17)
 * * Estruturas de Dados:
 * - Lista Linear (Mochila) - Gerenciamento de Itens
 * - Fila (Horda) - Gestão de Inimigos
 * - Lista Circular (Arena de Batalha) - Sistema de Turnos
 * * GUIA DE INTEGRAÇÃO (Como conectar as estruturas de dados):
 * * 1. MOCHILA (Lista Linear - Gerenciamento de Itens):
 * - Use: adicionarItem(No *inicio, char *nome, int qtd)
 * - Use: removerItem(No *inicio, char *nome, int qtd)
 * - Use: buscarItem(No *inicio, char *nome) para verificar requisitos de puzzles.
 * * 2. HORDA (Fila - Gestão de Inimigos):
 * - Use: enfileirarInimigo(Horda *horda, char *nome, int vida, int dano)
 * - Use: desenfileirarInimigo(Horda *horda) para mover inimigos para a Arena.
 * * 3. ARENA DE BATALHA (Lista Circular - Sistema de Turnos):
 * - Use: inserirCombatente(Combatentes *batalha, char *nome, char *frase, int v, int d, int n)
 * - Use: removerCombatente(Combatentes *batalha, char *nome) após derrotar o monstro.
 * - O sistema está pronto para processar o ciclo de combate e ações especiais.
 * * NOTA: O motor do jogo foi construído de forma modular. Para integrar a Árvore Binária 
 * (Mapa) e a Pilha (Caminho de Volta), basta chamar as funções acima dentro dos 
 * nós das suas respectivas estruturas.
 * ======================================================================================
 */


 void recompensas(char *nomeMosntro, No *mochila) {
    
    printf(COR_VERDE "=====================================================\n" COR_RESET);
    printf(COR_VERDE "|                 INIMIGO DERROTADO!                |\n" COR_RESET);
    printf(COR_VERDE "=====================================================\n" COR_RESET);
    printf(COR_AZUL "|              Nova sala desbloqueada!              |\n" COR_RESET);
    printf(COR_AZUL "=====================================================\n" COR_RESET);


    if (strcmp(nomeMosntro, "Ninho de Morcegos") == 0) {

        printf(COR_VERDE "| Caminho liberado para a sala 04!                  |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Esqueletos") == 0) {

        printf(COR_VERDE "| Caminho liberado para a sala 07!                  |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Gibbering Mouther") == 0) {

        printf(COR_VERDE "| Caminho liberado para a sala 09!                  |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Aranha Gigante") == 0) {

        adicionarItem(mochila, "Escudo", 1);
        adicionarItem(mochila, "Dinheiro!", 50);

        printf(COR_VERDE "| Voce ganhou um Escudo e 50 moedas de ouro!        |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "goblim") == 0) {
        
        adicionarItem(mochila, "Anel de GELO", 1);

        printf(COR_VERDE "| Voce ganhou um Anel de Gelo!                      |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Ogro") == 0) {
        
        adicionarItem(mochila, "Corda", 1);
        adicionarItem(mochila, "Poção de Vida", 1);
        adicionarItem(mochila, "Dinheiro!", 100);
        printf(COR_VERDE "| Ganhou Corda, Pocao e 100 moedas de ouro!         |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Urso-Coruja") == 0) {

        adicionarItem(mochila, "Poção de vida", 1);
        printf(COR_VERDE "| Voce ganhou uma pocao de vida!                |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Vampiro") == 0) {

        adicionarItem(mochila, "Dinheiro!", 300);
        printf(COR_VERDE "| Voc ganhou 300 moedas de ouro!                |\n" COR_RESET);

    } else if (strcmp(nomeMosntro, "Dragao") == 0) {

        printf(COR_AMARELA "=====================================================\n" COR_RESET);
        printf(COR_AMARELA "|     VOCE CONSEGUIU O CRISTAL E VENCEU O JOGO!     |\n" COR_RESET);
        printf(COR_AMARELA "=====================================================\n" COR_RESET);

   }

}

void carregarDesafios(Horda *horda) {

    enfileirarInimigo(horda, "Ninho de Morcegos", 50, 15);
    enfileirarInimigo(horda, "Esqueletos", 80, 20);
    enfileirarInimigo(horda, "Gibbering Mouther", 120, 30);
    enfileirarInimigo(horda, "Aranha Gigante", 40, 10);
    enfileirarInimigo(horda, "goblim", 150, 25);
    enfileirarInimigo(horda, "Ogro", 700, 100);
    enfileirarInimigo(horda, "Vampiro", 300, 50);
    enfileirarInimigo(horda, "Urso-Coruja", 200, 30);
    enfileirarInimigo(horda, "Dragao", 1000, 200);

}

int main() {

    // 1. Inicia o jogo e carrega os itens iniciais
    No *mochila = iniciarMochila();
    Horda *horda = criarHorda();
    Combatentes *combatentes = iniciarCombatentes();
    
    carregarDesafios(horda);
    inserirCombatente(combatentes, "Guerreira", "Vamos lá!", 100, 20, 1);

    int opcao, iniciado = 1;

    while (iniciado) {

        printf(COR_CIANO "\n=====================================================\n" COR_RESET);
        printf(COR_CIANO "|                   MENU INICIAL                    |\n" COR_RESET);
        printf(COR_CIANO "=====================================================\n" COR_RESET);
        printf(COR_CIANO "| 1. Exibir Mochila                                 |\n" COR_RESET);
        printf(COR_CIANO "| 2. Ver Proximo Inimigo (Horda)                    |\n" COR_RESET);
        printf(COR_CIANO "| 3. Puxar Inimigo para Arena                       |\n" COR_RESET);
        printf(COR_CIANO "| 4. Exibir Arena de Combate                        |\n" COR_RESET);
        printf(COR_CIANO "| 5. Derrotar Inimigo Atual                         |\n" COR_RESET);
        printf(COR_CIANO "| 6. Sair                                           |\n" COR_RESET);
        printf(COR_CIANO "=====================================================\n" COR_RESET);
        scanf("%d", &opcao);

        // Pausa a tela para a jogador(a) conseguir ler o que aconteceu
        if (iniciado) {
            printf("\n");
        }

        switch (opcao) {

            case 1:
                exibirMochila(mochila);
                break;

            case 2:
                exibirHorda(horda);
                break;

            case 3:
                if (!hordaVazia(horda)) {
                    
                    Inimigo *inimigo = desenfileirarInimigo(horda);
                    inserirCombatente(combatentes, inimigo->nome, "Se prepare!", inimigo->vida, inimigo->dano, 1);
                    
                    printf(COR_VERMELHA "\n=====================================================\n" COR_RESET);
                    printf(COR_VERMELHA "| " COR_RESET "%-15s entrou na Arena de Combate!    " COR_VERMELHA "|\n" COR_RESET, inimigo->nome);
                    printf(COR_VERMELHA "=====================================================\n" COR_RESET);    
                
                    free(inimigo);
                } else {

                    printf(COR_VERMELHA "=====================================================\n" COR_RESET);
                    printf(COR_VERMELHA "|                 NENHUM INIMIGO NA HORDA           |\n" COR_RESET);
                    printf(COR_VERMELHA "=====================================================\n" COR_RESET);
                }
                break;

            case 4:
                exibirCombatentes(combatentes);
                break;

            case 5:
                if (!combatentesVazios(combatentes) && !hordaVazia(horda)) {

                    char nomeInimigo[50];

                    strcpy(nomeInimigo, combatentes->inicio->nome);

                    if (removerCombatente(combatentes, nomeInimigo)) {

                        recompensas(nomeInimigo, mochila);

                    } else {

                        printf(COR_VERMELHA "=====================================================\n" COR_RESET);
                        printf(COR_VERMELHA "|           NENHUM INIMIGO PARA DERROTAR!           |\n" COR_RESET);
                        printf(COR_VERMELHA "=====================================================\n" COR_RESET);
                    }
                }
                    break;

                case 6:
                iniciado = 0;
                printf(COR_AMARELA "=====================================================\n" COR_RESET);
                printf(COR_AMARELA "|                 SAINDO DO JOGO                    |\n" COR_RESET);
                printf(COR_AMARELA "=====================================================\n" COR_RESET);
                break;

                default:
                printf(COR_VERMELHA "=====================================================\n" COR_RESET);
                printf(COR_VERMELHA "|                 OPÇÃO INVÁLIDA                   |\n" COR_RESET);
                printf(COR_VERMELHA "=====================================================\n" COR_RESET);
        }
    }

    return 0;
}