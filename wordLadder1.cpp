/*TC -> O(size of WordList * word length * 26)
  SC -> O(wordList) + O(size of wordlist)
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            string s = it.first;
            int steps = it.second;
            if(s == endWord) return steps;
            for(int i = 0; i < s.length(); i++)
            {
                char original = s[i];
                for(char ch = 'a'; ch <='z'; ch++)
                {
                    s[i] = ch;
                    if(st.find(s) != st.end())
                    {
                        q.push({s,steps+1});
                        st.erase(s);
                    }
                }
                s[i] = original;
            }
        }
        return 0;
    }
};
