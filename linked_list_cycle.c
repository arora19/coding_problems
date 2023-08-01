/**
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, there can't be a cycle.
        return false;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow pointer one step.
        fast = fast->next->next;   // Move fast pointer two steps.

        if (slow == fast) {
            // The pointers meet, indicating the presence of a cycle.
            return true;
        }
    }

    // If the fast pointer reaches the end of the list, there is no cycle.
    return false;
}