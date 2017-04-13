/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
/*
一看到这种题，就有感觉要用递归来做
判断两个子树是否对称
左子树的左子树应该等于右子树的右子树
左子树的右子树应该等于右子树的左子树
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        return isSame(pRoot->left,pRoot->right);
    }
    bool isSame(TreeNode *left,TreeNode *right){
        if(left == NULL)
            return (right==NULL);
        if(left!=NULL && right== NULL)
            return false;
        else if(left->val == right->val){
            return isSame(left->left,right->right)&&isSame(left->right,right->left);
        }
        return false;
    }
};
