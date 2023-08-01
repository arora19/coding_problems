/**
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){


    // Create a temp node to serve as the head of the merged list.
    struct ListNode temp;
    temp.next = NULL;
    // Pointer to the current node of the merged list.
    struct ListNode* merged = &temp;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            // Add the current node from list1 to the merged list.
            merged->next = list1;
            list1 = list1->next;
        } else {
            // Add the current node from list2 to the merged list.
            merged->next = list2;
            list2 = list2->next;
        }
        merged = merged->next;
    }

    // If there are any remaining nodes in list1 or list2, append them to the merged list.
    if (list1 != NULL) {
        merged->next = list1;
    } else {
        merged->next = list2;
    }

    // Return the head of the merged list.
    return temp.next;
}