#include <iostream>
#include <set>
#include "Person.h"

/*
 *    Programming Challenge 9
 *    Building on Program 19-5, write a function that
 *    takes a pointer to a Person object and produces a list of
 *    that Person's cousins.
 *
 *    Implementation:
 *    The Person class from Program 19-5 is unmodified.
 *    The getCousins() function is implemented in main.cpp.
 *
 */


std::vector<Person *> getCousins(Person *);

std::vector<Person *> produceTestData();
void doTesting(Person *, std::string);

int main() {
    // Test Data
    std::vector<Person *> test = produceTestData();

    std::cout << "Testing getCousins() function... \n";
    std::cout << "Family tree loaded. See source for tree. \n\n";

    doTesting(test[5], "Bellatrix, Narcissa, Andromeda"); // Sirius
    doTesting(test[2], "No cousins found."); // Lucretia
    doTesting(test[14], "Nymphadora"); // Draco
    doTesting(test[13], "Sirius, Regulus"); // Andromeda

    // Clear test data.
    for (Person * t : test) {
        delete t;
    }
    return 0;
}

std::vector<Person *> getCousins(Person * person) {
    if (!person) return std::vector<Person *>();
    // Return empty vector.

    // NOTE: Sets are used to avoid name duplication.
    // The insert function does nothing if key is already there.
    // Get the list of parents for child.
    std::set<Person *> parents;
    for (int i = 0; i < person->getNumParents(); i++) {
        parents.insert(person->getParent(i));
    }

    // Get the list of grandparents.
    std::set<Person *> grandparents;
    for (Person * parent : parents) {
        for (int i = 0; i < parent->getNumParents(); ++i) {
            grandparents.insert(parent->getParent(i));
        }
    }

    // Get the list of children of the grandparents
    std::set<Person *> parentSiblings;
    for (Person * grandparent : grandparents) {
        for (int i = 0; i < grandparent->getNumChildren(); ++i) {
            parentSiblings.insert(grandparent->getChild(i));
        }
    }
    // Remove the current parents to get list of parent siblings
    for (Person * parent : parents) {
        parentSiblings.erase(parent);
    }

    // Now, get the children of the p-siblings to get cousins
    std::set<Person *> cousinSet; // To avoid duplication.
    for (Person * parentSibling : parentSiblings) {
        for (int i = 0; i < parentSibling->getNumChildren(); i++) {
            cousinSet.insert(parentSibling->getChild(i));
        }
    }

    return std::vector<Person *>(cousinSet.begin(), cousinSet.end());
}

std::vector<Person *> produceTestData() {
    /*
     *    Black Family Tree (Test Data)
     *    Arcturus --- Melania    Pollux --- Irma
     *              |                     |
     *          ---------           -----------
     *         |        |          |          |
     *    Lucretia    Orion --- Walburga   Cygnus --- Druella
     *                       |                     |
     *                  ---------         -------------------------
     *                 |        |        |            |           |
     *              Sirius   Regulus  Bellatrix   Narcissa   Andromeda
     *                                               |           |
     *                                             Draco    Nymphadora
     *
     */
    std::vector<Person *> people = {
        new Person( "Arcturus Black III", male ), // 0
        new Person( "Melania Macmillan", male ), // 1
        new Person( "Lucretia Prewett", female ), // 2

        new Person( "Orion Black", male ), // 3
        new Person( "Walburga Black", female ), // 4
        new Person( "Sirius Black", male ), // 5
        new Person( "Regulus Black", male ), // 6

        new Person( "Pollux Black", male ), // 7
        new Person( "Irma Crabbe", female ), // 8

        new Person( "Cygnus Black", male ), // 9
        new Person( "Druella Rosier", female ), // 10

        new Person( "Bellatrix Lestrange", female ), // 11
        new Person( "Narcissa Malfoy", female ), // 12
        new Person( "Andromeda Tonks", female ), // 13

        new Person( "Draco Malfoy", male ), // 14
        new Person( "Nymphadora Tonks", female ), // 15
    };

    // Establish relationships.
    people[0]->addChild(people[2]);
    people[1]->addChild(people[2]);

    people[3]->addChild(people[5]); people[4]->addChild(people[5]);
    people[3]->addChild(people[6]); people[4]->addChild(people[6]);

    people[7]->addChild(people[4]); people[7]->addChild(people[4]);
    people[7]->addChild(people[9]); people[7]->addChild(people[9]);

    people[9]->addChild(people[11]); people[10]->addChild(people[11]);
    people[9]->addChild(people[12]); people[10]->addChild(people[12]);
    people[9]->addChild(people[13]); people[10]->addChild(people[13]);

    people[12]->addChild(people[14]);
    people[13]->addChild(people[15]);

    return people;
}

void doTesting(Person * test, std::string expectedResults) {
    std::vector<Person *> testResults;

    std::cout << "Testing: " << test->getName() << "\n"
              << "Expected Results: " << expectedResults << " \n";
    std::cout << "Cousins found for " << test->getName() << "... \n";
    testResults = getCousins(test);
    if (testResults.size() == 0) {
        std::cout << "  No cousins found. \n";
    } else {
        for (Person * p : testResults) {
            std::cout << "  " << p->getName() << "\n";
        }
    }

    std::cout << "\n";
}