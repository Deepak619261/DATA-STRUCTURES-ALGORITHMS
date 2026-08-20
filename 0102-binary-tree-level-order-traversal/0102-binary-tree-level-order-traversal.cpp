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
        queue<vector<TreeNode*>>q;
        vector<vector<int>>ans;
        if(root==NULL)return ans;

        q.push({root});


        while(!q.empty()){
            auto it=q.front();
            q.pop();


            vector<TreeNode*>temp;
            vector<int>ans1;

            for(auto it1:it){
                ans1.push_back(it1->val);
                if(it1->left){
                    temp.push_back(it1->left);
                }
                if(it1->right){
                    temp.push_back(it1->right);
                }
            }
            if(ans1.size()>0){
            ans.push_back(ans1);
            }

            if(temp.size()>0){
            q.push(temp);
            }

        }

        return ans;

        
    }
};