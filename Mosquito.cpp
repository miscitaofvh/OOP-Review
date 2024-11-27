#include "Mosquito.h"

Mosquito::Mosquito() : Insect("Mosquito", {}) {}
Mosquito::Mosquito(vector<int> stages) : Insect("Mosquito", stages) {}

istream& Mosquito::input(istream& in) {
    cout << "Enter the stages of the mosquito: ";
    stages.resize(4);
    for (int i = 0; i < 4; ++i) {
        in >> stages[i];
    }
    return in;
}

istream& operator>>(istream& in, Mosquito& mosquito) {
    return mosquito.input(in);
}

bool Mosquito::isValid() {
    return stages.size() == 4 && inRange(stages[0], 1, 3) && inRange(stages[1], 4, 10) && inRange(stages[2], 2, 3) && inRange(stages[3], 5, 8);
}