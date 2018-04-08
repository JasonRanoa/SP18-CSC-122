//
// Created by TheLoneWoof on 4/5/18.
//

#include "Person.h"

//************************************************************
// Create a child with specified name and gender, and        *
// set one of the parents to be this person.                 *
// Add the new child to the list of childfen for this person *
//************************************************************
Person *Person::addChild(string name, Gender g)
{
    Person *child = new Person(name, g);
    child->addParent(this);     // I am a parent of this child
    children.push_back(child);  // This is one of my children
    return child;
}

//************************************************************
// Add a child to the list of children for this person       *
//************************************************************
Person *Person::addChild(Person* child)
{
    child->addParent(this);    // I am a parent of this child
    children.push_back(child); // This is one of my children
    return child;
}

//*********************************************************
// Return a pointer to the specified parent               *
//*********************************************************
Person *Person::getParent(int k) const
{
    if (k < 0 || k >= parents.size())
    {
        cout << "Error indexing parents vector." << endl;
        exit(1);
    }
    return parents[k];
}

//**********************************************************
// Return a pointer to a specified child                   *
//**********************************************************
Person *Person::getChild(int k) const
{
    if (k < 0 || k >= children.size())
    {
        cout << "Error indexing children's vector." << endl;
        exit(1);
    }
    return children[k];
}

//****************************************************
// Overloaded stream output operator                 *
//****************************************************
ostream & operator<<(ostream & out, Person p)
{
    out << "<person name = " << p.name << ">" << '\n';
    if (p.parents.size() > 0)
        out << "   <parents>" << ' ';
    for (int k = 0; k < p.parents.size(); k++)
    {
        out << " " << p.parents[k]->name << ' ';
    }
    if (p.parents.size() > 0)
        out << " </parents>" << "\n";
    if (p.children.size() > 0)
        out << "   <children>" << ' ';
    for (int k = 0; k < p.children.size(); k++)
    {
        out << " " << p.children[k]->name << ' ';
    }
    if (p.children.size() > 0)
        out << " </children>" << "\n";
    out << "</person>" << "\n";
    return out;
}

