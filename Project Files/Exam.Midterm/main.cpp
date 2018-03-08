#include <iostream>
#include <string>
#include "LinkedList.h"

void testWithChars();
void testWithStrings();

int main() {
    std::cout << "Now testing with characters... \n";
    testWithChars();
    std::cout << "\n";

    std::cout << "Now testing with strings... \n";
    testWithStrings();
    std::cout << "\n";

    std::cout << "Done. ";
    return 0;
}

void testWithChars() {
    LinkedList<char> characterList;
    // Make a linked list of 7 characters.
    char charTest[] = { 'g', 'f', 'e', 'd', 'c', 'b', 'a' };
    for (char c : charTest) {
        characterList.addItem(c);
    }
    std::cout << "New linked list with 7 members: ";
    characterList.print();
    std::cout << "\n";

    // Remove the first three characters.
    std::cout << "Removed first three members: ";
    for (int i = 0; i < 2; i++) characterList.popItem();
    char charLastPopped = characterList.popItem();
    characterList.print();
    std::cout << "\n";
    std::cout << "The character most recently removed is: " << charLastPopped << "\n";

    // Insert at Position Tests
    characterList.insertAtPos('1', 0);
    std::cout << "Linked list after insertion to index 0: ";
    characterList.print();
    std::cout << "\n";

    characterList.insertAtPos('4', 3);
    std::cout << "Linked list after insertion to index 3: ";
    characterList.print();
    std::cout << "\n";

    characterList.insertAtPos('X', 100);
    std::cout << "Linked list after insertion to index 100: ";
    characterList.print();
    std::cout << "\n";
}

void testWithStrings() {
    LinkedList<std::string> characterList;
    // Make a linked list of 7 strings.
    std::string stringTest[] = { "Goat", "Fox", "Eagle", "Dog", "Cat", "Bird", "Ant" };
    for (std::string s : stringTest) {
        characterList.addItem(s);
    }
    std::cout << "New linked list with 7 members: ";
    characterList.print();
    std::cout << "\n";

    // Remove the first three characters.
    std::cout << "Removed first three members: ";
    for (int i = 0; i < 2; i++) characterList.popItem();
    std::string lastPopped = characterList.popItem();
    characterList.print();
    std::cout << "\n";
    std::cout << "The string most recently removed is: " << lastPopped << "\n";

    // Insert at Position Tests
    characterList.insertAtPos("ONE", 0);
    std::cout << "Linked list after insertion to index 0: ";
    characterList.print();
    std::cout << "\n";

    characterList.insertAtPos("FOUR", 3);
    std::cout << "Linked list after insertion to index 3: ";
    characterList.print();
    std::cout << "\n";

    characterList.insertAtPos("LAST", 100);
    std::cout << "Linked list after insertion to index 100: ";
    characterList.print();
    std::cout << "\n";
}