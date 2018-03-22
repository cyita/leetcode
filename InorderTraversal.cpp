/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
#include <vector>

using std::cout;
using std::endl;
using std::cin;
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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;

        if(root == NULL){

        } else{
        	addNode(result,root);
        }
        return result;
    }

    void addNode(vector<int> &result, TreeNode *node){
    	if(node != NULL){
    		if(node -> left != NULL){
    			addNode(result, node -> left);
    		}
    		result.push_back(node -> val);
    		if(node -> right != NULL){
    			addNode(result, node -> right);
    		}
    	} else{
    		/*nothing to do*/
    	}
    }
};

int main(int argc, char const *argv[])
{
	Solution test;

	//construct the tree
	TreeNode *first = new TreeNode(1);
	TreeNode *second = new TreeNode(2);
	TreeNode *third = new TreeNode(3);
	TreeNode *forth = new TreeNode(4);
	TreeNode *fifth = new TreeNode(5);
	first -> left = second;
	first -> right = third;
	third -> left = forth;
	forth -> right = fifth;

	vector<int> result = test.inorderTraversal(first);

	for(int i = 0; i != result.size(); i ++){
		cout << result[i] << endl;
	}
	return 0;
}