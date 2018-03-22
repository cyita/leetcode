/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

#include <iostream>
#include <map>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::map;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
        	return true;
        } else{
            int result = depth(root);
            if(result == -1){
                return false;
            } else{
                return true;
            }
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
    	    if(leftdepth == -1 || rightdepth == -1 || abs(leftdepth - rightdepth) > 1){
    	        return -1;
    	    } else{
    	        return max(rightdepth, leftdepth) + 1;
    	    }
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	TreeNode *first = new TreeNode(1);
	TreeNode *second = new TreeNode(2);
	TreeNode *third = new TreeNode(3);
	first -> right = second;
	first -> left = third;

	bool result = test.isBalanced(first);
	if(result){
		cout << "true" << endl;
	} else{
		cout << "false" << endl;
	}

	return 0;
}