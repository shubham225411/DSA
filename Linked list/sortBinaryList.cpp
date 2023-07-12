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