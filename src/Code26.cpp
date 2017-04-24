/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;https://www.nowcoder.com/profile/407594
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

//对于二叉搜索树，左子树比根节点小，右子树比根节点大，那么根据这个性质，中序遍历过后就是一个有序的链表；
class Solution {

private:
    TreeNode* head =NULL;
    TreeNode* node =NULL;
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)   //先判断二叉树是否为空，为空返回空
            return NULL;
        create(pRootOfTree);
        return head;
    }
    void create(TreeNode* root){   //中序遍历
        if(root==NULL)
            return;
        create(root->left);
        if(head == NULL){            //寻找头节点，head还未赋值，那次寻找到的节点即为头节点
            head = root;
            node = head;
        }
        else{                        //建立双向链表，利用左右指针进行指定
            node->right = root;
            root->left = node;
            node = root;
        }
        create(root->right);
    }
};
