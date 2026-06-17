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
    ListNode* reverseIt(ListNode* head)
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
    void reorderList(ListNode* head) {
        ListNode* fast=head, *slow=head;

        while(fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == nullptr)
            {
                break;
            }
        }

        ListNode* rev = reverseIt(slow);

        ListNode* temp = head;
        ListNode* res = new ListNode();
        ListNode* ptr = res;

        int c=0;
        while(rev != temp)
        {
            if(c%2 == 0)
            {
                ptr->next = temp;
                ptr=ptr->next;
                temp = temp->next;
            }
            else{
                ptr->next = rev;
                ptr=ptr->next;
                rev = rev->next;
            }

            c++;
        }

        head = res->next;
    }
};

// 2, 4, 6, 8, 10

// 2, 10, 4