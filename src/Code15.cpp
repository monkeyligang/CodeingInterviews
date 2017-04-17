/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//两种思路
//1,三个指针的滑动
//2,新建一个链表，把这个链表的每个值都进行头插

/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
         if(pHead == NULL)
             return NULL;
         if(pHead->next=NULL)
             return pHead;
         ListNode *pre=pHead,*cur=pHead->next,*post=cur->next;
         while(post){
             cur->next =pre;
             pre =cur;
             cur = post;
             post = post->next;
         }
         cur->next = pre;
         pHead->next = NULL;
         return cur;
    }
};*/
/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        if (pHead->next == NULL) return pHead;
          
        ListNode *pBefore = pHead, *p = pHead->next, *pAfter = p->next;
        while (pAfter) {
            p->next = pBefore; // reverse
            pBefore = p;
            p = pAfter;
            pAfter = pAfter->next;
        }
        p->next = pBefore;
        pHead->next = NULL;
        return p;
    }
};*/

//头插法
/*
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL) return NULL;
        ListNode* head = pHead;
        pHead = pHead->next;
        head->next = NULL;
        while (pHead) {
            ListNode *next = pHead->next;
            pHead->next = head;
            head = pHead;
            pHead = next;
        }
        return head;
    }
};*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        ListNode *newHead = pHead; //链表头节点给新节点
        pHead=pHead->next;
        newHead->next=NULL;
        
        while(pHead){
            ListNode *newnode = pHead->next;
            pHead->next = newHead;
            newHead=pHead;          
            pHead = newnode;
        }
        return newHead;
    }
};



