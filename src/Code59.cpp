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
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>>result;
        if(!pRoot)
            return result;
        stack<TreeNode*>s[2];//两个栈，一个奇数层栈，一个偶数层栈
        int cur = 0;
        int next = 1;
        s[cur].push(pRoot);
        vector<int> ve; //每一层的存入
        while(!s[cur].empty()||!s[next].empty()){
            TreeNode* node = s[cur].top();     //从当前栈中出栈，存入行vector中
            s[cur].pop();
            ve.push_back(node->val);
            if(cur==0){      //cur==0 代表偶数行，进栈顺序从左向右
                if(node->left)
                    s[next].push(node->left);
                if(node->right)
                    s[next].push(node->right);
            }
            else{           //cur==0 代表奇数行，进栈顺序从右向左
                if(node->right)
                    s[next].push(node->right);
                if(node->left)
                    s[next].push(node->left);
            }
            if(s[cur].empty()){   //每一层打印完毕，然后换层打印
                result.push_back(ve);
                ve.clear();
                cur = 1-cur;
                next = 1-next;
            }
        }
        return result;        
    }
    
};
