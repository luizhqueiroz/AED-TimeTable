/**
 * @file mudancaHorario.h
 */

#ifndef MUDANCAHORARIO_H
#define MUDANCAHORARIO_H

#include "estudante.h"
#include "turma.h"
#include "uc.h"
#include "pedido.h"



class MudancaHorario {
private:
    Bst estudantes;
    queue<Pedido> pedidos;

public:
    MudancaHorario();
    void inserirEstudantes(Bst &estudantes);
    void guardarPedidos(int n);
    void processarPedidos(list<Turma> &turmas, list<Uc> &UCs);
    void pedidosNaoSatisfeitos(const string &file);
};

#endif
