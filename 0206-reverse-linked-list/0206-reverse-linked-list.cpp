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
    int getLength(ListNode* &head){
        ListNode* temp = head;
        int len = 0;
        while(temp!=NULL){
            len = len+1;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev = NULL;
        // ListNode* curr = head;
        // int len = getLength(head);
        // for(int i=0;i<len;i++){
        //     ListNode* temp = curr->next;
        //     curr->next = prev;

        //     prev = curr;
        //     head = prev;

        //     curr = temp;
        // }
        // return prev;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;

        
    }
};