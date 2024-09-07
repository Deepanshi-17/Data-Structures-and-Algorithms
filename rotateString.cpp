class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string s2 = goal + goal;
        if(s2.find(s) != std:: string:: npos)
        return true;
        return false;
    }
};

/*TC -> O(m) + O(m)
  SC -> O(m) */
