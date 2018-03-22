/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        } else{
            tranverse(root);
        }
    }
    
    TreeNode* tranverse(TreeNode *node){
        TreeNode *last;
        if(node -> left == NULL && node -> right == NULL){
            return node;
        } else if(node -> left != NULL){
            last = tranverse(node -> left);
            last -> right = node -> right;
            node -> right = node -> left;
            node -> left = NULL;
            if(last -> right != NULL){
                last = tranverse(last -> right);
            }
        } else{
            last = tranverse(node -> right);
        }
        return last;
    }
};