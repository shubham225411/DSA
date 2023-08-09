    Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 
8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.

class Solution {
public:
//this function is to set parent relation with node, so that later on we can get parent of any node from a map to burn the parent
    void makeParent(TreeNode* root, map<TreeNode*, TreeNode*>&parent){
        if(!root) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        makeParent(root->left, parent);
        makeParent(root->right, parent);
    }
    // this fnc returns the starting point of fire npde
    TreeNode* returnStartNode(TreeNode* root, int start){
        if(!root) return NULL;
        if(root->val == start) return root;
        TreeNode* left = returnStartNode(root->left, start);
        TreeNode* right = returnStartNode(root->right, start);
        return (left!=NULL) ? left : right ;
    }
    int amountOfTime(TreeNode* root, int start) {

        map<TreeNode*, TreeNode*> parent; // stores the node->parent
        set<TreeNode*>burntNodes;// stores the already burnt nodes
        makeParent(root, parent);
        TreeNode* beginNode = returnStartNode(root, start);
        queue<TreeNode*> q;
       q.push(beginNode);
       burntNodes.insert(beginNode);// beginNode is the starting point of the fire, so it is already burnt hence pushing it in burntNodes set to keep its record
       
       int minutes = 0;
       while(!q.empty()){
           bool didBurnSomeBody = false; // bool variable to track that in a for loop did any nodes get burnt or not
           int size = q.size();
           for(int i=0;i<size;i++){
               TreeNode* front = q.front(); q.pop();     
               // if the parent of the current node exist and it is not already burnt, then pushing it in burntNodes list
               // and pusing it in queue and making the bool variable true
                if(parent.find(front)!=parent.end() && burntNodes.find(parent[front])==burntNodes.end()){
                    // now it will vurn its parent
                    burntNodes.insert(parent[front]);
                    q.push(parent[front]);
                    didBurnSomeBody = true;
                }
                // if left of node exits and it is not already burnt, then adding it to already burnt nodes list i.e burning
                // it now and the adding it to queue and making the bool variable true
                // we will not add any node to queue, if it is already burnt
                if(front->left && burntNodes.find(front->left)==burntNodes.end()){
                    // now it will burn its left child
                    burntNodes.insert(front->left);
                    q.push(front->left);
                    didBurnSomeBody = true;

                }
                
                if(front->right && burntNodes.find(front->right)==burntNodes.end()){
                    // now it will burn its left child
                    burntNodes.insert(front->right);
                    q.push(front->right);
                    didBurnSomeBody = true;

                }
           }
           // at last if bool variable is true that means at least one node is being burnt in this loop, then increment the
           // minutes
           if(didBurnSomeBody==true) minutes++;
           
       }
       return minutes;

    }
};