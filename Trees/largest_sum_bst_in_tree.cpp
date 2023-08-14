class nodeValue{
     public:
     int minvalue, maxvalue, sum;

     nodeValue(int minvalue, int maxvalue, int sum){
         this->minvalue = minvalue;
         this->maxvalue = maxvalue;
         this->sum = sum;
         
     }
 };
class Solution {
public:
        // we will update ans and save the max sum of BST in ita nd carry it forwards
        // and if we enounter any greater value we will update the ans again
    nodeValue helper(TreeNode* root, int &ans){
        if(!root) return nodeValue(INT_MAX, INT_MIN, 0);

        nodeValue left = helper(root->left,ans);
        nodeValue right = helper(root->right,ans);

            // when the current root forms a bst
        if(root->val > left.maxvalue && root->val < right.minvalue){
            //whebever we will come accross a BST, update the value of ans
            ans = max(ans, root->val + left.sum+right.sum);
            return nodeValue(min(root->val, left.minvalue), max(root->val, right.maxvalue), root->val + left.sum + right.sum);
        }

        // when the root does not form a bst
        return nodeValue(INT_MIN, INT_MAX,ans);

    }
    int maxSumBST(TreeNode* root) {

        int ans = 0;
        auto res = helper(root,ans);
        return ans;
    
     
    }
};