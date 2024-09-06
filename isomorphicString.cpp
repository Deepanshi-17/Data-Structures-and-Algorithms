/*TC -> O(N) + O(M)
  SC -> O(N)
  */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,char>mp;

        for(int i = 0; i < s.length(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                if(mp[s[i]] != t[i])
                return false;
            }
            mp[s[i]] = t[i];
        }
        mp.clear();

        for(int i = 0; i < t.length(); i++)
        {
            if(mp.find(t[i]) != mp.end())
            {
                if(mp[t[i]] != s[i])
                return false;
            }
            mp[t[i]] = s[i];
        }
        return true;
    }
};

/*TC -> O(N)
  SC -> O(N)
  */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;

        for(int i = 0; i < s.length(); i++)
        {
            if(mp1.find(s[i]) != mp1.end() || mp2.find(t[i]) != mp2.end())
            {
                if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i])
                return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};
