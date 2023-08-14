class Solution {
public:
    bool valid(TreeNode* root,  long long int min,  long long int max){
        if(!root) return true;
        
        if(root->val <= min || root->val >= max) return false;
        
        
        // the nodes of left subtree can take any value from -infinty to its parent nodes value, that's why before 
        // going towards left setting the max value with root->val
        // the nodes of right subtree can take any value from it parenr root to infinity, so setting the min value
        // to the root->val
        return valid(root->left, min, root->val) & valid(root->right, root->val, max);
    }
    bool isValidBST(TreeNode* root) {
        if(!root || !root->left && !root->right) return true;
        long long int min = -2147483649;
        long long int max = 2147483648;

        return valid(root, min, max);
        
    }
};
