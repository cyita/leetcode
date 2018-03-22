/**
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 #include <iostream>
 #include <stdlib.h>

 using std::cout;
 using std::endl;

 struct ListNode{
 		int val;
 		ListNode* next;
 		ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	//create mark for the two linked lists
    	ListNode* mark1 = l1;
    	ListNode* mark2 = l2;
    	ListNode* result;
    	ListNode* resultPivit;
    	//the carry
    	int carry = 0;
    	//this position result
    	int thisRe = 0;
        if(l1 == NULL){
        	return l2;
        } else if(l2 == NULL){
        	return l1;
        } else{
        	//calculate the first digit
        	thisRe = mark1 -> val + mark2 -> val;
        	if(thisRe > 9){
        		carry = thisRe/10;
        		thisRe = thisRe % 10;
        	}
        	ListNode* thisNode = new ListNode(thisRe);
        	result = thisNode;
        	resultPivit = result;
        	mark1 = mark1 -> next;
        	mark2 = mark2 -> next;

        	//calculate the same position in both l1 and l2
        	while(mark1 != NULL && mark2 != NULL){
        		thisRe = mark1 -> val + mark2 -> val + carry;
        		carry = thisRe/10;
        		thisRe = thisRe % 10;
        		ListNode* thisNode = new ListNode(thisRe);
        		resultPivit -> next = thisNode;
        		resultPivit = resultPivit -> next;
        		mark1 = mark1 -> next;
        		mark2 = mark2 -> next;
        	}

        	//if l1 and l2 are same in length
        	if(mark2 == NULL && mark1 == NULL){
        		if(carry == 0){
        			return result;
        		} else{
        			ListNode* thisNode = new ListNode(carry);
        			resultPivit -> next = thisNode;
        			return result;
        		}
        	} else if(mark2 == NULL){      //l1 is longer
        		while(mark1 != NULL && carry != 0){
        			thisRe = mark1 -> val + carry;
                    carry = thisRe/10;
                    thisRe = thisRe % 10;
                    ListNode* thisNode = new ListNode(thisRe);
                    resultPivit -> next = thisNode;
                    resultPivit = resultPivit -> next;
        			mark1 = mark1 -> next;
        		}
        		if(carry != 0){
                    ListNode* thisNode = new ListNode(carry);
                    resultPivit -> next = thisNode;
                } else{
                    resultPivit -> next = mark1;
                }
                return result;
        	} else{                        //l2 is longer
                while(mark2 != NULL && carry != 0){
                    thisRe = mark2 -> val + carry;
                    carry = thisRe/10;
                    thisRe = thisRe % 10;
                    ListNode* thisNode = new ListNode(thisRe);
                    resultPivit -> next = thisNode;
                    resultPivit = resultPivit -> next;
                    mark2 = mark2 -> next;
                }
                if(carry != 0){
                    ListNode* thisNode = new ListNode(carry);
                    resultPivit -> next = thisNode;
                } else{
                    resultPivit -> next = mark2;
                }
                return result;
        	}
        }
    }

    void printList(ListNode* head){
        ListNode* mark = head;
        while(mark != NULL){
            cout << mark -> val;
            mark = mark -> next;
        }
        cout << endl;
    }
};


int main(int argc, char const *argv[])
{
    Solution test;

    //test case
    //the first digit
    ListNode* first = new ListNode(2);
    ListNode* second = new ListNode(4);
    ListNode* third = new ListNode(3);
    first -> next = second;
    second -> next = third;

    //the second digit
    ListNode* firstt = new ListNode(9);
    ListNode* secondt = new ListNode(6);
    ListNode* thirdt = new ListNode(9);
    firstt -> next = secondt;
    secondt -> next = thirdt;

    ListNode* result = test.addTwoNumbers(first, firstt);
    test.printList(first);
    test.printList(firstt);
    test.printList(result);
    return 0;
}
