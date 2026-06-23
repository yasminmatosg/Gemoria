# GEMORIA - O Resgate do Cristal 🗡️💎

Projeto final desenvolvido para a disciplina de Estrutura de Dados do curso de Sistemas de Informação (3º semestre) do Centro Universitário Unieuro.

Trata-se de um RPG de terminal (*Dungeon Crawler*) construído 100% em linguagem C pura (programação estruturada). O sistema foca em alocação dinâmica de memória, otimização de recursos e manipulação direta de ponteiros, rodando com extrema fluidez e eficiência.

## 🔗 Arquitetura e Estruturas de Dados

A arquitetura do jogo foi desenhada para justificar a aplicação prática de seis estruturas de dados fundamentais:

* **Árvore Binária:** Mapeamento do labirinto (salas 01 a 17), onde cada nó possui ponteiros para os caminhos da `esquerda` e `direita`.
* **Pilha (Stack):** Sistema de rastro e navegação. A cada nova sala, a posição anterior sofre um `push`, permitindo o retorno seguro através de um `pop` ao encontrar becos sem saída.
* **Lista Simplesmente Encadeada:** Gerenciamento do inventário e mochila da guerreira, diferenciando itens-chave e consumíveis.
* **Fila (Queue):** Sistema de hordas de inimigos. Os monstros são enfileirados por sala e removidos (`dequeue`) conforme são derrotados na ordem de chegada.
* **Lista Circular:** Motor principal do sistema de batalha, garantindo o loop contínuo e ordenado dos turnos entre a personagem e os inimigos.
* **Lista Duplamente Encadeada:** Implementação do diário de anotações e *lore* do jogo, permitindo avanço e retrocesso bidirecional nas páginas de dicas.

## </> Como Compilar e Executar

O projeto não possui dependências externas além das bibliotecas padrão do C (`stdio.h`, `stdlib.h`, `string.h`).

1. Clone este repositório:
   ```bash
   git clone [https://github.com/SEU_USUARIO/o-resgate-do-cristal.git](https://github.com/SEU_USUARIO/o-resgate-do-cristal.git)

2. Navegue até a pasta do projeto e compile os arquivos integrados:
   ```bash
   gcc main.c exploracao_mapa.c combate_inventario.c -o resgate_cristal

3. Execute o jogo:
   ```bash
   ./resgate_cristal

## 𐀪𐀪 Autoras
Yasmin Matos - Módulo de Combate e Inventário

Maria Luisa - Módulo de Exploração, Mapa e Navegação
