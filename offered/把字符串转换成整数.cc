/*
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入

+2147483647
    1a33
输出

2147483647
    0
*/

class Solution {
public:
    int StrToInt(string str) {
        int sz = str.size();
        int i = 0;
        long result = 0;
        bool negFlag = false;

        while(i < sz && str[i] == ' ') i++;
        if (str[i] == '-') {
            negFlag = true;
            i++;
        }
        if (str[i] == '+') i++;

        while(i < sz) {
            if (str[i] >= '0' && str[i] <= '9') {
                result = result * 10 + (str[i]-'0');
            } else {
                break;
            }
            i++;
        }
        
        if (i < sz) return 0;
        else {
            result = negFlag ? -result : result;
            if (result > INT32_MAX) result = INT32_MAX;
            if (result < INT32_MIN) result = INT32_MIN;
            return result;
        }
    }
};
