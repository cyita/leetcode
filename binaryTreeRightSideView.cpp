/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;


        if(root == NULL){
        	return result;
        } else{
        	TreeNode *mark = root;
        	queue<TreeNode*> nodequeue;
        	int size = 0;
        	TreeNode* thisNode;

        	nodequeue.push(root);
        	while(!nodequeue.empty()){
        		size = nodequeue.size();
        		for(int i = 0; i != size; i ++){
        			thisNode = nodequeue.front();
        			if(thisNode -> left != NULL){
        				nodequeue.push(thisNode -> left);
        			}

        			if(thisNode -> right != NULL){
        				nodequeue.push(thisNode -> right);
        			}
        			nodequeue.pop();
        		}
        		result.push_back(thisNode -> val);
        	}
        }
        return result;
    }
};