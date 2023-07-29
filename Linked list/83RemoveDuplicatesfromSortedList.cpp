Input: head = [1,1,2,3,3]
Output: [1,2,3]

// recursive approach
ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        
        if(head->val == head ->next ->val){
            while(head->next && head->val == head->next->val){
                head = head->next;
            }
            //after the while loop the head will be at the last occurence of the element and
            // and since we want at least one occurence of multi-occuring element that's why 
            // including the head also while calling the function
            return deleteDuplicates(head);
        }else
        {
            
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }

// itereavtive approach

ListNode* deleteDuplicates(ListNode* head) {
     if(!head || !head->next) return head;
     ListNode* cur = head;
     while(cur && cur->next){
         if(cur->val == cur->next->val){
            // only moving the next pointer, not the cur position
             cur->next = cur->next->next;
         }else{
             cur = cur->next;
         }
     }
     return head;

    }

