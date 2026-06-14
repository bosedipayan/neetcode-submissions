/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res = new ListNode();
        ListNode* ptr = res;

        ListNode* t1 = list1, *t2 = list2;
        while(t1 || t2)
        {
            if(!t1)
            {
                while(t2)
                {
                    ptr->next = t2;
                    t2 = t2->next;
                    ptr=ptr->next;
                }
                break;
            }

            if(!t2)
            {
                while(t1)
                {
                    ptr->next = t1;
                    t1 = t1->next;
                    ptr=ptr->next;
                }
                break;
            }

            if(t1->val < t2->val)
            {
                ptr->next = t1;
                t1 = t1->next;
                ptr=ptr->next;
            }
            else{
                ptr->next = t2;
                t2 = t2->next;
                ptr=ptr->next;
            }
        }
        
        return res->next;
    }
};
