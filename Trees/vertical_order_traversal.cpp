Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
Output: 
4 2 1 5 6 3 8 7 9 
// here 5 and 6 are at same hd,level-> so smaller values goes first
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        if(!root->left && !root->right) return {{root->val}};
        //hd, level, root
        // we are using here multiset to sort the element at same hd and same level
        map<int, map<int, multiset<int>>> m;
        queue<pair<int,pair<int, TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* front = q.front().second.second;
                int hd = q.front().first;
                int level = q.front().second.first;
                q.pop();
                m[hd][level].insert(front->val);
                if(front->left) q.push({hd-1,{level+1, front->left}});
                if(front->right) q.push({hd+1,{level+1, front->right}});  
            }
        }
        vector<vector<int>> res;
        // here it == whole
        for(auto it:m){
            vector<int> temp;
            //here j = map inside the original map
            //so j will traverse the whole map and push the multiset of each key of map to out temp
            //ex 0-0-{1}, 0-2{5,6}
            // ye j phle 0-0 pe jaega aur temp mai 1 push krega, then ye 0-2 pe jaega and 5,6 push jrega
            // aise humare temp mai at hd=0 pe 1,5,6 ho jaega as shown in the fig at the top
                  for(auto j: it.second){
                      temp.insert(temp.end(), j.second.begin(),j.second.end());
                  }
                  res.push_back(temp);
            }
            return res; 
    }
};