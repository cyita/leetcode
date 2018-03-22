/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/

#include <string>
#include <iostream>
#include <stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Solution {
public:
    int myAtoi(string str) {
        int size = str.size();
        int result = 0;
        int multi = 1;
        int start = 0;
        bool ifStart = false;
        bool ifMinus = false;
        bool ifOverflow = false;

        //purify
        if(size == 0){
        	return 0;
        } else{
        	for(int i = 0; i != size; i ++){
        		if(!ifStart){
        			if(str[i] == ' '){
        				continue;
        			} else if((str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '+'){
        				ifStart = true;
        				start = i;
        			} else{
        				return 0;
        			}
        		} else{
        			if(str[i] >= '0' && str[i] <= '9'){
        				continue;
        			} else{
        				size = i;
        				break;
        			}
        		}
        	}
        }
        
        for(int i = size - 1; i != start; i --){
        	if(str[i] >= '0' && str[i] <= '9'){
        		result += (str[i] - '0') * multi;
        		multi = multi * 10;
        	}
        	if(result < 0){
        		ifOverflow = true;
        	}
        }

        if(str[start] == '-'){
        	result = 0 - result;
        	ifMinus = true;
        	start ++;
        } else if(str[start] == '+'){
        	start ++;
        } else{
        	result += (str[start] - '0') * multi;
        	if(result < 0){
        		ifOverflow = true;
        	}
        }

        //if overflow
        if(start <= size - 11){
        	ifOverflow = true;
        } else if(start == size - 10 && str[start] > '2' && str[start] <= '9'){
        	ifOverflow = true;
        }
              
        if(!ifMinus){
        	if(ifOverflow){
        		return 2147483647;
        	}
        } else{
        	if(ifOverflow){
        		return -2147483648;
        	}
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
	Solution test;
	string str;
	cout << "input the string to change" << endl;
	cin >> str;
	int result = test.myAtoi(str);
	cout << result << endl;
	return 0;
}
