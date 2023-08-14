//{ Driver Code Starts
//Initial Template for C++










// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
// make a class to store minvalue of node, maxvalue of node and size of bst
class nodeInfo{
    public:
   int minvalue, maxvalue,size;
   
   nodeInfo(int minvalue, int maxvalue, int size){
       this->minvalue = minvalue;
       this->maxvalue = maxvalue;
       this->size = size;
   }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    nodeInfo helper(Node* root){
        // if the root == null, then its size will be zero
        // we will make its minvalue tp int_max, so that after comparison every value can be lesser
        //than its min value
        // we will make its maxvalue to int_min, so that after comparison every value can be greater than its 
        //max value
        if(!root) return nodeInfo(INT_MAX,INT_MIN,0);
        
        nodeInfo left = helper(root->left);
        nodeInfo right = helper(root->right);
        
        // if the root->data > max value from its left subtree and smaller than than smallest value
        // from its right subtree then its a valid bst
        // now that left part return the minimum value so min(root->data, left.minvalue)
        // and right subtree return the greater value so max(root->data, right.maxvalue);
        if(root->data > left.maxvalue && root->data < right.minvalue){
            return nodeInfo(min(root->data, left.minvalue), max(root->data, right.maxvalue), 1+left.size+right.size);
        }
        // now the root is not a part of a valid bst
        // so making its minvalue to int_min, so that after making any comparison no value should be 
        // lesser than its minvalue and same with its maxvalue
        return nodeInfo(INT_MIN,INT_MAX,max(left.size, right.size));
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	return helper(root).size;
    }
};