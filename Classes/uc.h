/**
 * @file uc.h
 */

#ifndef UC_H
#define UC_H

#include "turma.h"
#include <list>

using namespace std;

/**
 * @class Uc
 * @brief Representa uma Unidade Curricular.
 */
class Uc {
private:
    string ucCode; /*!< Contém o código da unidade curricular. */
    vector<Turma> classes; /*!< Contém um vetor de turma com as turmas que possuem a unidade curricular. */

public:
    /**
     * @brief Construtor.
     * @param ucCode Contém o código da unidade curricular.
     * @param turma Contém a turma que contém a unidade curricular.
     */
    Uc(const string &ucCode, const Turma &turma);
    /**
     * @brief Pega o código da unidade curricular.
     * @return Retorna uma string com o código da unidade curricular.
     */
    string getUcCode();
    /**
     * @brief Procura a turma com determinado código de turma entre as turmas que possuem a unidade curricular.
     * @param classCode Contém o código da turma que será pesquisada.
     * @return Retorna, se a turma for encontra, o iterador  para turma procurada dentro do vetor de turma. Caso contrário, retorna o iterador para o fim desse vetor.
     */
    vector<Turma>::iterator findClass(const string &classCode);
    /**
     * @brief Pega o iterador para o fim do vetor de turma.
     * @return Retorna o iterador para o fim do vetor de turma.
     */
    vector<Turma>::iterator classesEnd();
    /**
     * @brief Adiciona uma turma ao vetor de turma por ordem crescente do código da turma.
     * @param turma Contém a turma que será adicionada ao vetor de turma.
     */
    void addClasses(Turma turma);
    /**
     * @brief Printa as turmas e sua ocupação por ordem crescente ou decrescente do código da turma.
     * @param i Contém o valor que define se as turmas serão printadas por ordem crescente ou decrescente do código da turma.
     */
    void printClassesOcupacao(int i);
};

#endif
