/*TC -> O(n)
  SC -> o(1)
  */

class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance = 0;
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(balance > 0)
                {
                    ans += s[i];
                }
                balance++;
            }
            else
            {
                balance--;
                if(balance > 0)
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};

/*TC -> O(n)
  SC -> O(n)
  */
//using stack

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                if(!st.empty())
                {
                    ans += s[i];
                }
                st.push(s[i]);
            }
            else
            {
                st.pop();
                if(!st.empty())
                {
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};
