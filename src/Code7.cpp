//ì³²¨ÄÇÆõÊýÁÐ
class Solution {
public:
    int Fibonacci(int n) {
       if(n==0)
           return 0;
        else if(n<2)
            return 1;
        int f1 =1;
        int f2 =1;
        while(n>2){
            f2 = f1+f2;
            f1 = f2-f1;
            n--;
        }
        return f2;
    }
};
