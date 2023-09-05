class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // morris traversal inorder
        if(!root) return {};
        vector<int> ans;

        TreeNode* cur = root;
        while(cur!=NULL){
            // case i) when cur ->left == null, print and then move to right
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                // case ii) when left is not equal to null, then move one step left and go to the right most node,
                // if the right most node is threaded to cur then remove the thread, else thread it to the cur
                TreeNode* temp = cur->left;
                while(temp->right && temp->right!=cur){
                    temp = temp->right;
                }
                // case i) temp->right == NULL, then make a thread to the cur
                if(temp->right == NULL){
                    temp->right = cur;
                    cur = cur ->left;
                }
                else{
                    // case ii) when temp->right is threaded to cur, then cut the thread and move to right
                    temp->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // morris traversal , preorder traversal
        if(!root) return {};
        vector<int> ans;

        TreeNode* cur = root;
        while(cur!=NULL){
            // case i) when cur ->left == null, print and then move to right
            if(cur->left == NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right!=cur){
                    temp = temp->right;
                }
                // case i) temp->right == NULL, then make a thread to the cur
                if(temp->right == NULL){
                    temp->right = cur;
                     ans.push_back(cur->val);
                    cur = cur ->left;
                }
                else{
                    // case ii) when temp->right is threaded to cur, then cut the thread and move to right
                    temp->right = NULL;
                   
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};