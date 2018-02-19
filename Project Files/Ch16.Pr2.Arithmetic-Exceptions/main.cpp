#include <iostream>
#include <string>
#include <cmath>

// Declarations.
int IntSqrt(int);
class NotAPerfectSquare {
private:
    int x;
public:
    NotAPerfectSquare(int nx) { x = nx; }
    int getVal() const { return x; }
};

int main() {
    int val, root;

    std::cout << "Please enter a perfect square: ";
    std::cin >> val;
    std::cout << "\n";

    try {
        root = IntSqrt(val);
        std::cout << val << " is a perfect square! \n";
        std::cout << "Its square root is " << root << ". \n";
    } catch(NotAPerfectSquare x) {
        std::cout << x.getVal() << " is a NOT perfect square. \n";
    }

    return 0;
}

// Implementations.
int IntSqrt(int square) {
    int root;
    root = static_cast<int>( sqrt(square) );
    if (root * root == square) {
        return root;
    } else {
        throw NotAPerfectSquare(square);
    }
}