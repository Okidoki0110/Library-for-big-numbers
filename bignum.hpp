#ifndef __BIGNUM_INCLUDED__
#define __BIGNUM_INCLUDED__

#include <string>

class bignum {
    public:
            bignum();
            bignum(unsigned int);
            bignum(const bignum&);

            operator+(const bignum&);

            ~bignum();

    protected:
            std::string number;

};


#endif