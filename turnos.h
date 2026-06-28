#ifndef TURNOS_H
#define TURNOS_H

/* ===============================================
   LISTA CIRCULAR (ESTRUTURA DOS TURNOS DE BATALHA)
  ================================================*/

typedef struct NoCombatente {

    char nome[50];
    char frase[100];
    int vida;
    int dano;
    int nivel;
    int efeito; // 0 = normal, 1 = veneno, 2 = hipnose, 3 = amarrado, 4 = gelo

    struct NoCombatente *proximo;

} NoCombatente;

 /*
A estrutura 'NoCombate' representa um nó na lista circular dos turnos. 
A estrutura é usada para criar o turno das batalhas, permitindo a adição e remoção delas de forma dinâmica.
*/

typedef struct Combatentes {

    NoCombatente *inicio;

    int tamanho;

} Combatentes;

Combatentes* iniciarCombatentes();

void inserirCombatente(Combatentes *combatentes, char *nome, char *frase, int vida, int dano, int nivel);
int removerCombatente(Combatentes *combatentes, char *nome);

NoCombatente* buscarCombatente(Combatentes *combatentes, char *nome);
void exibirCombatentes(Combatentes *combatentes);
int combatentesVazios(Combatentes *atual);

#endif
