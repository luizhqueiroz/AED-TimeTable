#include "aula.h"

Aula::Aula() {
    ucCode = "";
    info = {};
}

Aula::Aula(const string &ucCode, const string &weekDay, const Hour &startHour, const Hour &duration, const string &type){
    this->ucCode = ucCode;

    information infor;
    infor.weekDay = weekDay;
    infor.startHour = startHour;
    infor.duration = duration;
    infor.type = type;

    info.push_back(infor);
}

void Aula::insertInfo(const string &weekDay, const Hour &startHour, const Hour &duration, const string &type) {
    information infor;
    infor.weekDay = weekDay;
    infor.startHour = startHour;
    infor.duration = duration;
    infor.type = type;

    info.push_back(infor);
}

string Aula::getUcCode() {
    return ucCode;
}

vector<information> Aula::getInfo() {
    return info;
}

void Aula::setInfo(const information &i) {
    info.push_back(i);
}

void Aula::showAula() {
    cout << "UC: " << ucCode << endl;
    for (information i : info) {
        cout << i.weekDay + ' ';
        i.startHour.showHour();
        cout << ' ';
        i.startHour.sum(i.duration).showHour();
        cout << ' ' << i.type << endl;
    }
}
