#include <bits/stdc++.h>
using namespace std;
void perm(int list[], int k, int m)
{
    if (k==m)
    {
        copy(list,list+m,ostream_iterator<int>(cout," "));
        cout<<endl;
        return;
    }
 
    for (int i=k; i<m; i++)
    {
        swap(list[k],list[i]);
        perm(list,k+1,m);
        swap(list[k],list[i]);
    }
}
int main(){
    int list[]={1,2,3,4};
    perm(list,0,4);
}
