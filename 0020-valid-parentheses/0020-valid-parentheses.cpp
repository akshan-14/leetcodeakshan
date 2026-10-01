#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        // An odd-length string cannot be valid
        if (s.length() % 2 != 0) return false;

        std::stack<char> st;

        for (char c : s) {
            // Push opening brackets onto the stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                // Stack empty means a closing bracket has no corresponding opening bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check for mismatched bracket types
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Valid only if all opened brackets were closed
        return st.empty();
    }
};