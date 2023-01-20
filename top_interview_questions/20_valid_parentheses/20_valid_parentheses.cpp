/*
    Problem Components:
       Input is a string that only contains '(', ')', '{', '}', '[' and ']'
       Determine if they are valid Parantheses
       Valid Parantheses must:
            Open brackets must be closed by the same type of brackets.
            Open brackets must be closed in the correct order.
            Every close bracket has a corresponding open bracket of the same type.

    Solution ideas:
        Create a stack to store chars whenever it sees a open open_parentheses
        Whenever we see a closing parentheses, we wanna make sure that the stack
        is not empty so we can get the top and see if is corresponding to the closing
        parentheses that we are checking. If it passes through all the closing parentheses
        if statements, we know that they are not valid and we just return false, otherwise
        we just return if the stack is empty, so we know all opening have been closed.
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> open_parentheses; 
        int s_size = s.length();

        for (int i= 0; i < s_size; i++) {
           if (s[i] == '(' or s[i] == '[' or s[i] == '{') {
                open_parentheses.push(s[i]);
           }
           else if (s[i] == ')' and not open_parentheses.empty() and open_parentheses.top() == '(') {
                open_parentheses.pop();
           }
           else if (s[i] == ']' and not open_parentheses.empty() and open_parentheses.top() == '[') {
               open_parentheses.pop();
           }
           else if (s[i] == '}' and not open_parentheses.empty() and open_parentheses.top() == '{') {
                open_parentheses.pop();
           }
           else {
                return false;
           }
        }

        return open_parentheses.empty();
    }
};


