#include "horario.h"

Horario::Horario() {
    aulas = {};
}

Horario::Horario(const Aula &aula) {
    aulas = {aula};
}

vector<Aula> Horario::getAulas() {
    return aulas;
}

void Horario::addAula(Aula &aula) {
    bool add = true;
    for (Aula &a : aulas) {
        if (a.getUcCode() == aula.getUcCode()) {
            for (information &i : aula.getInfo()) {
                a.setInfo(i);
            }
            add = false;
            break;
        }
    }

    if(add) {
        aulas.push_back(aula);
    }
}

bool Horario::removeAula( const string &ucCode) {
    for (auto it = aulas.begin(); it != aulas.end(); it++) {
        if (it->getUcCode() == ucCode) {
            aulas.erase(it);
            return true;
        }
    }
    return false;
}

void Horario::show() {

    if (aulas.empty()) {
        cout << "Horário Inexistente";
        return ;
    }

    for (Aula &a : aulas) {
        cout << endl;
        a.showAula();
    }
}
