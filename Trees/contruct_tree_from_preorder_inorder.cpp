class Solution {
public:
    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int lb, int ub, int &idx, unordered_map<int, int> &m){
        if(lb > ub) return NULL;
        TreeNode* head = new TreeNode(preorder[idx++]);
        int mid = m[head->val];
        if(ub == lb) return head; // strting and ending point of the tree is same, so returnning the head

        // we use lb and ub as the starting and ending point the tree
        // for the left part the tree will contain from lb till the index of head found in inorder -1, hence mid -1, left root, right
        // for the right part tree will go from index of head in inorder +1 to ub

        head ->left = solve(preorder, inorder, lb, mid-1, idx,m);
        head->right = solve(preorder, inorder, mid+1, ub, idx, m);

        return head;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        int idx = 0;

        // hashing the index value of node of inorder traversal, so that later we can find the indexes of the root of preorder traversal and form tree
        for(int i =0; i< inorder.size(); i++) m[inorder[i]] = i;

        return solve(preorder, inorder, 0, inorder.size() -1, idx, m);
    }
};


// intution hai ki preorder mai phle root hota hai and and inorder mai lroot beech mai hota hai,
// so jo bhi humein root milega preorder mai humko usko search krenge inorder mai and uske left walo ko left subtree mai right walo ko right subtree mai bhej denge 
// througj recursion call. Thats why humne inorder traversal ko hash kiya hai (root,index).