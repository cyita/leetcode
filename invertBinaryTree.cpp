/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
    TreeNode* invertTree(TreeNode* root) {
    	TreeNode *temp;

        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
        	return root;
        } else if(root -> left == NULL){
        	root -> left = root -> right;
        	root -> right = NULL;
        	invertTree(root -> left);
        } else if(root -> right == NULL){
        	root -> right = root -> left;
        	root -> left = NULL;
        	invertTree(root -> right);
        } else{
        	temp = root -> left;
        	root -> left = root -> right;
        	root -> right = temp;
        	invertTree(root -> left);
        	invertTree(root -> right);
        }

        return root;
    }
};