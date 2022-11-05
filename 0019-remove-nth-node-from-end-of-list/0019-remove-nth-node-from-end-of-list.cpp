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
/*
    List length = N
    Node position to delete = nth from last
    
    steps: 
    1. create a gap of n nodes using two pointers fast and slow
    2. now shift this window until fast reaces to last node
    3. slow pointer is just behind the nth node from the last so break links
    4. return head
*/
           
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head;
        while(n--){
            fast = fast->next;
        }
        if(fast == NULL) return head->next;
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        return head;
    }
};