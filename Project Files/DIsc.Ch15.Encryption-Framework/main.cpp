// This program demonstrates an application
// of pure virtual functions.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Encryption
{
protected:
    ifstream inFile;
    ofstream outFile;
public:
    Encryption(const string& inFileName, const string& outFileName);
    virtual  ~Encryption();
    // Pure virtual function
    virtual char transform(char ch) const = 0;
    virtual char untransform(char ch) const = 0;
    // Do the actual work.
    virtual void encrypt() final;
    // Virtual and Final means that this function
    // cannot be hidden nor overridden.
    virtual void decrypt() final;
};

//**************************************************
// Constructor opens the input and output file.    *
//**************************************************
Encryption::Encryption(const string& inFileName, const string& outFileName)
{
    inFile.open(inFileName);
    outFile.open(outFileName);
    if (!inFile)
    {
        cout << "The file " << inFileName
             << " cannot be opened.";
        exit(1);
    }
    if (!outFile)
    {
        cout << "The file " << outFileName
             << " cannot be opened.";
        exit(1);
    }
}

//**************************************************
//Destructor closes files.                         *
//**************************************************
Encryption::~Encryption()
{
    inFile.close();
    outFile.close();
}

//*****************************************************
//Encrypt function uses the virtual transform         *
//member function to transform individual characters. *
//*****************************************************
void Encryption::encrypt()
{
    char ch;
    char transCh;
    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = transform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }
}

void Encryption::decrypt() {
    char ch;
    char transCh;
    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = untransform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }
}

// The subclass simply overides the virtual
// transformation function
class SimpleEncryption : public Encryption
{
public:
    char transform(char ch) const override
    {
        return ch + 1;
    }
    char untransform(char ch) const override {
        return ch - 1;
    }
    SimpleEncryption(const string& inFileName, const string& outFileName)
            : Encryption(inFileName, outFileName)
    {
    }
};

int main()
{
    string choice;
    cout << "Do you want to ENCRYPT or DECRYPT? ";
    cin >> choice;
    cout << "\n";

    // Tranforms it to all uppercase.
    transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

    if (choice == "ENCRYPT") {
        string inFileName, outFileName;
        cout << "Enter name of file to encrypt: ";
        cin >> inFileName;
        cout << "Enter name of file to receive "
             << "the encrypted text: ";
        cin >> outFileName;
        SimpleEncryption obfuscate(inFileName, outFileName);
        obfuscate.encrypt();
    } else if (choice == "DECRYPT") {
        string inFileName, outFileName;
        cout << "Enter name of file to decrypt: ";
        cin >> inFileName;
        cout << "Enter name of file to receive "
             << "the decrypted text: ";
        cin >> outFileName;
        SimpleEncryption unobfuscate(inFileName, outFileName);
        unobfuscate.decrypt();
    } else {
        cout << "Error: Invalid choice.";
    }

    return 0;
}