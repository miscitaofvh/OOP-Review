#include <iostream>
#include <vector>
#include "Butterfly.h"
#include "Frog.h"
#include "Mosquito.h"
#include "Insect.h"

using namespace std;

void InvalidInsects(const vector<Insect*>& insects) {
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

bool isBiodiverse(const vector<Insect*>& insects) {
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

int main() {
    vector<Insect*> insects;
    int n;
    cout << "Enter the number of insects: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        cout << "Enter the name of the insect (Mosquito/Frog/Butterfly): ";
        cin >> name;
        Insect* insect = nullptr;
        if (name == "Mosquito") {
            insect = new Mosquito();
            cin >> *dynamic_cast<Mosquito*>(insect);
        } else if (name == "Frog") {
            insect = new Frog();
            cin >> *dynamic_cast<Frog*>(insect);
        } else if (name == "Butterfly") {
            insect = new Butterfly();
            cin >> *dynamic_cast<Butterfly*>(insect);
        } else {
            cout << "Invalid type! Stopping...\n";
            exit(1);
        }
        insects.push_back(insect);
    }

    InvalidInsects(insects);
    if (isBiodiverse(insects)) 
        cout << "\nThe ecosystem is biodiverse.\n";
    else 
        cout << "\nThe ecosystem is NOT biodiverse.\n";

    for (auto insect : insects) 
        delete insect;

    return 0;
}