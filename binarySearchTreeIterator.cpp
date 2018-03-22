/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
#include <iostream>

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

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushStack(root, nodeSequence);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !nodeSequence.empty();
    }

    /** @return the next smallest number */
    int next() {
        int result = nodeSequence.top();
        nodeSequence.pop();
        return result;
    }
private:
	stack<TreeNode*> nodeSequence;

	void pushStack(TreeNode *node, stack<TreeNode*> &seq){
		if(node == NULL){
			return;
		} else{
			if(node -> right != NULL){
				pushStack(node -> right, seq);
			}
			seq.push(node);
			if(node -> left != NULL){
				pushStack(node -> left, seq);
			}
		}
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */