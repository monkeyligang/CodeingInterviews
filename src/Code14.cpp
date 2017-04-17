/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//两个指针，一个指针先向后移动到n-k的位置，然后第二个指针和第一个指针一起向后移动
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(k<=0||pListHead == NULL)
            return NULL;
        ListNode *pre=pListHead;
        ListNode *end=pListHead;
        while(k>1){
            if(end->next!=NULL){
                end = end->next;
            }
            else 
                return NULL;
            k--;
        }
        while(end->next!=NULL){
            end = end->next;
            pre = pre->next;
        }
        return pre;
    }
};


