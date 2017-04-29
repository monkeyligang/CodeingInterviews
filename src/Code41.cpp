/*
用两个数字begin和end分别表示序列的最大值和最小值，
首先将begin初始化为1，end初始化为2.
如果从begin到end的和大于s，我们就从序列中去掉较小的值(即增大begin),
相反，只需要增大end。
终止条件为：一直增加begin到(1+sum)/2并且end小于sum为止
*/
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        vector<int>ve;
        if(sum<3)
            return result;
        int small = 1;
        int big = 2;
        int sumtemp = small+big;//计算和
        int threshold = (1+sum)/2;//给定一个阈值，使得small不会超过
        //当前和大于sum前面后移  小于加一位 
        while(small<big&&big<sum){
            while(sumtemp>sum){
                sumtemp-=small;
                small++;
            }
            if(sumtemp == sum){
                copy(small,big,result);
            }
            big++;
            sumtemp+=big;
        }
        return result;
    }
    void copy(int start,int end,vector<vector<int>>& result){
        vector<int>temp;
        for(;start<=end;start++)
            temp.push_back(start);
        result.push_back(temp);
    }
    
};
