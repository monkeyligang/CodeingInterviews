//计算1出现的次数
//逐位进行分离，得到低位，现有位 和高位
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int low = 0;
		int cur = 0;
		int high = 0;
		int count = 0;
		int flag = 1;//取位flag，1表示先计算个位
		while (n / flag != 0){
			low = n - (n / flag)*flag;
			cur = (n / flag) % 10; //确定当前位是几
			high = n / flag / 10;
			if (cur == 0){               //当前位是0，出现1的个数等于高位数字乘以当前位数
				count += high*flag;
			}
			else if (cur == 1){         //当前位是1，出现1的个数等于高位数字乘以当前位数 再加上 低位出现次数
				count += high*flag + low + 1;
			}
			else{       //当前位大于1，等于更高位数字加1，再乘以位数
				count += (high + 1)*flag;
			}
			flag *= 10;
		}
		return count;
	}
};
