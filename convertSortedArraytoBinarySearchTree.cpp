/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
        	return NULL;
        } else{
        	return buildBST(nums, 0, size - 1);
        }
    }

    TreeNode* buildBST(vector<int>& nums, int start, int end){
    	int mid = (start + end) / 2;
    	TreeNode *subroot = new TreeNode(nums[mid]);
    	if(start == end){
    		return subroot;
    	} else if(mid == start){
    		subroot -> right = buildBST(nums, mid + 1, end);
    	} else{
    		subroot -> left = buildBST(nums, start, mid - 1);
    		subroot -> right = buildBST(nums, mid + 1, end);
    	}
    	return subroot;
    }
};