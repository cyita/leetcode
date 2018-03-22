/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
#include <stack>

 using std::vector;
 using std::stack;
 using std::cout;
 using std::endl;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<TreeNode*> > levelNode;
        vector<TreeNode*> thislevel;
        vector<TreeNode*> nextlevel;
        stack<vector<int> > resultReverse;
        vector<vector<int> > result;
        vector<int> thisResult;        
        if(root == NULL){
            return result;
        }

        //initialize
        vector<TreeNode*> first;
        first.push_back(root);
        levelNode.push_back(first);
        thisResult.push_back(root -> val);
        resultReverse.push(thisResult);
        thisResult.clear();

        while(true){
        	thislevel = *(-- levelNode.end());

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
        		resultReverse.push(thisResult);
        		nextlevel.clear();
        		thisResult.clear();
        	}
        }

        while(!resultReverse.empty()){
        	result.push_back(resultReverse.top());
        	resultReverse.pop();
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	TreeNode* first = new TreeNode(3);
	TreeNode* second = new TreeNode(9);
	first -> left = second;
	vector<vector<int> > result = test.levelOrderBottom(first);
	for(vector<vector<int> >::iterator i = result.begin(); i != result.end(); i ++){
		for(vector<int>::iterator j = (*i).begin(); j != (*i).end(); j ++){
			cout << (*j) << " ";
		}
		cout << endl;
	}
	return 0;
}