#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}
void conectarSalas(Sala *sala, Sala *esq, Sala *dir) {
    sala->esq = esq;
    sala->dir = dir;
}
void explorarSalas(Sala *atual) {
    char opcao;

    while (1) {
        printf("\n📍 Você está na sala: **%s**\n", atual->nome);
        printf("Para onde deseja ir?\n");
        printf("  (e) Ir para a sala da ESQUERDA\n");
        printf("  (d) Ir para a sala da DIREITA\n");
        printf("  (s) Sair da exploração\n");
        printf("> ");
        scanf(" %c", &opcao);

        if (opcao == 's') {
            printf("\n🧭 Você decidiu sair da exploração.\n");
            break;
        }
        else if (opcao == 'e') {
            if (atual->esq != NULL) {
                atual = atual->esq;
            } else {
                printf("❌ Não há sala à esquerda!\n");
            }
        }
        else if (opcao == 'd') {
            if (atual->dir != NULL) {
                atual = atual->dir;
            } else {
                printf("❌ Não há sala à direita!\n");
            }
        }
        else {
            printf("⚠ Opção inválida!\n");
        }
    }
}

int main() {
printf("🔎 Bem-vindo ao Detective Quest – Nível Novato!\n");
Sala *hall       = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha    = criarSala("Cozinha");
    Sala *salaJantar = criarSala("Sala de Jantar");
    Sala *sotao      = criarSala("Sótão");
    Sala *dispensa   = criarSala("Dispensa");

    // Conectando (árvore binária fixa)
    //             Hall
    //       /              \
    // Biblioteca          Cozinha
    //     /  \            /     \
    // Sótão SalaJantar Dispensa NULL

    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, salaJantar);
    conectarSalas(cozinha, dispensa, NULL);

    printf("🔎 Bem-vindo ao Detective Quest – Nível Novato!\n");
    explorarSalas(hall);

    // 🌱 Nível Novato: Mapa da Mansão com Árvore Binária
    //
    // - Crie uma struct Sala com nome, e dois ponteiros: esquerda e direita.
    // - Use funções como criarSala(), conectarSalas() e explorarSalas().
    // - A árvore pode ser fixa: Hall de Entrada, Biblioteca, Cozinha, Sótão etc.
    // - O jogador deve poder explorar indo à esquerda (e) ou à direita (d).
    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

    return 0;
}

