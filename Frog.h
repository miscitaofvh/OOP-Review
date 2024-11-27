#ifndef FROG_H
#define FROG_H

#include "Insect.h"

class Frog : public Insect {
public:
    Frog();
    Frog(vector<int> stages);
    istream& input(istream& in) override;
    bool isValid() override;
    friend istream& operator>>(istream& in, Frog& frog);
};

#endif // FROG_H