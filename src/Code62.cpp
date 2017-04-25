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
//中序遍历，寻找第k个元素
/*class Solution {
private:
    int count = 0;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k<=0)
            return NULL;
        else{
            TreeNode* left = KthNode(pRoot->left,k);
            if(left)
                return left;
            if(count++ == k-1)
               return pRoot;
            TreeNode* right = KthNode(pRoot->right,k);
            if(right)
                return right;
        }
        return NULL;
    }
    
};*/

class Solution {
private:
    vector<TreeNode*>result;
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k<=0)
            return NULL;
        inorder(pRoot);
        if(result.size()<k)
            return NULL;
        return result[k-1];
    }
    void inorder(TreeNode* pRoot){
        if(pRoot){
            inorder(pRoot->left);
            result.push_back(pRoot);
            inorder(pRoot->right);
        }
    }
    
};
