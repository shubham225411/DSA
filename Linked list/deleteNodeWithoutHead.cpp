void deleteNode(ListNode* node) {
        
        // suppose we 4-5-1-9 and node =5
        ListNode* temp ;
        temp = node->next;
        node->val = node->next->val; //copying the value of next list to the given node list, now list will be 
        //4-1-1-9 and we need to point the next pointer of 1st 1 to the 9
        node->next = node->next->next;// now disrupting the next pointer and making it point towards 9
        //now list will be 4-1-9
        delete temp;// just for sake delete temp
    }


    // 4->5->1->9
    //4->1->1->9
    //4->1->9

    // we have only access to 5 node not to 4