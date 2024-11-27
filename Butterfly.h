#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include "Insect.h"

class Butterfly : public Insect {
public:
    Butterfly();
    Butterfly(vector<int> stages);
    istream& input(istream& in) override;
    bool isValid() override;
    friend istream& operator>>(istream& in, Butterfly& butterfly);
};

#endif // BUTTERFLY_H