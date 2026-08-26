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
    
    TreeNode* deleteNode(TreeNode*& root,vector<TreeNode*>& result,unordered_map<int,int>& mpp){
        if(root == NULL){
            return NULL;
        }

       root->left = deleteNode(root->left,result,mpp);
        root->right = deleteNode(root->right,result,mpp);

        if(mpp.find(root->val) != mpp.end()){
            if(root->left != NULL){
                result.push_back(root->left);
            }
            if(root->right != NULL){
                result.push_back(root->right);
            }

            return NULL;
        }
        else{
            return root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_map<int,int>mpp;

        for(auto it: to_delete){
            mpp[it]++;
        }


        vector<TreeNode*>result;

        deleteNode(root,result,mpp);

        if(mpp.find(root->val) == mpp.end()){
            result.push_back(root);
        }

        return result;


    }
};