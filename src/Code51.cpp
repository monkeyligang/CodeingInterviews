class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int>left(A.size(), 0);
		vector<int>right(A.size(), 0);
		//结果
		vector<int>result;
		if (A.size() == 0)
			return result;
		left[0] = 1;
		//下三角
		for (int i = 1; i<A.size(); i++)
			left[i] = left[i - 1] * A[i - 1];
		//上三角
		right[A.size() - 1] = 1;
		for (int j = A.size() - 2; j >= 0; j--)
			right[j] = right[j + 1] * A[j + 1];

		for (int i = 0; i<A.size(); i++)
			result.push_back(left[i] * right[i]);
		return result;
	}
};

//参考思路，构造矩阵，得到上下三角的值
//http://blog.csdn.net/quzhongxin/article/details/47183965
