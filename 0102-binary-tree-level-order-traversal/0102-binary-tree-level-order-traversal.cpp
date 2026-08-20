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
        // queue<vector<TreeNode*>>q;
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL)return ans;

        q.push(root);


        while(!q.empty()){
            auto it=q.front();
            // q.pop();

            int size=q.size();
            cout<<"size of the q this time is "<<q.size()<<endl;

            vector<int>temp;

            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                temp.push_back(it->val);

                if(it->left){
                    q.push(it->left);
                }
                if(it->right){
                    q.push(it->right);
                }
                
            }

            if(temp.size()){
                ans.push_back(temp);
            }
          

        }

        return ans;

        
    }
};