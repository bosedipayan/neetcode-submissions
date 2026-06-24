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
        ListNode* rev = reverseList(head);

        ListNode* temp = rev;
        n--;
        while(n--)
        {
            temp=temp->next;
        }

        ListNode* res = new ListNode();
        ListNode* ptr = res;

        while(head)
        {
            if(head != temp)
            {
                ptr->next = head;
                ptr = ptr->next;
            }
            head = head->next;
        }
        return res->next;
    }
};

// [1,2,3,4]

// [4,3,2,1]
