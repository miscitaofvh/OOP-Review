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
    virtual bool isValid() = 0;
    virtual istream& input(istream& in) = 0;
    string getName() { return name; }
    bool inRange(int stage, int min, int max) {
        return stage >= min && stage <= max;
    }
    friend istream& operator>>(istream& in, Insect& insect) {
        return insect.input(in);
    }
};

class Mosquito : public Insect {
public:
    Mosquito() : Insect("Mosquito", {}) {}
    Mosquito(vector<int> stages) : Insect("Mosquito", stages) {}
    istream& input(istream& in) override {
        cout << "Enter the stages of the mosquito: ";
        stages.resize(4);
        for (int i = 0; i < 4; ++i) {
            in >> stages[i];
        }
        return in;
    }
    bool isValid() override {
        return stages.size() == 4 && inRange(stages[0], 1, 3) && inRange(stages[1], 4, 10) && inRange(stages[2], 2, 3) && inRange(stages[3], 5, 8);
    }
};

class Frog : public Insect {
public:
    Frog() : Insect("Frog", {}) {}
    Frog(vector<int> stages) : Insect("Frog", stages) {}
    istream& input(istream& in) override {
        cout << "Enter the stages of the frog: ";
        stages.resize(5);
        for (int i = 0; i < 5; ++i) {
            in >> stages[i];
        }
        return in;
    }
    bool isValid() override {
        return stages.size() == 5 && inRange(stages[0], 1, 3) && inRange(stages[1], 4, 4) && inRange(stages[2], 6, 9) && inRange(stages[3], 1, 4) && inRange(stages[4], 104, 208);
    }    
};

class Butterfly : public Insect {
public:
    Butterfly() : Insect("Butterfly", {}) {}
    Butterfly(vector<int> stages) : Insect("Butterfly", stages) {}
    istream& input(istream& in) override {
        cout << "Enter the stages of the butterfly: ";
        stages.resize(4);
        for (int i = 0; i < 4; ++i) {
            in >> stages[i];
        }
        return in;
    }
    bool isValid() override {
        return stages.size() == 4 && inRange(stages[0], 3, 8) && inRange(stages[1], 15, 16) && inRange(stages[2], 10, 10) && inRange(stages[3], 2, 3);
    }
};

class Insects {
private:
    vector<Insect*> insects;
public: 
    ~Insects() {
        for (auto insect : insects) 
            delete insect;
    } 

    friend istream& operator>>(istream& in, Insects& insects) {
        int n;
        cout << "Enter the number of insects: ";
        in >> n;
    
        for (int i = 0; i < n; ++i) {
            string name;
            cout << "Enter the name of the insect (Mosquito/Frog/Butterfly): ";
            in >> name;

            Insect* insect = nullptr;

            if (name == "Mosquito") {
                insect = new Mosquito();
            } else if (name == "Frog") {
                insect = new Frog();
            } else if (name == "Butterfly") {
                insect = new Butterfly();
            } else {
                cout << "Invalid type! Stopping...\n";
                exit(1);
            }

            in >> *insect;
            insects.insects.push_back(insect);
        }

        return in;
    }
    void InvalidInsects() const {
        bool ok = false;
        for (int i = 0; i < insects.size(); ++i) {
            if (!insects[i]->isValid()) {
                if (!ok) 
                    cout << "\nInsects with invalid development stages (Index): ";
                ok = true;
                cout << i << ' ';
            }
        }
        if (!ok)
            cout << "No invalid insects found!\n";
    }
    bool isBiodiverse() const {
        bool hasMosquito = false;
        bool hasFrog = false;
        bool hasButterfly = false;

        for (auto insect : insects) {
            if (insect->getName() == "Mosquito") hasMosquito = true;
            if (insect->getName() == "Frog") hasFrog = true;
            if (insect->getName() == "Butterfly") hasButterfly = true;

            if (hasMosquito && hasFrog && hasButterfly) return true;
        }

        return false;
    }
};

int main()
{
    Insects insects;
    cin >> insects;
    insects.InvalidInsects();
    if (insects.isBiodiverse()) 
        cout << "\nThe ecosystem is biodiverse.\n";
    else 
        cout << "\nThe ecosystem is NOT biodiverse.\n";
    
    return 0;
}