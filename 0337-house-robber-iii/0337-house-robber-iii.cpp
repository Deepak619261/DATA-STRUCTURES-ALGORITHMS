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
    int solve(TreeNode* root,map<TreeNode*,int>&dp){
        if(root==NULL)return 0; 

        //  at every node we got two choice either loot that node or not 
        int dontrob=solve(root->left,dp)+solve(root->right,dp);
        int rob=root->val;

        if(dp.find(root)!=dp.end())return dp[root];

        if(root->left){
            rob+=solve(root->left->left,dp)+solve(root->left->right,dp);
        }
        if(root->right){
            rob+=solve(root->right->left,dp)+solve(root->right->right,dp);
        }

        return dp[root]=max(dontrob,rob);
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode*,int>dp;
        return solve(root,dp);
    }
};