/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            // Do NOT delete head; LeetCode's driver will do it
            return nullptr; 
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        // Traverse the linked list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Skip the middle node
        // Do NOT delete slow->next; LeetCode's driver will handle it
        slow->next = slow->next->next;
        
        return head;
    }
};