//具体分析一下，还是个斐波那契数列
class Solution {
public:
    int rectCover(int number) {
        if(number == 0)
            return 0;
        if(number<=2)
            return number;
        int a =1;
        int b =2;
        int result;
        for(int i=3;i<=number;i++){
            result = a+b;
            a = b;
            b = result;
        }
        return result;
    }
};
