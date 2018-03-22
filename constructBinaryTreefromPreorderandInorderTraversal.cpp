/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

#include <algorithm>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
   TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
        	return NULL;
        } else{
        	return buildSubtree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        }
    }
    
    TreeNode* buildSubtree(vector<int>::iterator preorderbegin, vector<int>::iterator preorderend, vector<int>::iterator inorderbegin, vector<int>::iterator inorderend){
    	TreeNode *subroot  = new TreeNode(*preorderbegin);
    	vector<int>::iterator inmark = find(inorderbegin, inorderend, subroot -> val);
    	
    	int leftNum = inmark - inorderbegin;
    	int rightNum = inorderend - inmark;
    	
    	if(leftNum == 0 && rightNum == 1){
    		return subroot;
    	} else if(leftNum == 0){
    		subroot -> right = buildSubtree(preorderbegin + 1, preorderend, inorderbegin + 1, inorderend);
    	} else if(rightNum == 1){
    		subroot -> left = buildSubtree(preorderbegin + 1, preorderend, inorderbegin, inorderend - 1);
    	} else{
    		subroot -> left = buildSubtree(preorderbegin + 1, preorderbegin + 1 + leftNum, inorderbegin, inmark);
    		subroot -> right = buildSubtree(preorderbegin + 1 + leftNum, preorderend, inmark + 1, inorderend);
    	}
    	return subroot;
    }
};
