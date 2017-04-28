/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
       if(!pHead)         //如果链表为空，返回空
           return NULL;
        if(!pHead->next) //如果头结点的下一个结点为空，返回当前结点
            return pHead;
        ListNode *root = new ListNode(-1);//新建一个链表
        ListNode *move = root; //保留新建链表的头，记录当前处理结点
        while(pHead&&pHead->next){ //如果结点与节点的下个结点不为空
            if(pHead->val == pHead->next->val){ //寻找重复节点，将重复节点跳过，进行删除
                while(pHead->next && pHead->val==pHead->next->val){
                    pHead=pHead->next;
                }
                move->next=pHead->next;//指向下一个节点，但是move->next可能也是重复结点，因此暂时不要移动到下一个结点
            }
            else{ //如果不重复则保留下来，move向后移动
                move->next =pHead;
                move = move->next;
            }
            pHead = pHead->next;
        }
        return root->next;//返回结点的头
    }
};
