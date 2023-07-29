Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

// iterative approach

ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* cur = head, *prev = NULL;

        while(cur){
            if(cur->next && cur->val == cur->next->val){
                ListNode* temp = cur;
                while(temp && temp->next && temp->val == temp->next->val){
                    temp = temp->next;
                }
    // here the prev will be null only when we find duplicates at the beginnning of the list, so moving the head only is the best
                if(!prev) head = temp->next;
                else prev->next = temp->next;
                cur = temp->next;
            }else{
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }

// recursive approach
ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;


        if(head->next && head->val == head->next->val){
            while(head->next && head->val == head->next->val) head = head->next;
            // here after the while loop, the head will at the last duplicate element and since we dont want any occurence of duplicates
            //so calling the fnc with head->next
            return deleteDuplicates(head->next);
        }else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }