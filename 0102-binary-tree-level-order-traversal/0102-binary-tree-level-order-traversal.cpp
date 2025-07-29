/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;

        q.push(root);

        
        

        while(!q.empty()){
            vector<int>temp;
            int size=q.size();


            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                temp.push_back(it->val);

            if(it->left){
            //   temp.push_back(it->left->val);
              q.push(it->left);
            }
            if(it->right){
                // temp.push_back(it->right->val);
                q.push(it->right);
            }
            }

           
            if(!temp.empty())ans.push_back(temp);
        }

        return ans;


        
    }
};