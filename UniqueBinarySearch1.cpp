/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
    int numTrees(int n) {
        int result = 0;
        int resultArray[n];
        int loopNum = 0;
        int complement = 0;

        resultArray[0] = 1;
        resultArray[1] = 1;
        resultArray[2] = 2;

        if(n <= 2){
        	return n;
        } else{
        	for(int i = 3; i != n + 1; i ++){
        		result = 0;

        		if(i % 2 == 0){
        			loopNum = i/2;
        		} else{
        			loopNum = i/2 + 1;
        		}

        		for(int j = 0; j != loopNum; j ++){
        			complement = i - j - 1;
        			if(complement == j){
        				result += resultArray[j] * resultArray[j];
        			} else{
        				result += resultArray[j] * resultArray[complement] * 2;
        			}
        		}
        		resultArray[i] = result;
        	}
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	int testNum = 0;
	cout << "Please input the test number: " << endl;
	cin >> testNum;
	int result = test.numTrees(testNum);
	cout << result << endl;
	return 0;
}