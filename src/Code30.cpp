//用sum记录累计值，result记录和最大
//基于思想：对于一个数A，若是A的左边累计数非负，那么加上A能使得值不小于A，认为累计值对
//          整体和是有贡献的。如果前几项累计值负数，则认为有害于总和，sum记录当前值。
//         此时 若和大于result则用result记录下来

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
			return 0;
		int result = 0x80000000;  //最终结果    0x80000000为最小的负数，如果全为负数，那么这个数可以进行比较
		int sum = 0;   //实时求和
		for (int i = 0; i<array.size(); i++){  //逐个遍历，然后求和
			if (sum <= 0){           //如果和小于0，那么就重新计算
				sum = array[i];
			}
			else{            
				sum += array[i];
			}
			if (sum >= result){
				result = sum;
			}
		}
		return result;
	}
};
