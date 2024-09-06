/*TC -> O(nlogn * m) + O(n)
  SC -> O(m) */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //We want to find the longest common prefix in all the strings. so better to sort it lexicographically, then you will need to check only the first and the last string in the vector
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[n-1];

        string ans = "";
        for(int i = 0; i < min(s1.length(), s2.length()); i++)
        {
            if(s1[i] != s2[i])
            return ans;

            ans += s1[i];
        }
        return ans;
    }
};

/*
TC -> O(n*m)
SC -> O(m) */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i = 1; i < strs.size(); i++)
        {
            while(strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);

                if(prefix.empty())
                return "";
            }
        }
        return prefix;
    }
};
