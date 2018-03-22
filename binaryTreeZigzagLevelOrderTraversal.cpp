/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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

#include <stdlib.h>
#include <iostream>
#include <deque>
#include <vector>

using std::deque;
using std::cout;
using std::endl;
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        vector<int> thisLevel;
        bool odd = true;
        int nodeQsize = 0;

        if(root == NULL){
        	return result;
        }

        deque<TreeNode*> nodeQ;
        TreeNode* thisNode;
        nodeQ.push_front(root);
        thisLevel.push_back(root -> val);
        result.push_back(thisLevel);
        thisLevel.clear();

        while(!nodeQ.empty()){
        	nodeQsize = nodeQ.size();
        	if(odd){
        		for(int i = 0; i != nodeQsize; i ++){
        			thisNode = nodeQ.back();

        			if(thisNode -> right != NULL){
        				thisLevel.push_back(thisNode -> right -> val);
        				nodeQ.push_front(thisNode -> right);
        			}
        			if(thisNode -> left != NULL){
        				thisLevel.push_back(thisNode -> left -> val);
        				nodeQ.push_front(thisNode -> left);
        			}
        			
        			nodeQ.pop_back();
        		}
        		odd = false;
        	} else{
        		for(int i = 0; i != nodeQsize; i ++){
        			thisNode = nodeQ.front();

        			if(thisNode -> left != NULL){
        				thisLevel.push_back(thisNode -> left -> val);
        				nodeQ.push_back(thisNode -> left);
        			}
        			if(thisNode -> right != NULL){
        				thisLevel.push_back(thisNode -> right -> val);
        				nodeQ.push_back(thisNode -> right);
        			}
        			
        			nodeQ.pop_front();
        		}
        		odd = true;
        	}

        	if(!thisLevel.empty()){
        		result.push_back(thisLevel);
        		thisLevel.clear();
        	}
        	
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	TreeNode* first = new TreeNode(1);
	TreeNode* second = new TreeNode(2);
	TreeNode* third = new TreeNode(3);
	TreeNode* forth = new TreeNode(4);
	TreeNode* fifth = new TreeNode(5);
	TreeNode* sixth = new TreeNode(6);
	first -> right = third;
	first -> left = second;
	second -> left = forth;
	second -> right = fifth; 
	third -> right = sixth;
	vector<vector<int> > result = test.zigzagLevelOrder(first);
	for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); it ++){
		for(vector<int>::iterator i = (*it).begin(); i != (*it).end(); i ++){
			cout << (*i) << " ";
		}
		cout << endl;
	}
	return 0;
}