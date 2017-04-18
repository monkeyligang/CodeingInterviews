/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//递归求法
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode* result=NULL; 
        if(pHead1->val<pHead2->val){
            result = pHead1;
            result->next = Merge(pHead1->next,pHead2);
        }
        if(pHead1->val>=pHead2->val){
            result = pHead2;
            result->next = Merge(pHead1,pHead2->next);
        }
        return result;
    }
};
//非递归求法
//另外新建一个链表，保留它的头节点，然后依次比较，值小的先插

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode *merge = new ListNode(0);
        ListNode *temp = merge;
        while(pHead1&&pHead2){
            if(pHead1->val<pHead2->val){
                temp->next = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                temp->next = pHead2;
                pHead2 = pHead2->next;
            }
            temp = temp->next;
        }
        if(pHead1)
            temp ->next =pHead1;
        if(pHead2)
            temp ->next =pHead2;
        return merge->next;        
    }
};



