/**
 * @file aula.h
 */

#ifndef AULA_H
#define AULA_H

#include "hour.h"

#include <vector>
#include <string>

using namespace std;

/**
 * @struct information
 * @brief Contém informações sobre a Aula.
 */
struct information {
    string weekDay; /*!< Contém o dia da semana que a aula é ministrada. */
    Hour startHour; /*!< Contém a hora de inicio da aula. */
    Hour duration; /*!< Contém a duração da aula. */
    string type; /*!< Contém o tipo da aula. */
};

/**
 * @class Aula
 * @brief Representa uma aula de uma unidade curricular.
 */
class Aula {

private:
    string ucCode; /*!< Contém o código da unidade curricular. */
    vector<information> info; /*!< Contém um vetor de informação da aula da unidade curricular. */

public:
    /**
    * @brief Construtor.
    * Complexidade O(1)
    */
    Aula();
    /**
    * @brief Construtor.
    * Complexidade O(1)
    * @param ucCode Contém o código da Unidade Curricular.
     * @param weekDay Contém o dia da semana que ocorre a aula.
     * @param startHour Contém a hora que se inicia a aula.
     * @param duration Contém a duração da aula.
     * @param type Contém o tipo de aula.
    */
    Aula(const string &ucCode, const string &weekDay, const Hour &startHour, const Hour &duration, const string &type);
    /**
     *@brief Insere informações da aula.
     * @param weekDay Contém o dia da semana que ocorre a aula.
     * @param startHour Contém a hora que se inicia a aula.
     * @param duration Contém a duração da aula.
     * @param type Contém o tipo de aula.
     */
    void insertInfo(const string &weekDay, const Hour &startHour, const Hour &duration, const string &type);
    /**
     * @brief Pega o código da unidade curricular da aula.
     * Complexidade O(1)
     * @return Retorna uma string contendo código da unidade curricular.
     */
    string getUcCode();
    /**
     * @brief Pega as informações da aula de uma unidade curricular.
     * Complexidade O(1)
     * @return Retorna um vetor de informações da aula.
     */
    vector<information> getInfo();
    /**
     * @brief Coloca informações da aula de uma unidade curricular.
     * @param i contém a informação da aula a ser colocada.
     */
    void setInfo(const information &i);
    /**
     * @brief Printa a aula de uma unidade curricular.
     */
    void showAula();
};

#endif
