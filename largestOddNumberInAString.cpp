/*TC -> O(N)
  SC - > O(1)
  */
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--)
        {
            if((num[i] - '0') % 2 != 0)
            {
                num.resize(i+1);
                return num;
            }
        }
        return "";
    }
};

//iF YOU USE SUBSTR(0,i) function then, it will create new string, so it is better to use resize(i+1);
