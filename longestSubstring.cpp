/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int size = s.size();
        int repeatTime = 0;
        int maxRepeat = 0;
        char thisChar;
        bool Find = false;
        int position = 0;

        for(int i = 0; i != size; i ++){
        	thisChar = s[i];
        	//find if the char is in the string
        	for(int j = position; j != i; j ++){
        		if(s[j] == thisChar){
        			position = j + 1;
        			Find = true;
        			break;
        		} 
        	}

        	if(Find){
        		repeatTime = i - position + 1;
        		if(repeatTime > maxRepeat){
        			maxRepeat = repeatTime;
        		}
        	} else{
        		repeatTime ++;
        	}
            if(repeatTime > maxRepeat){
                maxRepeat = repeatTime;
            }
        }

        //if the longest string is in the last
        int sub = size - position;
        if(sub > maxRepeat){
        	maxRepeat = sub;
        }
        return maxRepeat;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	string s1;
	cout << "Please input the string:" << endl;
	cin >> s1;
	int result = test.lengthOfLongestSubstring(s1);
	cout << result << endl;
	return 0;
}