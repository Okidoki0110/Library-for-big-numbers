#include "bignum.hpp"


std::string bignum_add(const std::string& a,const std::string& b)
{
    std::string result;

    
    unsigned int max_len = (a.size() > b.size()) ? a.size() : b.size(); 

    bool carry = 0;
    for(unsigned int i=0; i<max_len; i++)
    {
        int c = (i > a.size()-1 ) ? 0 : (a[a.size() - (i+1)] - '0');
        int d = (i > b.size()-1 ) ? 0 : (b[b.size() - (i+1)] - '0');

        int x = c + d + carry;

        if(x >= 10) { x-= 10; carry = 1;}
        else {carry=0;}

        result.insert(0,1,x + '0');
    }

    
if(carry){result.insert(0,1,'1');}


return result;
}



bignum::bignum()
{
    this->number = "0";
}

bignum::bignum(unsigned int n)
{ 
    if(n == 0) {
        this->number = "0";
        return;
    }
    while(n != 0) {
        char c = n % 10;
        n /= 10;
       // convert number in ASCII
        this->number.insert(0, 1, '0' + c);
    }
}

bignum::bignum(const bignum& n) { this->number = n.number; }

bignum::operator+(const bignum& n)
{
this->number = bignum_add(this->number,n.number);
}




bignum::~bignum(){ this->number.clear(); }




 







