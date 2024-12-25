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
    vector<int> largestValues(TreeNode* root) {
        //  store the node as well level in the queue

        vector<int>ans;
        if(root==NULL)return ans;

    
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        int maxi=INT_MIN;
        int level=0;



        while(!q.empty()){
            auto it=q.front();
            int checklevel=it.second;
            TreeNode* temp=it.first;
            q.pop();

            if(level!=checklevel){
                ans.push_back(maxi);
                maxi=INT_MIN;
                level=checklevel;
            }


            if(temp){
                maxi=max(temp->val,maxi);
                if(temp->left){
                q.push({temp->left,checklevel+1});
                }
                if(temp->right){
                q.push({temp->right,checklevel+1});
                }
            }
             
        }
        ans.push_back(maxi);

        return ans;
        
    }
};