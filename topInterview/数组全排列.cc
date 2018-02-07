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

//================================================
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& nums, vector<bool>& used, vector<int>& result){
    if (result.size() == nums.size()) {
        for (int d : result) cout << d << " ";
        cout << "\n";
    }
    
    int sz = nums.size();
    for (int i = 0;i < sz; i++) {
        if(i > 0 && result.empty() && nums[i] == nums[i-1]) i++;
        if (!used[i]) {
            used[i] = true;
            result.push_back(nums[i]);
            dfs(nums, used, result);
            used[i] = false;
            result.pop_back();
        }
    }
}
int main(){
    vector<int> nums{1,1,3,4};
    vector<int> result;
    vector<bool> used(nums.size(), false);
    dfs(nums, used, result);
}
