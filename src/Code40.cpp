class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2)
            return;
        sort(data.begin(),data.end());//排序
        int flag = false;
        for(int i=0;i<data.size();i++){
            if(data[i] == data[i+1])
                i++;
            else if(!flag){
                *num1 = data[i];
                flag = true;
            }
            else if(flag)
                *num2 = data[i];
            
        }
    }
};
