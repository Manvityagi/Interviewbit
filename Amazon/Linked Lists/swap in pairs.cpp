/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//recursive
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL){
        return NULL;
    }
    if(A->next == NULL){
        return A;
    }
    
    ListNode* rec_head = swapPairs(A->next->next);
    
    ListNode* newhead = A->next;
    
    A->next = rec_head;
    newhead->next = A;
    
    return newhead;
}

//iterative
ListNode* Solution::swapPairs(ListNode* head) {
  if(!head || !(head->next)) return head;
        
        ListNode* h = head;
        head = head->next;
        
        ListNode* curr, *currN;
        
        while(h && h->next)
        {
            curr = h;
            currN = curr->next;
            
            h = currN->next;
            
            if(currN->next == NULL){
                curr->next = NULL;
            }
            else if(currN->next->next == NULL){
                curr->next = h;
            }
            else{
                curr->next = currN->next->next;
            }
            currN->next = curr;
        }
        
        return head;
}
