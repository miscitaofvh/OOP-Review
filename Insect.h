#ifndef INSECT_H
#define INSECT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Insect {
protected:
    string name;
    vector<int> stages;

public:
    Insect(string name, vector<int> stages) : name(name), stages(stages) {}
    virtual ~Insect() {}
    virtual istream& input(istream& in) = 0;
    virtual bool isValid() = 0;
    string getName() const { return name; }
    bool inRange(int value, int min, int max) {
        return value >= min && value <= max;
    }
};

#endif // INSECT_H