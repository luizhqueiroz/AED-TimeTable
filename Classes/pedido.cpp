#include "pedido.h"

Pedido::Pedido(int n) {
    estudante = nullptr;
    ucCodeOut = "";
    ucCodeIn = "";
    turmaOut = "";
    turmaIn = "";
    tipoPedido = n;
}

bool Pedido::fazerPedidoRemove(Bst &estudantes) {
    string nome;
    bool concluida = true;

    cout << "Digite o nome do aluno para o qual deseja a alteração:" << endl;
    cin >> nome;
    estudante = estudantes.searchName(nome);
    if (!estudante) concluida = false;

    cout << "Digite o código da unidade curricular que deseja remover:" << endl;
    cin >> ucCodeOut;

    cout << "Digite o código da turma em que o estudante se encontra:" << endl;
    cin >> turmaOut;

    if (concluida) cout << "Solicitação concluída." << endl;
    else cout << "Dados incorretos. Solicitação não pode ser realizada." << endl;

    return concluida;

}

bool Pedido::fazerPedidoAdiciona(Bst &estudantes) {
    string nome;
    bool concluida = true;

    cout << "Digite o nome do aluno para o qual deseja a alteração:" << endl;
    cin >> nome;
    estudante = estudantes.searchName(nome);
    if (!estudante) concluida = false;

    cout << "Digite o código da unidade curricular que deseja adicionar:" << endl;
    cin >> ucCodeOut;

    cout << "Digite o código da turma em que o estudante se encontra:" << endl;
    cin >> turmaOut;

    cout << "Digite o código da turma para a qual deseja cursar a unidade curricular:" << endl;
    cin >> turmaIn;

    if (concluida) cout << "Solicitação concluída." << endl;
    else cout << "Dados incorretos. Solicitação não pode ser realizada." << endl;

    return concluida;
}

bool Pedido::fazerPedidoAltera(Bst &estudantes) {
    string nome;
    bool concluida = true;

    cout << "Digite o nome do aluno para o qual deseja a alteração:" << endl;
    cin >> nome;
    estudante = estudantes.searchName(nome);
    if (!estudante) concluida = false;

    cout << "Digite o código da unidade curricular que deseja mudar:" << endl;
    cin >> ucCodeOut; // adicionar restrição para caso nao tenha essa uc

    cout << "Digite o código da turma em que o estudante se encontra:" << endl;
    cin >> turmaOut; // adicionar restrição para caso nao tenha essa turma

    cout << "Digite o código da turma para a qual deseja fazer a mudança:" << endl;
    cin >> turmaIn;// adicionar restrição para caso nao tenha essa turma

    if (concluida) cout << "Solicitação concluída." << endl;
    else cout << "Dados incorretos. Solicitação não pode ser realizada." << endl;

    return concluida;
}

bool Pedido::fazerPedidoAlteraConj(Bst &estudantes) {
    return false;
}

bstree_node* Pedido::getEstudante() {
    return estudante;
}

string Pedido::getUcCodeOut() const{
    return ucCodeOut;
}

string Pedido::getUcCodeIn() const{
    return ucCodeIn;
}

string Pedido::getTurmaOut() const{
    return turmaOut;
}

string Pedido::getTurmaIn() const{
    return turmaIn;
}

int Pedido::getTipoPedido() const {
    return tipoPedido;
}