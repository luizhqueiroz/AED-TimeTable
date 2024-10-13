/**
 * @file menu.h
 */

#ifndef MENU_H
#define MENU_H

#include "aula.h"
#include "estudante.h"
#include "horario.h"
#include "hour.h"
#include "turma.h"
#include "bst.h"
#include "uc.h"
#include "functions.h"
#include "mudancaHorario.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;

/**
 * @class Menu
 * @brief Representa o Menu.
 */
class Menu {
private:
    int option; /*!< Contém a opção que será utilizada para navegar pelo menu de acordo com a escolha do usuário. */
    list<Uc> UCs; /*!< Contém a lista de unidade curricular. */
    list<Turma> turmas; /*!< Contém a lista de turma. */
    Bst estudantes; /*!< Contém a bst de estudantes. */
    MudancaHorario mudanca; /*!< Contém as informações para alteração de horários. */

public:
    /**
     * @brief Construtor
     * @param file1 Contém o nome do ficheiro csv a ser passado para leitura.
     * @param file2 Contém o nome do ficheiro csv a ser passado para leitura.
     * @param file3 Contém o nome do ficheiro csv a ser passado para leitura.
     */
    Menu(const string &file1, const string &file2, const string &file3);
    /**
     * @brief Inicia o menu e o mantém em execução até o fim do programa.
     */
    void start();
    /**
     * @brief Mostra o menu principal com as opções para escolha do usuário.
     */
    static void display();
    /**
     * @brief Executa a escolha do usuário.
     */
    void execution();
    /**
     * @brief Faz a opção de visualizar o horário do estudante.
     */
    void visualization();
    /**
     * @brief Faz a opção de verificar a ocupação das turmas.
     */
    void ocupation();
    /**
     * @brief Faz a opção de visualizar os estudantes de determinada turma.
     */
    void VisualEstudTurma();
    /**
     * @brief Faz a opção de visualizar os estudantes com mais de n unidades curriculares.
     */
    void estudantesUc();
    /**
     * @brief Faz a opção de listar os estudantes por ordem alfabética.
     */
    void estudantesOrdemAlfabetica();
    /**
     * @brief Faz a opção de visualizar os horários das turmas.
     */
    void turmasHorarios();
    /**
     * @brief Faz a opção de alteração de horários.
     */
    void Alteracao();

};

#endif
