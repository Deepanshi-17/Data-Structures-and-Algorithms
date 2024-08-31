/*TC -> O(N * M)
  SC -> O(1) */
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        
        vector<int>ans;
        
        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom){
            for(int j = right; j >= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;}
            if(left <= right){
            for(int j = bottom; j >= top; j--)
            {
                ans.push_back(matrix[j][left]);
            }
            left++;}
        }
        return ans;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
    }
};
