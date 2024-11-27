#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Insect.h"

class Mosquito : public Insect {
public:
    Mosquito();
    Mosquito(vector<int> stages);
    istream& input(istream& in) override;
    bool isValid() override;
    friend istream& operator>>(istream& in, Mosquito& mosquito);
};

#endif // MOSQUITO_H