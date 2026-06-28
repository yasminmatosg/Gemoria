#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mochila.h"
#include "cores.h"


/* ===============================================
   EXECUÇÃO DAS FUNÇÕES DE MANIPULAÇÃO DA MOCHILA
   ===============================================*/ 

No *buscarItem(No *inicio, char *nome) {
    /*
    Adicionamos um ponteiro auxiliar para percorrer a lista, sem prejuducar a estrutura original da mochila.
    Isso permite que a função busque o item desejado sem modificar a lista.
    */
    No *atual = inicio;

    while (atual != NULL){

        if (strcmp(atual -> item.nome, nome) == 0) { // O String Compare foi utilizado para comparar o nome do item atual com o nome fornecido como parâmetro
            
            return atual;
        }
        
        atual = atual -> proximo; // Avança para o próximo nó, caso o item procurado não seja encontrado no nó atual
    }

    return NULL; // Retorna NULL se o item não for encontrado
}

No* adicionarItem(No *inicio, char *nome, int quantidade) {
    
    if (quantidade <= 0) {
       
        return inicio;
    }

    No *item_existente = buscarItem(inicio, nome);
        
        if (item_existente != NULL) {
            
            item_existente -> item.quantidade += quantidade; // soma a quantidade que ela já possui com a quatidade que ela adquiriu a mais
            
            return inicio;
        }
        
        No *novo_no = (No *)malloc(sizeof(No)); // O Malloc reserva um espaço na memória RAM suficiente para armazenar um novo nó da lista.
        
        if (novo_no == NULL) {

            return inicio;
        }

        // caso a mochila esteja vazia, o novo item será o primeiro da lista
        strcpy(novo_no -> item.nome, nome);

        novo_no -> item.quantidade = quantidade;
        novo_no -> proximo = NULL;

        if (inicio == NULL) {

            return novo_no; // Retorna o novo nó como início da lista
        }
        // caso já tenha itens na mochila, o novo item será adicionado no final da lista
        No *atual = inicio;
        
        while (atual -> proximo != NULL) {
            
            atual = atual -> proximo;
        }
        
        atual -> proximo = novo_no;
        return inicio; // Retorna o início da lista, que permanece inalterado
    }

    No* removerItem(No *inicio, char *nome, int quantidade) {

        if (quantidade <= 0)

        return inicio;

        No *atual = inicio;
        No *anterior = NULL;

        while (atual != NULL && strcmp(atual->item.nome, nome) != 0) {

            anterior = atual;
            atual = atual -> proximo;
        }

        if (atual == NULL)
        
        return inicio;

        atual -> item.quantidade -= quantidade;

        if (atual -> item.quantidade <= 0) {

            if (anterior == NULL) {

                inicio = atual -> proximo; // O primeiro item da mochila vira o próximo

            } else {

                anterior -> proximo = atual -> proximo;
            }

            free(atual); // Utilizamos o free para fazer a limpeza de memória
        }

        return inicio;
    }

    No* iniciarMochila() {

        No *mochila = NULL; // Inicializa a mochila vazia e adiciona o item inicial

        mochila = adicionarItem(mochila, "Tocha", 1);
        mochila = adicionarItem(mochila, "Fruta", 5);

        return mochila;
    }

    void exibirMochila(No *inicio) {

        No* atual = inicio;
        
        printf(COR_MAGENTA "\n=====================================================\n" COR_RESET);
        printf(COR_MAGENTA "|                      MOCHILA                      |\n" COR_RESET);
        printf(COR_MAGENTA "=====================================================\n" COR_RESET);

        if (atual == NULL) {
            
            printf(COR_MAGENTA "|               A mochila vazia!                   |\n" COR_RESET);

        } else {

        while (atual != NULL) {

            printf(COR_MAGENTA "| " COR_RESET "%-15s - Quantidade: %-5d               " COR_MAGENTA "|\n" COR_RESET, atual -> item.nome, atual -> item.quantidade);
           
            atual = atual -> proximo;
        }
    }

       printf(COR_MAGENTA "=====================================================\n" COR_RESET);
}
