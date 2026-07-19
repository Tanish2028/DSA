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
    pair<int,int> func(TreeNode* root){
        if(root == NULL){
            return {INT_MIN,0};
        }

        auto [leftMax,leftC] = func(root->left);
        auto [rightMax,rightC] = func(root->right);
        
        int sumMax = max({leftMax,rightMax,root->val});

        int count = leftC + rightC;

        if(sumMax == root->val){
            count++;
        }
        return {sumMax,count};
        
    }
    int countDominantNodes(TreeNode* root) {
        

        int count = func(root).second;

        return count;
    }
};