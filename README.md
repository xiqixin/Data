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
 ## 输出字符串中出现次数大于等于n/2的数
     //输出数字串中出现次数大于等于n/2的数
     #include <iostream>
     #include <stdio.h>
     #include <algorithm>
     using namespace std;

     int main()
     {
	     vector<int> v;//用于存放输入的数组
	     int tmp;
          while (1)
	     {
		     scanf("%d ", &tmp);
		     fflush(stdin);
		     v.push_back(tmp);
	     }
	     sort(v.begin(), v.end());
          int i = len / 2;
	     cout << v[i] << endl;
	     return 0;
     }
 ## 进制转换
    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;  
    int main()
    {
	vector<int> v;
	int m, n;
	cin >> m >> n;
	if (n == 10 || m == 0)
	{
		cout << m;
		return 0;
	}
	while (m)
	{
		v.push_back(m%n);
		m /= n;
	}
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] > 9) {

			if (v[i] == 10)
				cout << "a";

			if (v[i] == 11)
				cout << "b";

			if (v[i] == 12)
				cout << "c";

			if (v[i] == 13)
				cout << "d";

			if (v[i] == 14)
				cout << "e";

			if (v[i] == 15)
				cout << "f";

		}ekse{
            cout << v[i]; 
		}
	}
	return 0;
     }
 ## 将两个有序链表合并为一个新的有序链表并返回
    /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     struct ListNode *next;
    * };
	*/
	struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
		if (p1 == NULL)
		{
			return p2;
		}
		if (p2 == NULL)
		{
			return p1;
		}
		struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* p0 = new;
		struct ListNode* p1 = l1;
		struct ListNode* p2 = l2;
		while (p1 != NULL && p2 != NULL)
		{
			if (p1->val<p2->val)
			{
				new = p1;
				new = new->next;
				p1 = p1->next;
			}
			if (p1->val == p2->val)
			{
				new = p1;
				new = new->next;
				new = p2;
				new = new->next;
				p1 = p1->next;
				p2 = p2->next;
			}
			if ((p1->val)>(p2->val))
			{
				new = p2;
				new = new->next;
				p2 = p2->next;
			}
		}
		if (p1 == NULL && p2 != NULL)
		{
			new = p2;
		}
		if (p2 == NULL && p1 != NULL)
		{
			new = p1;
		}
		return p0;
  	}
 ## 平时的练习
