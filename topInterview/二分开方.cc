#include <iostream>
#include <vector>

using namespace std;

int binary_sqrt(int x) {
    if (x < 0) return -1;
    
    int low = 0; 
    int high = x;
    int mid = (low + high) / 2;
    int last;
    double eps = 0.5;
    
    do
    {
        if (mid*mid == x) return mid;
        else if(mid*mid<x) low=mid;
        else high=mid;

        last=mid;
        mid=(low+high)/2;
    } while (abs(last-mid)>eps);
    
    return mid;
}

int main() {
    cout << binary_sqrt(9) << endl;
    return 0;
}
