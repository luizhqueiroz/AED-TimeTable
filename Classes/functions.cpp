#include "functions.h"

void readClassesPerUc(list<Uc> &UCs,const string &file) {
    ifstream f(file);
    string line, ucCode, classCode;

    getline(f, line);

    while (getline(f, line)) {
        istringstream is(line);

        getline(is, ucCode, ',');
        getline(is, classCode);

        classCode = classCode.substr(0, classCode.size() - 1);

        if (UCs.empty()) UCs.emplace_back(ucCode, Turma(classCode));
        else {
            auto it = UCs.begin();
            for ( ; it != UCs.end(); it++) {
                if (ucCode == it->getUcCode()) {
                    it->addClasses(Turma(classCode));
                    break;
                }
                else if (ucCode < it->getUcCode()) {
                    UCs.insert(it, Uc(ucCode, Turma(classCode)));
                    break;
                }
            }

            if (it == UCs.end()) {
                UCs.emplace_back(ucCode, Turma(classCode));
            }
        }
    }
}

void readClassesData(list<Turma> &turmas, list<Uc> &UCs,const string &file) {
    ifstream f(file);
    string line, classCode, ucCode, weekday, startHourStr, durationStr, type;
    vector<string> classcodes;

    getline(f,line);

    while(getline(f,line)) {
        istringstream is(line);

        getline(is, classCode, ',');
        getline(is, ucCode, ',');
        getline(is, weekday, ',');
        getline(is, startHourStr, ',');
        getline(is, durationStr, ',');
        getline(is, type);

        type = type.substr(0,type.size()-1);

        Hour startHour = Hour(startHourStr);
        Hour duration = Hour(durationStr);

        Aula aula =  Aula(ucCode, weekday, startHour, duration, type);

        if (turmas.empty()) turmas.emplace_back(classCode,Horario(aula));
        else {
            auto it = turmas.begin();
            for ( ; it != turmas.end(); it++) {
                if (classCode == it->getClassCode()) {
                    it->setClassHorario(aula);
                    break;
                } else if (classCode < it->getClassCode()) {
                    turmas.insert(it,Turma(classCode,Horario(aula)));
                    break;
                }
            }

            if (it == turmas.end()) turmas.emplace_back(classCode, Horario(aula));
        }
    }
}


void readStudentsData(list<Turma> &turmas, Bst &estudantes, list<Uc> &UCs,const string &file) {
    ifstream f(file);
    string line, studCode, studName, ucCode, classCode;

    getline(f,line);

    while (getline(f,line)) {
        istringstream is(line);

        getline(is, studCode, ',');
        getline(is, studName, ',');
        getline(is, ucCode, ',');
        getline(is, classCode);

        classCode = classCode.substr(0, classCode.size() - 1);

        auto it = UCs.begin();
        for (; it != UCs.end(); it++){
            if (it->getUcCode() == ucCode) {
                auto iter = it->findClass(classCode);
                iter->insertEstudanteByName(make_pair(studName, studCode));
                break;
            }
        }

        Horario horario;

        for (Turma &t : turmas) {
            if (t.getClassCode() == classCode) {
                t.insertEstudanteByName(make_pair(studName, studCode));
                for (Aula &a : t.getClassHorario().getAulas()) {
                    if (a.getUcCode() == ucCode) {
                        horario.addAula(a);
                    }
                }
            }
        }

        bstree_node* nodestudent = estudantes.searchName(studName);
        if (!nodestudent) {
            estudantes.insert(Estudante(studCode, studName,horario,classCode));
        } else {
            nodestudent->est.setStudentHorario(horario.getAulas());
        }
    }
}