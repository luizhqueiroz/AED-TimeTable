/**
 * @file bst.h
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <list>

#include "estudante.h"

using namespace std;

/**
 * @struct bstree_node
 * @brief Contém informações sobre um nó da Bst.
 */
struct bstree_node {
    Estudante est; /*!< Contém o valor do nó como sendo um estudante. */
    bstree_node *left = nullptr; /*!< Contém o ponteiro para o nó da esquerda. */
    bstree_node *right = nullptr; /*!< Contém o ponteiro para o nó da direita. */
    bstree_node *parent = nullptr; /*!< Contém o ponteiro para nó pai. */
};

/**
 * @class Bst
 * @brief Representa a bst de estudante.
 */
class Bst {
private:
    bstree_node *root; /*!< Contém o ponteiro para o nó raiz da árvore. */
    int size; /*!< Contém o número de estudantes na árvore. */
    /**
     * @brief Insere um novo nó a partir de outro nó qualquer.
     * @param new_node Contém o ponteiro para o novo nó.
     * @param node Contém o ponteiro para o nó a partir do qual será inserido o novo nó.
     */
    void insert(struct bstree_node *new_node, struct bstree_node *node);
    /**
     * @brief Procura pelo nó que terá o estudante de certo nome a partir de outro nó.
     * @param name Contém o nome do estudante procurado.
     * @param node Contém o ponteiro do nó a partir do qual será feita a procura.
     * @return Retorna um ponteiro para o nó que tenha o estudante com nome procurado ou um ponteiro nulo.
     */
    struct bstree_node* searchName(const string &name, struct bstree_node *node);
    /**
     * @brief Substitui um nó por outro nó.
     * @param source Contém o ponteiro para o nó que será substituído.
     * @param target Contém o ponteiro para o nó que será o substituto.
     */
    void splice(struct bstree_node *source, struct bstree_node *target);
    /**
     * @brief Destrói a árvore em uma abordagem InOrder.
     * @param node Contém o ponteiro para o nó base.
     */
    void destroy(struct bstree_node *node);

public:
    /**
     * @brief Construtor.
     */
    Bst();
    /**
     * @brief Destruidor.
     */
    ~Bst();
    /**
     * @brief Insere um novo estudante na árvore.
     * @param est Contém o estudante a ser inserido na árvore.
     */
    void insert(const Estudante &est);
    /**
     * @brief Procura pelo nó que terá o estudante de mesmo nome do procurado.
     * @param name Contém o nome do estudante a ser procurado na árvore.
     * @return Retorna um ponteiro para o nó que tenha o estudante com nome procurado ou um ponteiro nulo caso não encontre.
     */
    struct bstree_node* searchName(const string &name);
    /**
     * @brief Remove um estudante da árvore.
     * @param name Contém o nome do estudante a ser removido.
     * @return Retorna um bool que será true se o estudante for encontrado e falso caso contrário.
     */
    bool remove(const string &name);
    /**
     * @brief Pega o nó raiz da árvore.
     * @return Retorna um ponteiro para o nó raiz da árvore.
     */
    struct bstree_node* rootTree();
    /**
     * @brief Busca o estudante com nome de menor ordem alfabética.
     * @param tree_root Contém o ponteiro para o nó base da procura.
     * @return Retorna o ponteiro para o nó que tem o estudante com nome de menor ordem alfabética.
     */
    struct bstree_node* minimum(struct bstree_node *tree_root);
    /**
     * @brief Busca o estudante com nome de maior ordem alfabética.
     * @param tree_root Contém o ponteiro para o nó base da procura.
     * @return Retorna o ponteiro para o nó que tem o estudante com nome de maior ordem alfabética.
     */
    struct bstree_node* maximum(struct bstree_node *tree_root);
    /**
     * @brief Informa a quantidade de estudantes na árvore.
     * @return Retorna um inteiro que contém o valor da quantidade de estudantes na árvore.
     */
    int sizeTree() const;
    /**
     * @brief Informa se a árvore está vazia.
     * @return Retorna um bool que será true se a árvore estiver vazia e false caso contrário.
     */
    bool isEmpty() const;
    /**
     * @brief Imprime o nome dos estudantes na ordem de precedência a partir da raiz.
     * @param node Contém o ponteiro para o nó base.
     */
    void preOrder(bstree_node *node);
    /**
     * @brief Imprime os estudantes em ordem alfabética.
     * @param node Contém o ponteiro para o nó base.
     */
    void inOrder(bstree_node *node);
    /**
     * @brief Imprime o nome dos estudantes dando preferência para nós filhos antes de nós pais.
     * @param node Contém o ponteiro para o nó base.
     */
    void postOrder(bstree_node *node);
    /**
     * @brief Verifica os estudantes com mais de n unidades curriculares e imprime em ordem alfabética
     * @param node Contém o ponteiro para o nó base.
     * @param n Contém a quantidade de unidades curriculares que os estudantes precisam ter a mais.
     */
    void estudMaisNAlf(bstree_node* node, int n);
    /**
     * @brief Verifica os estudantes com mais de n unidades curriculares e adiciona numa lista em ordem decrescente de número de unidades curriculares
     * @param node Contém o ponteiro para o nó base.
     * @param n Contém a quantidade de unidades curriculares que os estudantes precisam estar cursando a mais.
     * @param estds Contém a lista de pair(estudante, número de unidades curriculares) que será preenchida em ordem decrescente de número de unidade curricular.
     */
    void estudMaisNUCs(bstree_node* node, int n, list<pair<Estudante,int>> &estds);

};

#endif
