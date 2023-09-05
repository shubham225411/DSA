class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        // using morris inorder traversal, bcz inorder of bst gives sorted results
        int ans;
        int idx = 1;
        while(cur){
            if(cur->left == NULL){
                idx++;
                cur = cur ->right;
            }else{
                TreeNode* temp = cur->left;
                while(temp->right && temp->right!=cur){
                    temp = temp->right;
                }
                if(temp->right == NULL){
                    temp->right = cur;
                    cur = cur->left;
                }else{
                    temp->right = NULL;
                    idx++;
                    cur = cur->right;
                }
            }
            if(idx == k) ans = cur ->val;
        }
        return ans;
    }
};

// using counter to track small element using inorder traversal
class Solution {
public:
    int small(TreeNode* root, int &idx, int k){
        if(!root) return 0;

        int left = small(root->left, idx,k);
        idx++;
        if(idx == k) return root->val;
        int right = small(root->right, idx, k);

        int ans = (left!=0) ? left : right;
        return ans;

    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int idx =0;
        return small(root, idx, k);
    }
};