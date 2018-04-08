// This program demonstrates the STL list container.
#include <iostream>
#include <list>     // Include the list header
#include <string>
#include <sstream>
using namespace std;

void doubleList();
void charList();
void stringList();

int main()
{
    doubleList();
    charList();
    stringList();
    return 0;
}

void doubleList() {
    list<double> myList;
    list<double>::iterator iter;

    // Add values to the list
    for (double x = 0; x < 100; x += 9.99)
        myList.push_back(x);

    cout << "List of Doubles: \n";
    // Display the values
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // Now reverse the order of the elements
    myList.reverse();

    // Display the values again
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << "\n\n";
}

void charList() {
    list<char> myList;
    list<char>::iterator iter;

    // Add values to the list
    for (int x = (int)('A'); x <= (int)('Z'); x += 1)
        myList.push_back((char)(x));

    cout << "List of Characters: \n";
    // Display the values
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // Now reverse the order of the elements
    myList.reverse();

    // Display the values again
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << "\n\n";
}

void stringList() {
    list<string> myList;
    list<string>::iterator iter;

    string test = "The quick brown fox jumps over the lazy dog.";
    istringstream iss(test);

    string temp;
    while(iss >> temp) {
        myList.push_back(temp);
    };

    cout << "List of Strings: \n";
    // Display the values
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    // Now reverse the order of the elements
    myList.reverse();

    // Display the values again
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << "\n\n";
}