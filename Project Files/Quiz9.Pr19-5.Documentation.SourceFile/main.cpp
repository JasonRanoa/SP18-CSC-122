// This program uses a generalization of binary trees to build
// genealogy trees.
#include "Person.h"
using namespace std;

int main(int argc, char ** argv) {
    // 1st Generation
    Person james("James", male);
    Person lily("Lily", female);

    Person arthur("Arthur", male);
    Person molly("Molly", female);

    // 2nd Generation
    Person * harry = james.addChild("Harry", male);
    lily.addChild(harry);
    Person * ron = arthur.addChild("Ron", male);
    molly.addChild(ron);
    Person * ginny = arthur.addChild("Ginny", female);
    molly.addChild(ginny);

    // The Grandchildren
    Person * james2nd = harry->addChild("James Sirius", male);
    Person * albus = harry->addChild("Albus Severus", male);
    Person * lily2nd = harry->addChild("Lily Luna", female);
    ginny->addChild(james2nd);
    ginny->addChild(albus);
    ginny->addChild(lily2nd);

    // Output all people.
    cout << "Here are all the people: \n";
    cout << james << "\n" << lily << "\n";
    cout << molly << "\n" << arthur << "\n";
    cout << *harry << "\n" << *ron << "\n" << *ginny << "\n";
    cout << *james2nd << "\n" << *albus << "\n" << *lily2nd << "\n";

    // Print out the children of Harry
    cout << "Harry's children are: \n";
    for (int i = 0; i < harry->getNumChildren(); i++) {
        Person * temp = harry->getChild(i);
        switch (temp->getGender()) {
            case male:
                cout << "    Son: " << temp->getName() << "\n";
                break;
            case female:
                cout << "    Daughter: " << temp->getName() << "\n";
                break;
        }
    }

    return 0;
}
