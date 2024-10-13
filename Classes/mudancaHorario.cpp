#include "mudancaHorario.h"

MudancaHorario::MudancaHorario() {
    this->estudantes = {};
    pedidos = {};
}

void MudancaHorario::inserirEstudantes(Bst &estudantes) {
    this->estudantes = estudantes;
}

void MudancaHorario::guardarPedidos(int n) {
    Pedido pedido = Pedido(n);

    switch (n) {
        case 1:
            if(pedido.fazerPedidoRemove(estudantes)) pedidos.push(pedido);
            break;

        case 2:
            if (pedido.fazerPedidoAdiciona(estudantes)) pedidos.push(pedido);
            break;

        case 3:
            if (pedido.fazerPedidoAltera(estudantes)) pedidos.push(pedido);
            break;

        case 4:
            if (pedido.fazerPedidoAlteraConj(estudantes)) pedidos.push(pedido);
            break;
    }
}

void MudancaHorario::processarPedidos(list<Turma> &turmas, list<Uc> &UCs) {
    //ler a fila com os pedidos e analisar se pode processar, se nao puder, guarda os pedidos num arquivo.


    while (!pedidos.empty()) {
        Pedido pedido = pedidos.front();
        pedidos.pop();

        switch (pedido.getTipoPedido()) {
            case 1:
                for (auto it = UCs.begin(); it != UCs.end(); it++) {
                    if (it->getUcCode() == pedido.getUcCodeOut()) {
                        auto iter = it->findClass(pedido.getTurmaOut());
                        if (iter != it->classesEnd()) {
                            pair<string,string> estud = make_pair(pedido.getEstudante()->est.getName(),pedido.getEstudante()->est.getStudentCode());
                            if (iter->removeEstudante(estud)){
                                pedido.getEstudante()->est.getHorario().removeAula(pedido.getUcCodeOut());
                                for (auto it2 = turmas.end(); it2 != turmas.end(); it2++) {
                                    if (it2->getClassCode() == pedido.getTurmaOut()) it2->removeEstudante(estud);
                                }
                            } else pedidosNaoSatisfeitos("PedidosNaoSatisfeitos");
                        }
                    }
                }
                break;

            case 2:


                break;

            case 3:



                break;


            case 4:


                break;

        }
    }
}

void MudancaHorario::pedidosNaoSatisfeitos(const string &file) {
    //guardar os pedidos nao satisfeitos no arquivo de nome file.
}