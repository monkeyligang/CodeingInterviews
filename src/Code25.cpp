/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/


   /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;       //判断头节点是不是空，如果为空，返回空
        RandomListNode* newlist = pHead;
        while(newlist){       //进行复制，next指针得到
            RandomListNode* newNode = new RandomListNode(newlist->label); //复制
            newNode->next = newlist->next;
            newlist->next = newNode;
            newlist = newNode->next; 
        }
        newlist = pHead;
        while(newlist){                //复制特殊指针,从左向右遍历
            RandomListNode* node = newlist->next;
            if(newlist->random){
                 node->random = newlist->random->next;
            }
            newlist=node->next;
        }

        newlist = pHead;      //置到头,进行拆分，
        //先分出原链表和新链表的头
        RandomListNode* newNodeHead;
       
        if(newlist){
            newNodeHead = newlist->next; //复制链表的头
            newlist->next = newNodeHead->next;
            newlist =newlist->next;       
        }
         RandomListNode* newNodeTmp = newNodeHead; //保留头
        while(newlist){
            newNodeTmp->next = newlist->next;
            newNodeTmp = newNodeTmp->next;      //新链表链接
            newlist->next = newNodeTmp->next;
            newlist = newlist->next;    
        }
        return newNodeHead; //返回复制链表头
        
    }
};

//三步法1

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    //复制原始链表的任一节点N并创建新节点N'，再把N'链接到N的后边
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=new RandomListNode(0);
            pCloned->label=pNode->label;
            pCloned->next=pNode->next;
            pCloned->random=NULL;
              
            pNode->next=pCloned;
              
            pNode=pCloned->next;
        }
    }
    //如果原始链表上的节点N的random指向S，则对应的复制节点N'的random指向S的下一个节点S'
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=pNode->next;
            if(pNode->random!=NULL)
                pCloned->random=pNode->random->next;
            pNode=pCloned->next;
        }
    }
    //把得到的链表拆成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
    RandomListNode* ReConnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
          
        //初始化
        if(pNode!=NULL)
        {
            pClonedHead=pClonedNode=pNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
              
        }
        //循环
        while(pNode!=NULL)
        {
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
        }
          
        return pClonedHead;
          
    }
    //三步合一
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReConnectNodes(pHead);
    }
};
