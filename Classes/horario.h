/**
 * @file horario.h
 */

#ifndef HORARIO_H
#define HORARIO_H

#include "aula.h"

#include <string>
#include <vector>

using namespace std;

/**
 * @class Horario
 * @brief Representa um horário que é um conjuntos de aulas.
 */
class Horario {

private:
    vector<Aula> aulas; /*!< Contém um vetor de aulas que formam o horário. */

public:
    /**
     * @brief Construtor.
     * Complexidade O(1)
     */
    Horario();
    /**
     * @brief Construtor.
     * Complexidade O(1)
     * @param aula Contém a aula que formará o horário.
     */
    Horario(const Aula &aula);
    /**
     * @brief Pega as aulas do horário.
     * Complexidade O(1)
     * @return Retorna um vetor com as aulas que formam o horário.
     */
    vector<Aula> getAulas();
    /**
     * @brief Adiciona uma aula ao horário.
     * @param aula Contém a aula que será adicionada ao horário.
     */
    void addAula(Aula &aula);
    /**
     * @brief Remove uma aula do horário.
     * @param ucCode Contém o código da unidade curricular a ser removida do horário.
     */
    bool removeAula(const string &ucCode);
    /**
     * @brief Printa o horário.
     */
    void show();
};

#endif
