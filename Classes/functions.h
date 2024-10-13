/**
 * @file functions.h
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "menu.h"

/**
 * @brief Função para ler ficheiro.
 * @param turmas Contém uma lista de turmas a ser preenchida pelo ficheiro.
 * @param UCs   Contém uma lista de unidades curriculares.
 * @param file Contém o nome do ficheiro csv.
 */
void readClassesData(list<Turma> &turmas, list<Uc> &UCs,const string &file);
/**
 *@brief Função para ler ficheiro.
 * @param turmas contém uma lista de turmas para relacionar aos estudantes.
 * @param estudantes contém uma bst a ser preenchida com estudantes pelo ficheiro.
 * @param UCs contém uma lista de unidades curriculares para relacionar aos estudantes.
 * @param file Contém o nome do ficheiro csv.
 */
void readStudentsData(list<Turma> &turmas, Bst &estudantes, list<Uc> &UCs,const string &file);
/**
 *@brief Função para ler ficheiro.
 * @param UCs contém uma lista de unidades curriculares a ser preenchida pelo ficheiro.
 * @param file Contém o nome do ficheiro csv.
 */
void readClassesPerUc(list<Uc> &UCs,const string &file);

#endif
