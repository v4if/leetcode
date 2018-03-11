/*
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent ==0) return 1;
        
        double result = base;
        int exp = 1;
        while((exp<<1) <= abs(exponent)) {
            result *= result;
            exp = exp <<1;
        }
        while(exp < abs(exponent)) {
            result *= base;
            exp++;
        }
        return exponent >= 0 ? result : 1 / result;
    }
};

//====================================================
class Solution {
public:
    double Power(double base, int exponent) {
        long long p = abs((long long)exponent);
      double r = 1.0;
        while(p){
            if(p & 1) r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent < 0 ? 1/ r : r;
    }
};
