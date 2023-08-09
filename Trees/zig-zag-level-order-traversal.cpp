
                    1
                   / \
                  2   3
                  /    \
                 4      5
                ans= [[1],[ 32],[45]]
// ? The intuition first push the root tp the  answer vector and then make a variable ex loop=1,
//? the first time we enter the while loop we have to piush from the right side to the answer vector
//? and after that from the left side and soo on. So while the "loop" is we will just reverse the v vector and push
//? it in ans vector, and when loop is even then no need to reverse the v vector and push it in asn as it is.

// one more doubt jo diumag mai aa sakta hai ki queue mai phle right then left kyu nhi push kar dete,
// toh aise krne mai wrong o jaega lets see..q mai phle 1 push kiye, phir 3,4 push kiye , lekin ab toh humko
// phle 4 and 5 push karna hai lekin chuki humne phle 3 push kiya hai toh q mai 4 push krne mai dikkat hoga
// wo for loop ulta chalana hoga , //! so v vector ko reverse kar dena jyada asan hai
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {{root->val}};

        vector<vector<int>>ans;
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        ans.push_back({root->val});
        int alternate = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front(); q.pop();
                
                if(front->left){
                        q.push(front->left);
                        v.push_back(front->left->val);
                    }
                if(front->right){
                        q.push(front->right);
                        v.push_back(front->right->val);
                }    
                
            }
            // odd hua toh reverse krke and v ka size check krke dalenge kyuki jab last level hum bfs
            // kar rahe honge tabhi v mai kuch bhi push nhi hoga and agar bina size check kiye dal diye toh
            // ans ke andar empty vector ja sakta hai
           if(alternate%2!=0 && v.size()!=0){
               reverse(v.begin(), v.end());
               ans.push_back(v);
               v.clear();
           }else if(alternate%2==0 && v.size()!=0){
               ans.push_back(v);
               v.clear();
           }
           
            alternate++;
        }
        return ans;
    }
};