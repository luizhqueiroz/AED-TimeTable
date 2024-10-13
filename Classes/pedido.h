/**
 * @file pedido.h
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream>
#include <string>
#include <queue>
#include <list>

#include "bst.h"


using namespace std;

class Pedido {

private:

    bstree_node* estudante;
    string ucCodeOut;
    string ucCodeIn;
    string turmaOut;
    string turmaIn;
    int tipoPedido;

public:

    Pedido(int n);
    bool fazerPedidoRemove(Bst &estudantes);
    bool fazerPedidoAdiciona(Bst &estudantes);
    bool fazerPedidoAltera(Bst &estudantes);
    bool fazerPedidoAlteraConj(Bst &estudantes);
    bstree_node* getEstudante();
    string getUcCodeOut() const;
    string getUcCodeIn() const;
    string getTurmaOut() const;
    string getTurmaIn() const;
    int getTipoPedido() const;
};

#endif
