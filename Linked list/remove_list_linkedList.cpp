class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        if(!head || !head->next) return;
        // first we will find out if there is a loop or not
        Node* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast ) break;
        }
        // if slow == fast, it means there is a loop
        // checking for edge case, that if loop begins from head itself, then we cant go directly assign a pointer
        // to head and slow will also be at head
        // so here we will let the slow be at head and move the fast till fast->nex!=slow/head, then fast will be stucked at
        // the last node and then point it to null thus removing the loop
        if(slow == fast){
            Node *begin = head;
             Node* prev = NULL;
             if(slow == head){
                 while(fast->next!=slow) fast = fast->next;
                 fast->next = NULL;
             }else{
                // if the loop doesn't start at head, then using the prev pointer find the node just before the start
                // of the loop and pointing it to null and removing the NULL
                 while(slow!=begin){
                prev = slow;
                slow = slow->next;
                begin = begin->next;
             }
            if(prev) prev->next = NULL;
             }
            
        }
    }
};