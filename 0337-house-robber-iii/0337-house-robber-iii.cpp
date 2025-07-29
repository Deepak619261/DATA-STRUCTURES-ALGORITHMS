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
    int solve(TreeNode* root, bool canROB,map<pair<TreeNode*,bool>,int>&dp){
        if(root==NULL)return 0;

        int rob=0;
        int dontrob=0;

        pair<TreeNode*,bool>key={root,canROB};
        if(dp.find(key)!=dp.end())return dp[key];

        if(canROB){
            rob=root->val+solve(root->left,false,dp)+solve(root->right,false,dp);
            dontrob=solve(root->left,true,dp)+solve(root->right,true,dp);
        }
        else{
            rob=solve(root->left,false,dp)+solve(root->right,false,dp);
            dontrob=solve(root->left,true,dp)+solve(root->right,true,dp);

        }

        return dp[key]=max(rob,dontrob);

    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int>dp;
        return max(solve(root,true,dp),solve(root,false,dp));
    }
};