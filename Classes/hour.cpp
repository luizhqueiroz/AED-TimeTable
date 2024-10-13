#include "hour.h"

Hour::Hour() {
    hora = 0;
    min = 0;
}

Hour::Hour(int hora, int min) {
    this->hora = hora;
    this->min = min;
}

Hour::Hour(const string &hour) {
    float time = stof(hour);
    hora = int(time);
    min = (time - int(time))*60;
}

Hour Hour::sum(Hour duration) const{
    int horaSum = hora, minSum = min;
    horaSum += duration.hora;
    minSum += duration.min;

    if ( minSum >= 60) {
        horaSum++;
        minSum -= 60;
    }

    return {horaSum,minSum};
}

void Hour::showHour() const {
    cout << hora << 'h' << min << 'm';
}
