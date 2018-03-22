/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
        	return 0;
        } else{
            return depth(root);
        }
    }
    
    int depth(TreeNode *node){
    	int leftdepth = 0;
    	int rightdepth = 0;
    	
    	if(node == NULL){
    	    return 0;
    	} else{
    	    leftdepth = depth(node -> left);
    	    rightdepth = depth(node -> right);
    	    if(leftdepth == 0){
    	        return rightdepth + 1;
    	    } else if(rightdepth == 0){
    	        return leftdepth + 1;
    	    } else{
    	        return min(rightdepth, leftdepth) + 1;
    	    }
    	}
    }
};