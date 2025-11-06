/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if (head == NULL) return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // move slow by one
        fast = fast->next->next;     // move fast by two
        
        if (slow == fast) {          // if they meet, cycle exists
            return true;
        }
    }

    return false;                    // reached end, no cycle
}
