// In the below soltution we can first do any traversala nd store the nodes in vector and then sort the vector 
// then while doing inorder traversal of the tree place the node value from the vector one by one, 
// bcz inorder traversal gives the sorted order of bst
// so it will finally fixed the two deviated nodes
// brute-force method
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&v){
        if(!root) return ;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    void correctbst(TreeNode* root, vector<int>&v,int &index){
        if(!root) return;

        correctbst(root->left, v,index);
        root->val = v[index];
        index++;
        correctbst(root->right, v,index);
    }
    void recoverTree(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int index =0;
        correctbst(root, v, index);
        
    }
};
// below solution is optimized as we have to just one traversal
class Solution {
public:
TreeNode* prev, *first, *middle, *last;
void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    // condition 
    // prev == null bcz when it will first leaf node at that time, prev will be null so
    // every node has to be greater than its previous node while inorder traverse
    if(prev!=NULL && root->val < prev->val){
        // if first ==NULL, then its the first element to have deviation
        // in the first deviation we have to set first and middle
        // bcz there is chance that the two deviated nodes are adjacent, so we need to swap first   and  middle only
        // if after the entire traversal if last is still null that means first and middle are the only deviated nodes and we need to swap these two nodes only
        // if after the traversal if last != NULL, then it means that two deviated nodes are not adjacent
        // then we will swap first and last node

        // first case of deviation
        if(first==NULL){
            first = prev;
            middle = root;
        }else{
            // if first!=NULL, then second case of deviation
            last = root;
        }
    }
    prev = root;
    inorder(root->right);

}
    void recoverTree(TreeNode* root) {
        if(!root || !root->left && !root->right) return;

        prev = first = middle = last = NULL;
        inorder(root);

        if(first && middle && !last) swap(first->val, middle->val);
        if(first && middle && last) swap(first->val, last->val);
    }
};
