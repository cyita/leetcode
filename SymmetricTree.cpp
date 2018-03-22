/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
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
    bool isSymmetric(TreeNode* root) {
        bool result = false;
        if(root == NULL){
        	return true;
        } else{
        	result = ifSymmetric(root -> left, root -> right);
        }
        return result;
    }
    
    bool ifSymmetric(TreeNode *p, TreeNode *q){
    	bool result = false;
    	if(p == NULL && q == NULL){
    		return true;
    	} else if(p == NULL || q == NULL){
    		return false;
    	} else{
    		if(p -> val != q -> val){
    			return false;
    		} else{
    			result = ifSymmetric(p -> left, q -> right) && ifSymmetric(p -> right, q -> left);
    			if(result == false){
    				return false;
    			}
    		}
    	}
    	
    	return result;
    }
};