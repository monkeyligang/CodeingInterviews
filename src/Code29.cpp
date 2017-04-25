class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> result; //结果数组
		if (input.empty()|| k>input.size() || k<0)
			return result;
		quicksort(input, 0, input.size() - 1, k);
		for (int i = 0; i < k; i++){
			result.push_back(input[i]);
		}
		return result;
	}
	//快排   
	void quicksort(vector<int>& input, int start, int end, int k){
		if (start<end){
			int index = getMid(input, start, end);
			if (index != k - 1){
				if (index < k - 1){
					quicksort(input, index + 1, end, k);
				}
				else{
					quicksort(input, start, index-1, k);
				}
			}
		}
	}
	//快排获取分割点
	int getMid(vector<int>& input, int start, int end){
		int left = start, right = end;
		int x = input[left];
		while (left<right){
			while (input[right] >= x && left<right){
				right--;
			}
			if (left<right){
				input[left] = input[right];
				left++;
			}
			while (input[left] <= x && left<right){
				left++;
			}
			if (left<right){
				input[right] = input[left];
				right--;
			}

		}
		input[left] = x;
		return left;
	}

};
