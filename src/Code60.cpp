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
//层次遍历，逐层入队列
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>>result;//结果
            if(!pRoot){
               return result;
            }
            queue<TreeNode*>q;
            q.push(pRoot);
            while(!q.empty()){
                int start=0,end = q.size();
                vector<int>temp;
                while(start<end){
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                    start++;
                }
                result.push_back(temp);
            }
           return result;
        }
    
};
