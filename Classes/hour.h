/**
 * @file hour.h
 */

#ifndef HOUR_H
#define HOUR_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Hour
 * @brief Representa o tempo em horas e minutos.
 */
class Hour {
private:
    int hora; /*!< Contém a hora. */
    int min; /*!< Contém o minuto. */

public:
    /**
     * @brief Construtor.
     * Complexidade O(1)
     */
    Hour();
    /**
     * @brief Construtor.
     * Complexidade O(1)
     * @param hora Contém a hora.
     * @param min Contém o minuto.
     */
    Hour(int hora, int min);
    /**
     * @brief Construtor.
     * @param hour Contém o tempo em forma decimal da hora.
     */
    Hour( const string &hour);
    /**
     * @brief Faz a soma do tempo com a duração de uma atividade.
     * @param duration Contém a duração de uma atividade.
     * @return Retorna o tempo em horas e minutos do fim de uma atividade.
     */
    Hour sum(Hour duration) const;
    /**
     * @brief Printa o tempo em formato de hora e minuto.
     */
    void showHour() const;
};

#endif
