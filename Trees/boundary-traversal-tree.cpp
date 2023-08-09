           1
           /
          2
        /  \
       4    9
     /  \    \
    6    5    3
             /  \
            7     8

Output: 1 2 4 6 5 7 8

class Solution {
public:
   void printBoundaryLeft(Node* root,vector<int>&ans)
    {
        //cout<<"at the top, root is "<<root->data<<endl;
        if(root==NULL) return;
        
        if(root->left)
        {
            //cout<<"inside root->left, root is "<<root->data<<endl;
            ans.push_back(root->data);
            printBoundaryLeft(root->left,ans);
        }
        //we have to use here else if only bcz we have to go towards left subtree first and if left subtree
        // is not present then only we have to go towards right. if there is both left and right then we will go
        // to left subtree only only right.
        //! same with printing right boundary
         else if(root->right)
        {
            //cout<<"inside root->right , root is "<<root->data<<endl;
            ans.push_back(root->data);
            printBoundaryLeft(root->right,ans);
        }
        //cout<<"leaf node"<<endl;
    }
    void printLeaf(Node* root, vector<int>&ans)
    {
        if(root==NULL) return;
        
        if(!root->left && !root->right) ans.push_back(root->data);
        printLeaf(root->left,ans);
        printLeaf(root->right,ans);
    }
    void printBoundaryRight(Node* root, vector<int>&ans)
    {
        if(root==NULL) return;
        
        if(root->right)
        {
            printBoundaryRight(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            printBoundaryRight(root->left,ans);
            ans.push_back(root->data);
        }
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root==NULL) return ans;
        ans.push_back(root->data);
        printBoundaryLeft(root->left,ans);
        printLeaf(root->left,ans);
        printLeaf(root->right,ans);
        printBoundaryRight(root->right,ans);
        return ans;
    }
    
};