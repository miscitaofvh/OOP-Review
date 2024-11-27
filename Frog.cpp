#include "Frog.h"

Frog::Frog() : Insect("Frog", {}) {}
Frog::Frog(vector<int> stages) : Insect("Frog", stages) {}

istream& Frog::input(istream& in) {
    cout << "Enter the stages of the frog: ";
    stages.resize(5);
    for (int i = 0; i < 5; ++i) {
        in >> stages[i];
    }
    return in;
}

istream& operator>>(istream& in, Frog& frog) {
    return frog.input(in);
}

bool Frog::isValid() {
    return stages.size() == 5 && inRange(stages[0], 1, 3) && inRange(stages[1], 4, 4) && inRange(stages[2], 6, 9) && inRange(stages[3], 1, 4) && inRange(stages[4], 104, 208);
}