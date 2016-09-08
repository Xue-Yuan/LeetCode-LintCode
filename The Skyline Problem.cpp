class Solution
{
private:
	vector<pair<int,int>> merge(vector<pair<int,int>> &A,vector<pair<int,int>> &B)
	{
		int h1 = 0, h2 = 0, i = 0, j = 0;
		vector<pair<int, int>> res;
		while (i < A.size() && j < B.size())
		{
			int x, h;
			if (A[i].first < B[j].first)
			{
				x = A[i].first;
				h = max(h1 = A[i].second, h2);
				++i;
			}
			else if (A[i].first > B[j].first)
			{
				x = B[j].first;
				h = max(h1, h2 = B[j].second);
				++j;
			}
			else
			{
				x = A[i].first;
				h = max(h1 = A[i].second, h2 = B[j].second);
				++i, ++j;
			}
			if (res.empty() || h != res.back().second)
				res.push_back({x, h});
		}
		//We don't have to worry about two points with the same
		//	height here. Think about the last point of B if B
		//	ends earlier than A.
		while (i < A.size()) res.push_back(A[i++]);
		while (j < B.size()) res.push_back(B[j++]);

		return res;
	}
	vector<pair<int,int>> getSkyline(vector<vector<int>> &A,int start,int end)
	{
	    if (start < end)
	    {
	    	int mid = start + (end - start) / 2;
	    	auto left = getSkyline(A, start, mid);
	    	auto right = getSkyline(A, mid + 1, end);
	    	return merge(left, right);
	    }
	    return {{A[start][0], A[start][2]}, {A[start][1], 0}};
	}
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& A)
	{
	    if (A.empty()) return {};
	    return getSkyline(A,0,A.size()-1);
	}
};
