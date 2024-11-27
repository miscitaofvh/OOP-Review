#include "Butterfly.h"

Butterfly::Butterfly() : Insect("Butterfly", {}) {}
Butterfly::Butterfly(vector<int> stages) : Insect("Butterfly", stages) {}

istream& Butterfly::input(istream& in) {
    cout << "Enter the stages of the butterfly: ";
    stages.resize(4);
    for (int i = 0; i < 4; ++i) {
        in >> stages[i];
    }
    return in;
}

bool Butterfly::isValid() {
    return stages.size() == 4 && inRange(stages[0], 3, 8) && inRange(stages[1], 15, 16) && inRange(stages[2], 10, 10) && inRange(stages[3], 2, 3);
    
}

istream& operator>>(istream& in, Butterfly& butterfly) {
    return butterfly.input(in);
}