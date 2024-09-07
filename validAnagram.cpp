/*TC -> O(nlogn) + O(nlogn)
SC -> O(1)
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

/*TC -> O(N) + O(N)
SC -> O(N)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>mp;
        for(auto it: s)
        mp[it]++;
        for(auto it: t)
        mp[it]--;

        for(auto it: mp)
        {
            if(it.second != 0) return false;
        }
        return true;
    }
};

/*TC -> O(n) + O(n)
  SC -> O(n) */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int>freq(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i <=26; i++)
        {
            if(freq[i] != 0) return false;
        }
        return true;
    }
};
