#include "estudante.h"

Estudante::Estudante() {
    studentName = "";
    studentCode = "";
    studentHorario = Horario();
    studentClassCode = {};
}

Estudante::Estudante(const string &studentCode, const string &studentName, const Horario &studentHorario, const string &studentClassCode) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->studentHorario = studentHorario;
    this->studentClassCode.push_back(studentClassCode);
}

string Estudante::getName() {
    return studentName;
}

Horario Estudante::getHorario() {
    return studentHorario;
}

string Estudante::getStudentCode() {
    return studentCode;
}

void Estudante::setStudentHorario(const vector<Aula> &aulas) {
    for (Aula a: aulas) studentHorario.addAula(a);
}

vector<string> Estudante::getStudentClassCode() {
    return studentClassCode;
}