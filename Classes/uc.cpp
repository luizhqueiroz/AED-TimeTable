#include "uc.h"


Uc::Uc(const string &ucCode, const Turma &turma) {
    this->ucCode = ucCode;
    this->classes = {turma};
}

string Uc::getUcCode() {
    return ucCode;
}

vector<Turma>::iterator Uc::findClass(const string &classCode) {
    for (auto it = classes.begin(); it != classes.end(); it++) {
        if (it->getClassCode() == classCode) return it;
    }
    return classes.end();
}

vector<Turma>::iterator Uc::classesEnd() {
    return classes.end();
}


void Uc::addClasses(Turma turma) {
    if (classes.empty()) classes.push_back(turma);
    else {
        auto it = classes.begin();
        for (; it != classes.end(); it++) {
            if (turma.getClassCode() < it->getClassCode()) {
                classes.insert(it, turma);
                break;
            }
        }
        if (it == classes.end()) classes.push_back(turma);
    }
}

void Uc::printClassesOcupacao(int i) {

    if (i == 1) {
        for (Turma &t: classes) {
            cout << "Turma: " << t.getClassCode() << "\t Nº de Alunos: " << t.getOcupacao() << endl;
        }
    } else {
        for (auto it = classes.rbegin(); it != classes.rend(); it++) {
            cout << "Turma: " << it->getClassCode() << "\t Nº de Alunos: " << it->getOcupacao() << endl;
        }
    }
}
