/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	bool result = false;
        if(p == NULL && q == NULL){
        	return true;
        } else if(p == NULL || q == NULL){
        	return false;
        } else{
        	result = ifSame(p, q);
        }
        return result;
    }

    bool ifSame(TreeNode *p, TreeNode *q){
    	bool result = false;
    	if(p == NULL && q == NULL){
    		return true;
    	} else if(p == NULL || q == NULL){
    		return false;
    	} else{
    		if(p -> val != q -> val){
    			return false;
    		} else{
    			result = ifSame(p -> left, q -> left) && ifSame(p -> right, q -> right);
    			if(result == false){
    				return false;
    			}
    		}
    	}
    	
    	return result;
    }
};