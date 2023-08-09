
           8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
answer = 8,10,14,3,6,7,13,1,4
solution- after pushing the root, we will traverse to the right of root till root becomes null and during this
we will push root to the answer vector and if root->left then push root->left to the queue , for the next diagonal traversal
 jab root aa jaega 1 ya 4 pe toh aise toh uska koi right nhi hai , toh simply 1 ya 4 ko answer vector mai dal denge
 and check krlenege ki uska koi left toh nhi hai taki uska dusra diagonal traversal mai cover kar sake
vector<int> diagonal(Node *root)
{
   // your code here
   if(!root) return {};
   if(!root->left && !root->right) return {{root->data}};
   
   vector<int>ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node* front = q.front(); q.pop();
       // agar root ka right hai toh pghle usko ans mai push karenge and uske left ko queue mai
       if(front->right){
           while(front){
           ans.push_back(front->data);
           if(front->left) q.push(front->left);
           front = front->right;
        }
       }else{
        //agar root ka right nhi hai toh usko directly ans mai push kar denge and uska left child check kar lenge
           ans.push_back(front->data);
           if(front->left) q.push(front->left);
       }
   }
   return ans;
}