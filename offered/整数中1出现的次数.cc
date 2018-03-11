/*
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。
*/

//几个整圈+余数
#include<iostream>
#include<string>
using namespace std;

int NumbersOf1sFrom1ToN(unsigned int n)
{
    int cnt = 0;

    int base = 1;
    int curN = n;
    while(curN) {
        int remain = curN % 10;

        if (remain > 1) {
            cnt += base;
        } else if (remain == 1) {
            cnt += n - curN * base + 1;
        }

        curN = curN / 10;
        cnt += curN * base;

        base = base * 10;
    }
    return cnt;
}

int main()
{
    cout<<NumbersOf1sFrom1ToN(119)<<endl;

    return 0;
}

//===============================================
#include<iostream>
#include<string>
using namespace std;

int NumbersOf1sFrom1ToN(unsigned int n)
{
    int currentN = n;

    //计数器
    int cnt = 0;

    //商，计算该数字包含多少个10，100，1000等
    int quotient = 0;

    //余数，计算除去“整”的包含，剩下的数字包含的1的个数
    int remainder = 0;

    //每一轮循环中的权重，分别记录10，100，1000中包含多少个位1，十位1，百位1；
    int mult = 1;

    while(currentN)
    {
        quotient = currentN / 10;
        remainder = currentN % 10;

        //包含多少个10，100，1000，乘以对应的数量的个位1，十位1，百位1
        cnt += quotient * mult;

        //余数大于1，多加一个该轮下的权重
        if(remainder > 1)
        {
            cnt += mult;
        }
            //余数等于1
        else if(remainder == 1)
        {
            cnt += n - currentN * mult + 1;
        }


        currentN = currentN / 10;
        mult *= 10;
    }

    return cnt;
}

int main()
{
    cout<<"please enter the number N:"<<endl;
    unsigned int number = 119;


    cout<<"the number of 1s From 1 to N is:"<<endl;
    cout<<NumbersOf1sFrom1ToN(number)<<endl;

    return 0;
}
