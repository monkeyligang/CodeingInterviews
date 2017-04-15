//运用递归的思想
/*
逻辑运算的短路特性：
(表达式1）&&(表达式2) 如果表达式1为假，则表达式2不会进行运算，即表达式2“被短路”
(表达式1）||(表达式2) 如果表达式1为真，则表达式2不会进行运算，即表达式2“被短路”
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int Sum_Solution(int n) {
		int result = n;
		(n > 0) && (result+=Sum_Solution(n-1));
		return result;
	}
};

int main(){
	Solution s;
	cout << s.Sum_Solution(10);
	system("pause");
}
