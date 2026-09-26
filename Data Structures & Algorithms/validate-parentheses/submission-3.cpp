class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for(char c: s){
            if(closeToOpen[c]){
                if(!stack.empty() && stack.top() == closeToOpen[c]){
                    stack.pop();
                } else return false;
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
