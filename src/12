/*
递归地进行调用，exponent为偶数与奇数时分情况而讨论
一定要考虑到边界情况
exponent可能为负 可能为正

*/
class Solution {
public:
	double Power(double base, int exponent) {
		int ex = abs(exponent);//将数转为正数
		if (exponent == 0)   
			return 1;
		if (exponent == 1)
			return base;
		double result = Power(base, ex >> 1);
		result *= result;
		if ((ex & 1) == 1)   //判断是否为奇数
			result *= base;
		if (exponent<0)
			result = 1.0 / result;
		return result;
	}
};
