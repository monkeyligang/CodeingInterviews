/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	
};*/
//利用队列的思想进行遍历，然后得到最终结果
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> result;//存放打印出来的结果
       if(root==NULL)
           return result;      
       queue<TreeNode*> qe;      //先进先出
       qe.push(root);           //先将根节点入队
       while(!qe.empty()){          //对不为空，则出对来找向下进行遍历
           TreeNode *node = qe.front();
           qe.pop();
           result.push_back(node->val); 
           if(node->left){
               qe.push(node->left);               
           }
           if(node->right){
               qe.push(node->right);               
           }
       }
        return result;
    }
};
