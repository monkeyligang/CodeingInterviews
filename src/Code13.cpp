class Solution {
public:
	void reOrderArray(vector<int> &array) {	
		if (array.size() == 0)
			return;
		vector<int> result;
		for (int i = 0; i < array.size(); i++){
			if (array[i] & 0x1)
				result.push_back(array[i]);
		}
		for (int j = 0; j < array.size(); j++){
			if (!(array[j] & 0x1))
				result.push_back(array[j]);
		}
        array = result;
        result.clear();
	}
};
