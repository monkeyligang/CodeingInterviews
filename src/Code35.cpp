class Solution {
private:
   	long long result = 0; 
public:
	int InversePairs(vector<int> data) {
		if (data.size() <= 0)
			return 0;
		InverseCount(data, 0, data.size() - 1);
		return result % 1000000007;
	}
	void InverseCount(vector<int>&data, long long start, long long end){
		if (start<end){
			long long mid = (start + end) / 2; //取中间值
		    InverseCount(data, start, mid);
			InverseCount(data, mid + 1, end);
			MergeCount(data, start, mid, end);
		}
	}
	//采用倒归并
	void MergeCount(vector<int>&data, long long start, long long mid, long long end){
		long long i = mid;
		long long j = end;
		vector<int>temp;
		while (i >= start&&j > mid){
			if (data[i] > data[j]){
				temp.push_back(data[i--]);
				result += j - mid;
			}
			else{
				temp.push_back(data[j--]);
			}
		}
		while (i >= start){
			temp.push_back(data[i--]);
		}
		while (j > mid){
			temp.push_back(data[j--]);
		}
		for (int i = 0; i < temp.size(); i++){
			data[end - i] = temp[i];
		}
	}
};
