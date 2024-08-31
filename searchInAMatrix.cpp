/*TC -> O(N^2)
  SC -> O(1)*/

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    for(int i = 0; i < N; i++)
	    {
	        for(int j = 0; j < M; j++)
	        {
	            if(mat[i][j] == X)
	            return 1;
	        }
	    }
	    return 0;
	}
};

/*TC -> O(N + M)
   SC -> o(1)*/
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	   int i = 0;
	   int j = M-1;
	   while( i < N && j >= 0)
	   {
	       if(mat[i][j] == X)
	       return 1;
	       else if(mat[i][j] > X)
	       j--;
	       else 
	       i++; 
	   }
	   return 0;
	}
};

/*
For Completely sorted 2-D Array
TC -> O(log(N*M))
SC -> O(1)
  */

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	   int low = 0;
	   int high = N * M -1;
	   while(low <= high)
	   {
	       int mid = low + (high-low)/2;
	       int row = mid/M;
	       int col = mid % M;
	       if(mat[row][col] == X)
	       return 1;
	       else if(mat[row][col] > X)
	       high = mid -1;
	       else 
	       low = mid + 1;
	   }
	   return 0;
	}
};
