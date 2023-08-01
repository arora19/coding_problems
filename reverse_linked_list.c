/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){

// Initialize pointers to keep track of the current, previous, and next nodes.
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    struct ListNode* nextNode = NULL;

    while (current != NULL) {
        // Store the next node before modifying the current node's "next" pointer.
        nextNode = current->next;
        // Reverse the current node's "next" pointer to point to the previous node.
        current->next = previous;
        // Move the 'previous' and 'current' pointers one step forward.
        previous = current;
        current = nextNode;
    }

    // At the end of the loop, 'previous' will be pointing to the new head of the reversed list.
    return previous;

}