// 第一阶和第二阶考虑过了，初始当前台阶为第三阶，向后迭代
 
// 思路：当前台阶的跳法总数=当前台阶后退一阶的台阶的跳法总数+当前台阶后退二阶的台阶的跳法总数
class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0)
            return 0;
        if(number == 1)
            return 1;
        if(number == 2)
            return 2;
        int result;
        int a=1,b=2;
        for(int i=3;i<=number;i++){
            result=a+b;
            a=b;
            b=result;
        }
        return result;
    }
};
