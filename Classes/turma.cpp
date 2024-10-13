#include "turma.h"

const int Turma::capacidade = 50;

Turma::Turma(const string &classCode) {
    this->classCode = classCode;
    this->classHorario = Horario();
    estudantes = {};
}

Turma::Turma(const string &classCode, const Horario &classHorario) {
    this->classCode = classCode;
    this->classHorario = classHorario;
    estudantes = {};
}

string Turma::getClassCode() {
    return classCode;
}

Horario Turma::getClassHorario() {
    return classHorario;
}

void Turma::setClassHorario(Aula &aula) {
    classHorario.addAula(aula);
}

int Turma::getOcupacao() const {
    return estudantes.size();
}

void Turma::insertEstudanteByName(pair<string,string> estudante) {
    if (estudantes.empty()) {
        estudantes.push_back(estudante);
        return ;
    }

    auto it = estudantes.begin();
    for (; it != estudantes.end(); it++) {
        if (estudante.first < it->first ) {
            estudantes.insert(it,estudante);
            break;
        } else if (estudante.first == it->first && estudante.second == it->second) {
            break;
        }
    }
    if (it == estudantes.end()) {
        estudantes.push_back(estudante);
    }
}

void Turma::printEstudanteByName() {
    for (pair<string,string> &e : estudantes) cout << "Código: " << e.second << ' ' << "Nome: " << e.first << endl;
}

bool Turma::removeEstudante(pair<string,string> estudante) {
    size_t n = estudantes.size();
    estudantes.remove(estudante);
    return n == estudantes.size();
}