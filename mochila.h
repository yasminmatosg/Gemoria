#ifndef MOCHILA_H
#define MOCHILA_H

/* ===================================
   LISTA SIMPLES (ESTRUTURA DA MOCHILA)
  ===================================*/


// Definição dos itens presentes na mochila
typedef struct Item {
    
    char nome[100];
    int quantidade;
    /*
    Os itens foram declarados de forma genérica para que ao longo do jogo,
    novos itens possam ser adicionados sem a necessidade de alterar a estrutura do código.
    */
} Item;

// Definição da estrutura de nó da lista simples
typedef struct No {
   
    Item item;
    struct No *proximo;
    
} No;

No* iniciarMochila();

// Declaração das funções para a manipulação da mochila 
No* adicionarItem(No *inicio, char *nome, int quantidade);

No* removerItem(No *inicio, char *nome, int quantidade);

No* buscarItem(No *inicio, char *nome);

void exibirMochila(No *inicio);

#endif