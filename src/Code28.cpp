/*//先把数组进行排序，然后从前向后依次判断是否出现次数超过数组长度的一半


//每次编程考虑边界情况，空的情况，只有一个值的情况，还有各种边界
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)  //边界值
			return 0;
		if (numbers.size() == 1) //只有一个元素，直接返回
			return numbers[0];
		sort(numbers.begin(),numbers.end()); //排序
		int start=0, end=0;
		int len = numbers.size(); 
		for (int i = 0; i < len-1; i++){         //从前向后找，每次计算每个数字出现的次数，大于一半则输出对应数字
			if (numbers[i + 1] == numbers[i]){          //两个指针一个指向每一个数字的头，一个指向尾部，如果数字不同则计算长度，与数组长度进行比较  
				end=i+1;
			}
			else{
				if (end - start + 1 > len / 2){
					return numbers[i];
				}
				start = i + 1;
				end = start;
			}
		}
		return 0;
	}
};*/
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
        //寻找数组中元素数量超过一半的数字
		int result = numbers[0];
		int count = 1; //计数
		for (int i = 1; i < numbers.size(); i++){  //先把第一个元素作为基准点，然后向后判断，相同计数加1，不同减1，如果有出现次数大于数字一半的数字，那么count就大于0
			if (count == 0){
				result = numbers[i];
				count = 1;
			}
			if (numbers[i] == result){
				count++;
			}
			else{
				count--;
			}
		}
		//判断是不是所需数字
		count = 0;
		for (int i = 0; i < numbers.size(); i++){
			if (numbers[i] == result)
				count++;
		}
		if (count>numbers.size() / 2)
			return result;
		return 0;
	}
};
