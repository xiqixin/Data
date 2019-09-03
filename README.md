# Data
数据结构
## 求二进制中1的个数
	public class Solution {
    	public int NumberOf1(int n) {
       		 int count = 0;
        	 while(n!= 0){
          	     count++;
         	  	 n = n & (n - 1);
         	}
        	return count;
    	}
	}
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
  ##  根据前序和中序创建二叉树
     //链接：https://www.nowcoder.com/questionTerminal/8a19cbe657394eeaac2f6ea9b0f6fcf6?f=discussion
	public class Solution {
   	      public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
       		     TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        	     return root;
   		 }
    	     //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    	    private TreeNode reConstructBinaryTree(int [] pre,int startPre,int endPre,int [] in,int startIn,int endIn) {
              	if(startPre>endPre||startIn>endIn)
          	  return null;
       	        TreeNode root=new TreeNode(pre[startPre]);
                for(int i=startIn;i<=endIn;i++){
                    if(in[i]==pre[startPre]){
                       root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
                       root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
                      break;
                    }
                }        
                return root;
   	   }
	}
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
 ## 二叉树的最小深度
	 /**
	 * Definition for a binary tree node.
	 * struct TreeNode {
 	*     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Solution {
	public:
   	  int minDepth(TreeNode* root) {
       	 if(root==nullptr)
       	 {
             return 0;
       	 }
       	 int dl = minDepth(root->left);
        	int dr = minDepth(root->right);
       	 if(root->left==nullptr||root->right==nullptr)
          	  return dl+dr+1;
        
        	return 1+min(dl,dr);
    	}
	};
 ##  斐波那契数列
    class Solution {
	public:
   		 int Fibonacci(int n) {
      	    if(n==0)
      	    {
            	return 0;
      	    }
       	   if(n>0&&n<=2)
           {
              return 1;
           }
           int fn1=1;
           int fn2=1;
           int sum=0;
           for(int i=3;i<=n;++i)
           {
              sum = fn1+fn2;
              fn1=fn2;
              fn2=sum;
          }
         return sum;
       }
   };
 ## 跳台阶（总结：f(n)=f(n-2)+f(n-1))
    class Solution {
    public:
       int jumpFloor(int number) {
       	  int f1=1;
      	  int f2=2; 
          if(number==0)
          {
            return 0;
          }
          if(number==1)
          {
            return f1;
          }
          if(number==2)
          {
            return f2;
          }
          int sum=0;
          for(int i=3;i<=number;++i)
         {
             sum=f1+f2;
             f1=f2;
             f2=sum;
         }
         return sum;
      }
    };
 ## 平时的练习
