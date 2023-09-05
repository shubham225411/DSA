Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list
 and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Input : 
          1
        /   \
       2     5
      / \     \
     3   4     6

Output :
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

class Solution {
public:
    void flatten(TreeNode* root) {
        
        if(!root) return;
        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()){
            TreeNode* temp = s.top(); s.pop();

            // pushing right first so that left should be on top and then point the right pointer to the top od stack
            if(temp->right) s.push(temp->right);
            if(temp->left) s.push(temp->left);

            if(!s.empty()){
                temp->right = s.top();
            }
            temp->left = NULL;
        }
    }
};

class Solution {
public:
void flat(TreeNode* root, TreeNode*& prev){

    if(!root) return;
    flat(root->right, prev);
    flat(root->left, prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* prev = NULL;
        flat(root, prev);
    }
};

class Solution {
public:
    void preorder(TreeNode* root, queue<TreeNode*>&q){
        if(root == NULL)  return;
        q.push(root);
        preorder(root->left, q);
        preorder(root->right, q);
    }
    void flatten(TreeNode* root) {

        if(root == NULL) return;

        
        queue<TreeNode*> q;
        preorder(root, q);
        
        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            temp->left = NULL;
            if(!q.empty()){
                temp->right = q.front();
            }else{
                temp->right = NULL;
            }
        }
    }
};

//using morris traversal technique
class Solution {
public:
    void flatten(TreeNode* root) {

     if(!root) return;

     TreeNode* cur = root;

     while(cur){
         if(cur->left){
             TreeNode* temp = cur->left;

             while(temp->right) temp = temp->right;
             temp ->right = cur->right;
             cur ->right = cur->left;

         }
         cur->left = NULL;
         cur = cur->right;
         
     }
    }
};