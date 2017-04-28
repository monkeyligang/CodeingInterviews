//数组里面，两个数相差越远，乘积越小，那么和就一个前一个后的找
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>result;
        if(array.size()<0){//边界判断，如果数据没有元素，那么直接返回空数组
            return result;
        }
        int start = 0; //前面的指针
        int end = array.size()-1; //尾指针
        while(start<end){
            if(array[start]+array[end] == sum){  //如果找到合适的两个数，则放入vector中，跳出循环
                result.push_back(array[start]);
                result.push_back(array[end]);
                break;
            }
            if(array[start]+array[end]<sum) //如果和小与给定值，那么前指针向后移动
                start++;
            if(array[start]+array[end]>sum) //如果和大于给定值，那么后指针向前移动
                end--;
        }
        return result;
    }
};
