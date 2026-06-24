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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;

        ListNode* res = new ListNode();
        ListNode* ptr = res;

        int sum=0, c=0;
        while(head1 || head2 || c)
        {
            int temp = 0;
            if(head1)
            {
                temp+=head1->val;
                head1 = head1->next;
            }

            if(head2)
            {
                temp+=head2->val;
                head2 = head2->next;
            }

            temp+=c;
            c=temp/10;

            ListNode* node = new ListNode(temp%10);
            ptr->next = node;
            ptr = ptr->next;
        }

        return res->next;
    }
};
