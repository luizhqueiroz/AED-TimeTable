/**
 * @file turma.h
 */

#ifndef TURMA_H
#define TURMA_H

#include <string>
#include <list>

#include "estudante.h"
#include "horario.h"

using namespace std;

/**
 * @class Turma
 * @brief Representa uma turma.
 */
class Turma {

private:
    string classCode;  /*!< Contém o código da turma. */
    Horario classHorario; /*!< Contém o horário da turma. */
    list<pair<string,string>> estudantes; /*!< Contém uma lista dos estudantes identificados por nome e código de estudante. */
    const static int capacidade; /*!< Contém a capacidade máxima da turma. */

public:
    /**
     * @brief Construtor.
     * Complexidade O(1)
     * @param classCode Contém o código da turma.
     * @param classHorario Contém o horário da turma.
     */
    Turma(const string &classCode, const Horario &classHorario);
    /**
     * @brief Construtor.
     * Complexidade O(1)
     * @param classCode Contém o código da turma.
     */
    Turma(const string &classCode);
    /**
     * @brief Pega o código da turma.
     * @return Retorna uma string contendo o código da turma.
     */
    string getClassCode();
    /**
     * @brief Pega o horário da turma.
     * @return Retorna um objeto da classe Horario contendo o horário da turma.
     */
    Horario getClassHorario();
    /**
     * @brief Coloca uma aula no horário da turma.
     * @param aula Contém a aula que será adicionada ao horário da turma.
     */
    void setClassHorario(Aula &aula);
    /**
     * @brief Pega a ocupação da turma.
     * @return Retorna um inteiro contendo a ocupação da turma.
     */
    int getOcupacao() const;
    /**
     * @brief Insere um estudante na lista de estudantes da turma por ordem alfabética.
     * @param estudante Contém o estudante a ser adicionado a turma.
     */
    void insertEstudanteByName(pair<string,string> estudante);
    /**
     * @brief Printa os estudantes da turma por ordem alfabética.
     */
    void printEstudanteByName();
    /**
     * @brief Remove o estudante da turma.
     * @param estudante Contém a informação do estudante a ser removido.
     * @return Retorna true se o estudando for removido e false caso contrário.
     */
    bool removeEstudante(pair<string,string> estudante);
};

#endif
