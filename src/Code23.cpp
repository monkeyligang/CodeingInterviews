//后序遍历二叉排序树，会发现，最后一个节点的值为根节点的值，然后左子树上节点的值都小于根节点，然后右子树上的值都大于根节点，
//然后递归遍历左子树和右子树是否是我们想要的数值

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
			return false;
		return IsPost(sequence, 0, sequence.size() - 1);
	}
	bool IsPost(vector<int>sequence, int start, int end){
		if (start >= end)
			return true;
		int mid = end; //找出左子树和右子树的分割点
        while (mid>start && sequence[mid-1] > sequence[end])  //从后向前找完右子树
			mid--;
  		for (int j = mid-1;j>-1;j--){
			if (sequence[j] > sequence[end])
				return false;
		}
	    return IsPost(sequence, start, mid-1) && IsPost(sequence, mid, end-1);
	}
};
