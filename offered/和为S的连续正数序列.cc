/*
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

输出描述:
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        
        vector<vector<int>> result;
        for (int a1 = 1;a1 <= sum / 2; a1++){
            for (int n = 1;n < sum; n++) {
                //int temp = n * a1 + n*(n-1)/2;
                int temp = (sum - n * a1) * 2;
                //if (temp < n * (n-1)) continue;
                if (temp == n*(n-1)) {
                    vector<int> cand;
                    for (int i = 0;i < n;i++) {
                        cand.push_back(a1+i);
                    }
                    result.push_back(cand);
                }
            }
        }
        return result;
    }

//=======================================================
//左神的思路，双指针问题
//当总和小于sum，大指针继续+
//否则小指针+
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > allRes;
        int phigh = 2,plow = 1;
         
        while(phigh > plow){
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            if( cur < sum)
                phigh++;
             
            if( cur == sum){
                vector<int> res;
                for(int i = plow; i<=phigh; i++)
                    res.push_back(i);
                allRes.push_back(res);
                plow++;
            }
             
            if(cur > sum)
                plow++;
        }
         
        return allRes;
    }
};

};
