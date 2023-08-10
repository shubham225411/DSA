class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head ) return false;

        // here intuition is that agar loop hoga toh kabhi na kabhi slow aur fast same ho ajenge kyuki
        // fast ka speed double hai slow se so ek point ke bad jakar overlap toh hoga hi
        ListNode* slow= head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast) return true;
        } 
        //agar ye loop khatm ho gaya toh iska matlab ye hai ki fast null ya fast->next null hai that means koi cycle nhi hai list mai, so return false

        return false;
        
    }
};