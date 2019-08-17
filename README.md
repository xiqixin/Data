# Data
数据结构

## 单链表逆序输入到一个数组中返回
     class Solution {
     public:
        vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        if(!head){
            return {};
        }
        while(p)
        {
            v.push_back(p->val);
            p=p->next;
        }
        reverse(v.begin(),v.end());
        return v;
        }
    };
## 两个栈实现一个队列
     class Solution
     {
     public:
          void push(int node) {
          stack1.push(node);
           }

           int pop() {
               if(stack2.empty())
               {
                   while(!stack1.empty())
                   {
                       int tmp=stack1.top();
                       stack2.push(tmp);
                       stack1.pop();
                    }
               }
               int m=stack2.top();
               stack2.pop();
               return m;;
          }

    private:
          stack<int> stack1;//存放入队元素
          stack<int> stack2;//存放出队元素
    };
 ## 输出链表的倒数第 K 个节点
     class Solution {
     public:
           ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
                 ListNode* p1=pListHead;
                 ListNode* p2=pListHead;//先走k步
                 while(p2!=NULL&&k--)
                 {
                     p2=p2->next;
                }
                if(p2==NULL)
               {
                  if(k==0)
                  {
                      return p1;
                  }
                  return NULL;
               }
               while(p2!=NULL)
               {
                  p1=p1->next;
                  p2=p2->next;
               }
               return p1;
         }
     };
 ## 剑指offer
