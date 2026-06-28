#ifndef INIMIGOS_H
#define INIMIGOS_H
#include "cores.h"

/* =======================================================
         FILA (ESTRUTURA DA HORDA DE INIMIGOS)
  ========================================================*/

typedef struct Inimigo {
    
    char nome[50];
    int vida;
    int dano;

} Inimigo;

 /*
A estrutura 'NoHorda' representa um nó na lista encadeada de inimigos. 
Cada nó possui um inimigo e um ponteiro para o próximo nó na lista. 
A estrutura é usada para criar uma horda de inimigos, permitindo a adição e remoção de inimigos de forma dinâmica.
*/
typedef struct NoHorda {

    Inimigo inimigo;
    struct NoHorda *proximo;

} NoHorda;

// Controla a fila, do primeiro até o último inimigo
typedef struct Horda {

    NoHorda *comeco; // os monstros saem para a batalha
    NoHorda *fim; // Os montros novos entram para batalhar

} Horda;

Horda* criarHorda();

void enfileirarInimigo(Horda *horda, char *nome, int vida, int dano); 
Inimigo* desenfileirarInimigo(Horda *horda);

void exibirHorda(Horda *horda);
int hordaVazia(Horda *horda);

#endif
