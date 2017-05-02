/*
分析：
（1）十进制加法分三步：(以5+17=22为例)
1. 只做各位相加不进位，此时相加结果为12(个位数5和7相加不进位是2，十位数0和1相加结果是1)；
2. 做进位，5+7中有进位，进位的值是10；
3. 将前面两个结果相加，12+10=22
（2）这三步同样适用于二进制位运算
1.不考虑进位对每一位相加。0加0、1加1结果都是0,0加1、1加0结果都是1。这和异或运算一样；
2.考虑进位，0加0、0加1、1加0都不产生进位，只有1加1向前产生一个进位。可看成是先做位与运算，然后向左移动一位；
3.相加过程重复前两步，直到不产生进位为止。
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        int a;
        int b;
        //进位和不进位
        while(num2){
            a=num1^num2;
            b=(num1&num2)<<1;
            num1 = a;
            num2 = b;
        }
        return num1;
    }
};
