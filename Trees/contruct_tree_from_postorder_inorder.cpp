class Solution {
public:
    TreeNode* solve(vector<int>&inorder, vector<int>&postorder, int lb, int ub, int &idx, unordered_map<int, int>&m){
        if(lb > ub || idx<0) return NULL;
        TreeNode* head = new TreeNode(postorder[idx--]);
        int mid = m[head->val];
        if(ub == lb) return head;
        // we are coming from the back of postorder ie. idx--, so we encounter the right subtree first and hence we are making right recursion call first
        head->right = solve(inorder, postorder, mid+1, ub, idx, m);
        head->left = solve(inorder, postorder, lb, mid-1, idx, m);
       
        return head;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

     unordered_map<int, int> m;
     int idx = inorder.size()-1;
     for(int i=0;i<inorder.size(); i++) m[inorder[i]] = i;

     return solve(inorder, postorder, 0, inorder.size()-1, idx, m);   
    }
};

//** postorder mai sabse right wala root hai toh udhar se hi shuru krte hue aaenge and root ko inorder traversal mai khoj kar uska left and right subtree set kr denge