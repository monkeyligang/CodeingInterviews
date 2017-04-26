class Solution {
private:
    bool is=true;;
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)
            return is;
        TreeDepth(pRoot);
        return is;
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        if(abs(left-right)>1)
            is = false;
        return left>right?left+1:right+1;
    }

};



bool IsBalanced(BinaryTreeNode* pRoot, int* depth)
{
	if(pRoot== NULL)
	{
		*depth = 0;
		return true;
	}

	int nLeftDepth,nRightDepth;
	bool bLeft= IsBalanced(pRoot->m_pLeft, &nLeftDepth);
	bool bRight = IsBalanced(pRoot->m_pRight, &nRightDepth);
	
	if (bLeft && bRight)
	{
		int diff = nRightDepth-nLeftDepth;
		if (diff<=1 || diff>=-1)
		{
			*depth = 1+(nLeftDepth > nRightDepth ? nLeftDepth : nRightDepth);
			return true;
		}
	}
	
	return false;
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
	int depth = 0;

	return IsBalanced(pRoot, &depth);
}
