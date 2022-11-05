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
private:
    ListNode* mergeSort(ListNode* head){
        if(!head || !head->next)
            return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast && fast->next){
            slow = slow->next; // increment slow by 1
            fast = fast->next->next; // increment fast by 2
        }
        
        ListNode* head1 = head; // head of lefthalf
        ListNode* head2 = slow->next; // head of right half
        slow->next = NULL; // separate two halves
        
        ListNode* list1 = mergeSort(head1); // recursive calls to lefthalf
        ListNode* list2 = mergeSort(head2); // recursive calls to righthalf
        
        return merge(list1,list2); // final head
    }
    
    
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* iterator = dummyHead;
        
        // for equal sized lists
        while(head1 && head2){
            if(head1->val < head2->val){
                iterator->next = new ListNode(head1->val);
                iterator = iterator->next;
                head1 = head1->next;
            }
            else{
                iterator->next = new ListNode(head2->val);
                iterator = iterator->next;
                head2 = head2->next;
            }
        }
        
        // unqual sized lists
        while(head1){
            iterator->next = new ListNode(head1->val);
            head1 = head1->next;
            iterator = iterator->next;
        }
        
        while(head2){
            iterator->next = new ListNode(head2->val);
            head2 = head2->next;
            iterator = iterator->next;
        }
        
        return dummyHead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};