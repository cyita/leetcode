/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        } else{
            preorder(root, result);
        }

        return result;
    }

    void preorder(TreeNode* node, vector<int>& list){
        if(node == NULL){
            return;
        } else{
            list.push_back(node -> val);
            preorder(node -> left, list);
            preorder(node -> right, list);
        }
    }
};
