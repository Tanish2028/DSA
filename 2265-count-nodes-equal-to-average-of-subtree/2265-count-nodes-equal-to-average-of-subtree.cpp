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
    int count = 0;
    pair<int,int> func(TreeNode* root){
         if(root == NULL){
            return {0,0};
         }
      

        pair<int,int> leftSide = func(root->left);
        pair<int,int> rightSide = func(root->right);

        int val = (root->val + leftSide.second + rightSide.second)/(1 + leftSide.first + rightSide.first);
        if(val == root->val){
            count++;
        }

        return {1+leftSide.first + rightSide.first,root->val + leftSide.second+rightSide.second};
    }
    int averageOfSubtree(TreeNode* root) {
        
        func(root);

        return count;
    }
};