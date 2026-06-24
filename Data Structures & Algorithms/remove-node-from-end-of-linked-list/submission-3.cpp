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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next;

        while(cur)
        {
            next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1)
        {
            ListNode* slow = reverseList(head);
            return reverseList(slow->next);
        }
        int c=0;
        ListNode* temp = head;
        while(temp)
        {
            c++;
            temp=temp->next;
        }

        int cp = (c-n)+1;

        int check=0;
        ListNode* res = new ListNode();
        ListNode* ptr = res;
        while(head)
        {
            check++;
            if(cp != check)
            {
                ptr->next = head;
                ptr = ptr->next;
            }
            head = head->next;
        }
        return res->next;
    }
};