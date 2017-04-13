//�ؽ�������
//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//����Ѱ�Ҹ��ڵ㣬�ҵ����ڵ��ͨ��������������а����������������ҳ�����Ȼ����еݹ齨��������

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