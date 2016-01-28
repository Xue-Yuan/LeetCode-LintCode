class Solution {  
public:  
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {  
        vector<vector<int>> res;  
        int m = matrix.size();  
        if(0 == m) return res;  
        int n = matrix[0].size();  
  
        for(int i=0;i<n;i++) 
        {  
            vector<int> sum(m, 0);  
            for(int j=i;j<n;j++) 
            {  
                  
                //sum[k] is the sum of matrix (k,i), (k,j)  
                //sum of subarray of sum[k] can be all sub  
                //matrix of (0,i), (m-1,j)  
                for(int k=0;k<m;k++)   
                    sum[k] += matrix[k][j];  
      
                //find a subarray with 0 sum  
                int lastSum = 0;  
                unordered_map<int, int> set;  
                set[0] = -1;  
                for(int v=0;v<m;v++) 
                {  
                    lastSum += sum[v];  
                    if(set.count(lastSum)) 
                    {  
                        res.push_back(vector<int>({set[lastSum]+1, i}));  
                        res.push_back(vector<int>({v, j}));  
                        return res;  
                    }  
                    set[lastSum] = v;  
                }  
            }  
        }  
        return res;  
    }  
};  