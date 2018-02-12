//
// Created by TheLoneWoof on 2/11/18.
//

#ifndef CH11_PR11_PRIME_NUMBER_GENERATION_ISPRIME_H
#define CH11_PR11_PRIME_NUMBER_GENERATION_ISPRIME_H

class IsComposite {

public:
    bool operator()(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return true;
            }
        }
        return false;
    }

};


#endif //CH11_PR11_PRIME_NUMBER_GENERATION_ISPRIME_H
