//
// Created by TheLoneWoof on 4/5/18.
//

#ifndef QUIZ9_PR19_5_DOCUMENTATION_SOURCEFILE_PERSON_H
#define QUIZ9_PR19_5_DOCUMENTATION_SOURCEFILE_PERSON_H

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

enum Gender{male, female};

// Person class represents a person participating in a genealogy.
class Person
{
    string name;
    Gender gender;
    vector<Person *> parents;
    vector<Person *> children;
    void addParent(Person *p){ parents.push_back(p); }
public:
    Person (string name, Gender g)
    {
        this->name = name;
        gender = g;
    }
    Person *addChild(string name, Gender g);
    Person *addChild(Person *p);

    friend ostream &operator << (ostream &out, Person p);

    // Member functions for getting various Person info
    string getName() const{ return name; };
    Gender getGender() const{ return gender; };
    int getNumChildren() const{ return children.size(); }
    int getNumParents() const{ return parents.size(); }
    Person *getChild(int k) const ;
    Person *getParent(int k) const;
};

#endif //QUIZ9_PR19_5_DOCUMENTATION_SOURCEFILE_PERSON_H
