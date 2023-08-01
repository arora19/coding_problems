/**
Remove Duplicates from Sorted List

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){

    struct ListNode* node = head;
    struct ListNode* duplicate;

    while(node!= NULL && node->next != NULL){

        //if duplicate found
        if(node->val == node->next->val){
            duplicate = node->next;
            node->next = node->next->next;
            free(duplicate);
        }
        else{
            node = node->next; // no duplicate found so move to next node
        }
    }

    return head;
}