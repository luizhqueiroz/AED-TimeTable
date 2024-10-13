/**
 * @file estudante.h
 */

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <string>

#include "horario.h"

using namespace std;

/**
 * @class Estudante
 * @brief Representa um estudante.
 */
class Estudante {
private:
    string studentCode; /*!< Contém o código do estudante. */
    string studentName; /*!< Contém o nome do estudante. */
    Horario studentHorario; /*!< Contém o horário do estudante. */
    vector<string> studentClassCode; /*!< Contém as turmas em que o estudante está inscrito. */

public:
    /**
     * @brief Construtor.
     * Complexidade O(1)
     */
    Estudante();

    /**
     * @brief Construtor.
     * Complexidade O(1)
     * @param studentCode Contém o código do estudante.
     * @param studentName Contém o nome do estudante.
     * @param studentHorario Contém o horário do estudante.
     * @param StudentClassCode Contém as turmas em que o estudante está inscrito.
     */
    Estudante(const string &studentCode, const string &studentName, const Horario &studentHorario, const string &StudentClassCode);
    /**
     * @brief Pega o nome de um estudante.
     * Complexidade O(1)
     * @return Retorna uma string contendo o nome do estudante.
     */
    string getName();
    /**
     * @brief Pega o horário do estudante.
     * Complexidade O(1)
     * @return Retorna um objeto da classe Horario contendo o horário do estudante.
     */
    Horario getHorario();
    /**
     * @brief Pega o código do estudante.
     * Complexidade O(1)
     * @return Retorna uma string contendo o código do estudante.
     */
    string getStudentCode();
    /**
     * @brief Pega o código das turmas que o estudante está inscrito.
     * Complexidade O(1)
     * @return Retorna um vetor de string contendo o código das turmas do estudante.
     */
    vector<string> getStudentClassCode();
    /**
     * @brief Coloca aulas no horário do estudante.
     * @param aulas contém um vetor com as aulas que serão adicionadas ao horário do estudante.
     */
    void setStudentHorario(const vector<Aula> &aulas);
};

#endif
