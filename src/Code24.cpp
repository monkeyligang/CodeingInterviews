/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//广度遍历是借用队列的思想

//借用深度遍历的思想，然后对每一次遍历的序列进行记录，最后把所有的可行成果进行保留

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> result;
        vector<int>record;
        if(root)
            DfsFind(root,expectNumber,result,record);
        return result;
    }
    void DfsFind(TreeNode *root,int rest,vector<vector<int>>& result,vector<int>& re){
        re.push_back(root->val);                     //将节点的值进行记录
        if(!root->left&&!root->right){            //找到叶子节点，看找到的这条路径是不是需要的那条，如果是加入到结果中去
            if(root->val == rest){
                result.push_back(re);
            }
        }
            
        if(root->left){                     //遍历左子树
            DfsFind(root->left,rest-root->val,result,re);
        }
        if(root->right){                    //遍历右子树
            DfsFind(root->right,rest-root->val,result,re);
        }
        re.pop_back();     //如果叶子节点不是想要的，则退一格
    }
};
