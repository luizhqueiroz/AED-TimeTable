#include "Classes/menu.h"

int main() {
    string file1 = "../data/classes_per_uc.csv";
    string file2 = "../data/classes.csv";
    string file3 = "../data/students_classes.csv";

    Menu menu(file1, file2, file3);
    menu.start();

    return 0;
}

