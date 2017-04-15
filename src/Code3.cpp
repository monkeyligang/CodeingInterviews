//输入一个链表，从尾到头打印链表每个节点的值

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int> s;
        vector<int> result;
        while(head){
            s.push((*head).val);
            head = head->next;
        }
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};
