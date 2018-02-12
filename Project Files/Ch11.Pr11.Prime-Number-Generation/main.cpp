#include <iostream>
#include <vector>
#include "IsComposite.h"

void printVector(const std::vector<int> &, int = 5);

int main() {
    int limit;
    std::cout << "Please enter a number greater than 1: ";
    std::cin >> limit;
    std::cout << "\n";

    if (limit <= 1) {
        std::cout << "Invalid number. Re-run the program \n";
        std::cout << "and pass a proper argument";
        return -1;
    }

    // Fill the vector with 2 to limit
    std::vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        primes.push_back(i);
    }

    // Remove all composite numbers from vector
    auto fi = std::remove_if(primes.begin(), primes.end(), IsComposite());
    /* Lambda version of the above statement.
    auto fi = std::remove_if(primes.begin(), primes.end(),
        [ ](int n){
            for (int i = 2; i < n; i++) {
                if (n % i == 0) {
                    return true;
                }
            }
            return false;
        }
    );
    */
    primes.erase(fi, primes.end());

    std::cout << "The primes found under this number are: \n";
    for (int i : primes) {
        std::cout << i << " ";
    }
    std::cout << "\n\n";

    if (primes.back() == limit) {
        std::cout << "This number, " << limit << ", is also prime.";
    } else {
        std::cout << "This number, " << limit << ", is NOT prime.";
    }
    return 0;
}
