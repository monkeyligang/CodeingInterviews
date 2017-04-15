/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

/*
递归调用判断各子树各个子树是不是两一颗树的子结构
*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1 == NULL || pRoot2 == NULL)
            return false;
        return isSubtree(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
    bool isSubtree(TreeNode* p1,TreeNode* p2){
        if(p2 == NULL)
            return true;
        if(p1 == NULL)
            return false;
        return (p1->val == p2->val)&&isSubtree(p1->left,p2->left)&&isSubtree(p1->right,p2->right);
    }
};
