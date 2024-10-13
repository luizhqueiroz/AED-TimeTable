#include "menu.h"

Menu::Menu(const string &file1, const string &file2, const string &file3) {
    option = -1;

    readClassesPerUc(UCs, file1);
    readClassesData(turmas, UCs, file2);
    readStudentsData(turmas,estudantes, UCs, file3);

    mudanca = MudancaHorario();
}

void Menu::start() {
    cout << endl << "Olá, Bem-vindo a Gestão de Horários" << endl << endl;

    while(option != 0) {
        display();
        execution();
    }

    mudanca.processarPedidos(turmas,UCs);
}

void Menu::display() {
    cout << "Selecione uma opção:\t";
    cout << "1 - Visualizar Horário do Estudante" << endl;
    cout << "\t\t\t\t\t\t2 - Ocupação das Turmas" << endl;
    cout << "\t\t\t\t\t\t3 - Visualizar Estudantes na Turma" << endl;
    cout << "\t\t\t\t\t\t4 - Estudantes com mais de N número de UCs" << endl;
    cout << "\t\t\t\t\t\t5 - Listagem de Estudantes por Ordem Alfabética" << endl;
    cout << "\t\t\t\t\t\t6 - Horário das Turmas" << endl;
    cout << "\t\t\t\t\t\t7 - Alteração de Horário" << endl;
    cout << "\t\t\t\t\t\t0 - Sair" << endl;
}

void Menu::execution() {
    do {
        cin >> option;
        if (option < 0 || option > 7) cout << "Digite um número válido entre 0 e 7:" << endl;
    } while(option < 0 || option > 7);

    switch (option){
        case 1:
            visualization();
            option = -1;
            break;

        case 2:
            ocupation();
            option = -1;
            break;

        case 3:
            VisualEstudTurma();
            option = -1;
            break;

        case 4:
            estudantesUc();
            option = -1;
            break;
        case 5:
            estudantesOrdemAlfabetica();
            option = -1;
            break;
        case 6:
            turmasHorarios();
            option = -1;
            break;
        case 7:
            Alteracao();
            option = -1;
            break;
    }
}

void Menu::visualization() {
    string nome;

    while(true) {
        cout << "Para visualizar o horário do estudante, informe o nome:" << endl;
        cin >> nome;
        struct bstree_node* node = estudantes.searchName(nome);

        if (!node) {
            cout << "Estudante não encontrado. Digite 0 para voltar ao menu principal ou 1 para nova tentativa: " << endl;

        } else {
            node->est.getHorario().show();
            cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
        }

        while(true) {
            cin >> option;
            if (option != 1 && option != 0) {
                cout << "Opção não existe. Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
            } else break;
        }

        if (option == 0) break;
    }
}

void Menu::ocupation() {

    while(true) {
        cout << "Selecione uma opção:";
        cout << "\t1 - Ocupação por UC" << endl;
        cout << "\t\t\t\t\t\t2 - Ocupação por Ano" << endl;

        do {
            cin >> option;
            if (option != 1 && option != 2) cout << "Escolha uma opção válida:" << endl;
        } while(option != 1 && option != 2);

        switch (option) {
            case 1:
                cout << "Selecione uma opção:";
                cout << "\t1 - Ordenação Crescente" << endl;
                cout << "\t\t\t\t\t\t2 - Ordenação Decrescente" << endl;
                do {
                    cin >> option;
                    if (option != 1 && option != 2) cout << "Escolha uma opção válida:" << endl;
                } while(option != 1 && option != 2);

                if (option == 1) {
                    for (Uc &uc : UCs) {
                        cout << "UC: " << uc.getUcCode() << endl;
                        uc.printClassesOcupacao(option);
                        cout << endl;
                    }
                }
                else {
                        for (auto it = UCs.rbegin(); it != UCs.rend(); it++) {
                            cout << "UC: " << it->getUcCode() << endl;
                            it->printClassesOcupacao(option);
                            cout << endl;
                        }
                    }
                break;

            case 2:
                cout << "Selecione uma opção:";
                cout << "\t1 - Ordenação Crescente" << endl;
                cout << "\t\t\t\t\t\t2 - Ordenação Decrescente" << endl;
                do {
                    cin >> option;
                    if (option != 1 && option != 2) cout << "Escolha uma opção válida:" << endl;
                } while(option != 1 && option != 2);

                if (option == 1) {
                    auto it = turmas.begin();

                    cout << endl << "1º Ano:" << endl;
                    for ( ; it != turmas.end(); it++) {
                        if (!(it->getClassCode().substr(0, 1) == "1")) break;
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }

                    cout << endl << "2º Ano:" << endl;
                    for (; it != turmas.end(); it++){
                        if (!(it->getClassCode().substr(0,1) == "2")) break;
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }

                    cout << endl << "3º Ano:" << endl;
                    for (; it != turmas.end(); it++) {
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }
                }
                else {
                    auto it = turmas.rbegin();

                    cout << endl << "3º Ano:" << endl;
                    for (; it != turmas.rend(); it++) {
                        if (!(it->getClassCode().substr(0,1) == "3")) break;
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }

                    cout << endl << "2º Ano:" << endl;
                    for (; it != turmas.rend(); it++){
                        if (!(it->getClassCode().substr(0,1) == "2")) break;
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }

                    cout << endl << "1º Ano:" << endl;
                    for ( ; it != turmas.rend(); it++) {
                        //if (!(it->getClassCode().substr(0, 1) == "1")) break;
                        cout << "Turma: " << it->getClassCode() << "\tNº de Alunos: " << it->getOcupacao() << endl;
                    }
                }
                break;
        }


        cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
        while(true) {
            cin >> option;
            if (option != 1 && option != 0) {
                cout << "Opção não existe. Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
            } else break;
        }

        if (option == 0) break;
    }
}

void Menu::VisualEstudTurma() {
    string uc, ano, turma;
    auto it = UCs.begin();
    auto it2 = turmas.begin();

    while(true) {
        cout << "Selecione uma opção:\t";
        cout << "1 - Por UC" << endl;
        cout << "\t\t\t\t\t\t2 - Por Ano" << endl;

        do {
            cin >> option;
            if (option != 1 && option != 2) cout << "Escolha uma opção válida:" << endl;
        } while(option != 1 && option != 2);

        switch (option) {
            case 1:
                cout << "Digite o código da UC:" << endl;
                cin >> uc;

                cout << "Digite o código da Turma:" << endl;
                cin >> turma;

                for (; it != UCs.end(); it++) {
                    if (it->getUcCode() == uc) {
                        auto iter = it->findClass(turma);
                        if (iter != it->classesEnd()) {
                            cout << "Turma: " << turma << ' ' << "UC: " << uc << endl;
                            iter->printEstudanteByName();
                            option = 4;
                        } else {
                            cout << "Dados incorretos.";
                            option = 3;
                        }
                        break;
                    }
                }

                if (it == UCs.end()) {
                    cout << "Dados incorretos.";
                    option = 3;
                }
                break;
            case 2:
                cout << "Digite o ano:" << endl;
                cin >> ano;

                cout << "Digite o código da Turma:" << endl;
                cin >> turma;

                for (; it2 != turmas.end(); it2++) {
                    if (it2->getClassCode() == turma) {
                        if (ano == turma.substr(0,1)) {
                            cout << ano << "º" << " Ano " << ' ' << "Turma: " << turma << endl;
                            it2->printEstudanteByName();
                            option = 4;
                        } else {
                            cout << "Dados incorretos.";
                            option = 3;
                        }
                        break;
                    }
                }

                if (it2 == turmas.end()) {
                    cout << "Dados incorretos.";
                    option = 3;
                }
                break;
        }


        if (option == 3) cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova tentativa:" << endl;
        if (option == 4) cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;

        while(true) {
            cin >> option;
            if (option != 1 && option != 0) {
                cout << "Opção não existe. Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
            } else break;
        }

        if (option == 0) break;
    }
}

void Menu::estudantesUc() {
    int n;

    while(true) {
        cout << "Digite o valor de n:" << endl;

        while(true) {
            cin >> n;
            if (n < 0) cout << "Digite um número positivo:" << endl;
            else break;
        }

        cout << "Selecione uma opção:\t";
        cout << "1 - Por Ordem Alfabética" << endl;
        cout << "\t\t\t\t\t\t2 - Por Número de UC" << endl;

        do {
            cin >> option;
            if (option != 1 && option != 2) cout << "Escolha uma opção válida:" << endl;
        } while(option != 1 && option != 2);


        switch (option) {
            case 1:
                estudantes.estudMaisNAlf(estudantes.rootTree(),n);
                break;
            case 2:
                list<pair<Estudante,int>> estds;
                estudantes.estudMaisNUCs(estudantes.rootTree(),n,estds);

                for (pair<Estudante,int> &e : estds) {
                    cout << "Nome: " << setiosflags(ios::left) << setw( 25 ) << e.first.getName()
                    << "\tCódigo: " << setw( 8 ) << e.first.getStudentCode() << "\tNúmero de UCs: " << e.second << endl;
                }
                break;
        }

        cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
        while(true) {
            cin >> option;
            if (option != 1 && option != 0) {
                cout << "Opção não existe. Digite 0 para voltar ao menu principal ou 1 para nova consulta:" << endl;
            } else break;
        }

        if (option == 0) break;
    }
}

void Menu::estudantesOrdemAlfabetica() {
    estudantes.inOrder(estudantes.rootTree());
    cout << endl;
}

void Menu::turmasHorarios() {
    for (auto & turma : turmas) {
        cout << "=============================" << endl;
        cout << "Turma: " << turma.getClassCode() << endl;
        cout << "-----------------------------";
        turma.getClassHorario().show();
        cout << "=============================" << endl;
        cout << endl;
    }
}

void Menu::Alteracao() {
    mudanca.inserirEstudantes(estudantes);

    while (true) {
        cout << "Selecione uma opção:\t";
        cout << "1 - Remover estudante de turma por UC" << endl;
        cout << "\t\t\t\t\t\t2 - Adicionar estudante a turma por UC" << endl;
        cout << "\t\t\t\t\t\t3 - Alterar a turma de um estudante" << endl;
        cout << "\t\t\t\t\t\t4 - Alterar um conjunto de turmas de um estudante" << endl;

        do {
            cin >> option;
            if (option < 1 || option > 4) cout << "Escolha uma opção válida:" << endl;
        } while (option < 1 || option > 4);

        switch (option) {
            case 1:
                mudanca.guardarPedidos(option);
                option = -1;
                break;

            case 2:
                mudanca.guardarPedidos(option);
                option = -1;
                break;

            case 3:
                mudanca.guardarPedidos(option);
                option = -1;
                break;

            case 4:
                mudanca.guardarPedidos(option);
                option = -1;
                break;
        }

        cout << endl << "Digite 0 para voltar ao menu principal ou 1 para nova solicitação:" << endl;
        while(true) {
            cin >> option;
            if (option != 1 && option != 0) {
                cout << "Opção não existe. Digite 0 para voltar ao menu principal ou 1 para nova solicitação:" << endl;
            } else break;
        }

        if (option == 0) break;
    }
}
