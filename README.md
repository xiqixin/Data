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
## 剑指offer
