ListNode* Solution::solve(ListNode* A) {
    // agar list null hai ya list mai ek hi node hai toh , list ko as it is return kardo
    if(!A || !(A->next)) return A;
    ListNode *zeroD = new ListNode(0);
    ListNode *oneD = new ListNode(0);
    ListNode *zero = zeroD;
    ListNode *one = oneD;
    
    ListNode *head = A;
    while(head){
        if(head->val == 0){
            zero ->next = head;
            zero = zero->next;
        }else{
            one->next = head;
            one = one->next;
        }
        head = head ->next;
    }
    // hum jo new list bana rahe hein, uske endpoint ko null ki taraf point kiya hai
    one ->next = NULL;
    // zeroD list mai starting dummy node hai, usko skip krke list ko one oneD se connect kiya
    // and oneD ke list ke bhi phle node ko skip kiya kyuki wo bhi dummy node hai
    zero ->next = oneD ->next;
    // finally zeroD ke first dummy node ko skip krke baki sara list return krdiya
    return zeroD->next;
}

// the below code is to return the node from where the cycle begins
ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;

        ListNode* slow =head, *fast = head;
        while(fast && fast->next ){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow==fast){
            ListNode* start = fast, *begin = head;
            while(start!=begin){
                start = start->next;
                begin = begin->next;
            }
            return start;

        }else{
            return NULL;
        }
    }

    // the below code will also return the first node of cycle
    // we use map, if the node is not present in the map then add it, else if the node is already present
    // it means we came to that node again and their is a loop. simply return the first npde we come accross again
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;

        ListNode* slow =head;
        map<ListNode*, bool> visited;
        while(slow){
            if(visited.find(slow) == visited.end()) visited[slow] = true;
            else return slow;
            
            slow = slow->next;
        }
        return NULL;

    }