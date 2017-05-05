/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
/*

具体思想是，两个指针fast和slow，fast以slow两倍速度前进，
如果没有环，那么fast和slow不会相遇此时返回null；如果有环，那fast和slow肯定会再次相遇
相遇的时候，fast刚好比slow多走了一圈环的长度。 当fast与slow相遇时，fast走过的距离为a + b + c + b，
而slow走过的距离为a + b，因为fast是slow速度的两倍，则有a+b+c+b = 2*(a+b)，登出a=c;此时slow节点所处X处
到环起点Y处的距离a和X节点到Y处距离c其实是相等的，此时第三个指针p从x处，以和slow指针
相同的速度前进，当它两相遇时，即为环的起点Y处！

*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead)//如果链表为空返回空
            return NULL;
        ListNode* slow=pHead;      //慢指针
        ListNode* fast=pHead;//快指针
        while(slow!= NULL && fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* temp = pHead;
                while(temp!=slow){
                    temp =temp->next;
                    slow =slow->next;
                }
                return temp;
            }

        }
        return NULL;
    }
};
