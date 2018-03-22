/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
 #include <vector>

 using std::vector;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<TreeNode*>> levelNode;
        vector<TreeNode*> thislevel;
        vector<vector<int>> result;
        
        if(root == NULL){
            return result;
        }

        //initialize
        vector<TreeNode*> first;
        first.push_back(root);
        levelNode.push_back(first);
        vector<int> firstResult;
        firstResult.push_back(root -> val);
        result.push_back(firstResult);

        while(true){
        	thislevel = *(-- levelNode.end());
        	vector<TreeNode*> nextlevel;
        	vector<int> thisResult;

        	for(vector<TreeNode*> :: iterator i = thislevel.begin(); i != thislevel.end(); i ++){
        		if((*i) -> left != NULL){
        			nextlevel.push_back((*i) -> left);
        			thisResult.push_back((*i) -> left -> val);
        		}
        		if((*i) -> right != NULL){
        			nextlevel.push_back((*i) -> right);
        			thisResult.push_back((*i) -> right -> val);
        		}
        	}

        	if(nextlevel.size() == 0){
        		break;
        	} else{
        		levelNode.push_back(nextlevel);
        		result.push_back(thisResult);
        	}
        }

        return result;
    }
};