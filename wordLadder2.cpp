/*TC -> O(wordList * wordlength * 26)
  SC -> O(wordList) + O(wordList) + O(wordList)
  */

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        int level = 0;

        while(!q.empty())
        {
            vector<string>v = q.front();
            q.pop();
            string s = v.back();
            if(s == endWord)
            {
                // if(ans.size() == 0)
                // ans.push_back(v);
                // else if(ans[1].size() == v.size())
                ans.push_back(v);
            }
            if(v.size() > level)
            {
                level++;
                for(auto it: usedOnLevel)
                st.erase(it);
            }
            for(int i = 0; i < s.length(); i++)
            {
                char original = s[i];
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[i] = ch;
                    if(st.find(s) != st.end())
                    {
                        v.push_back(s);
                        q.push(v);
                        v.pop_back();
                        usedOnLevel.push_back(s);
                    }
                }
                s[i] = original;
            }
        }
        return ans;
    }
};
