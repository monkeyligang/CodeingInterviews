//重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//首先寻找根节点，找到根节点后，通过中序遍历的序列把左子树和右子树找出来，然后进行递归建立二叉树

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0)
            return NULL;
        
        TreeNode* tree = new TreeNode(pre[0]);
        vector<int> leftpre;
        vector<int> leftvin;
        vector<int> rightpre;
        vector<int> rightvin;
         
        int leftlen=0;
        for(;vin[leftlen]!=pre[0];leftlen++){
            leftpre.push_back(pre[leftlen+1]);
            leftvin.push_back(vin[leftlen]);            
        }
        leftlen++;
        for(;leftlen<pre.size();leftlen++){
            rightpre.push_back(pre[leftlen]);
            rightvin.push_back(vin[leftlen]);
            
        }
        
        tree->left= reConstructBinaryTree(leftpre,leftvin);
        tree->right= reConstructBinaryTree(rightpre,rightvin);
        return tree;
    }
};