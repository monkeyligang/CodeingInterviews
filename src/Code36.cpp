/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*
我们可以首先遍历两个链表得到它们的长度，就能知道哪个链表比较长，以及长的链表比短的链表多几个结点。
在第二次遍历的时候，在较长的链表上先走若干步，接着再同时在两个链表上遍历，找到的第一个相同的结点就是它们的第一个公共结点。
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2)
            return NULL;
        int len1 = getLength(pHead1);
        int len2 = getLength(pHead2);
        int diff = abs(len1-len2);
        if(len1>len2){
            while(diff){
                pHead1=pHead1->next;
                diff--;
            }
        }
        if(len1<len2){
            while(diff){
                pHead2=pHead2->next;
                diff--;
            }
        }
        while(pHead1&&pHead2&&pHead1!=pHead2){
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
        
    }
    int getLength(ListNode* root){
        int len = 0;
        while(root){
            len++;
            root = root->next;
        }
        return len;
    }
        
};
