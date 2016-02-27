/*
	Given a list of airline tickets represented by pairs of departure and 
		arrival airports [from, to], reconstruct the itinerary in order. 
		All of the tickets belong to a man who departs from JFK. Thus, 
		the itinerary must begin with JFK.

	Note:
	If there are multiple valid itineraries, you should return the itinerary 
		that has the smallest lexical order when read as a single string. For 
		example, the itinerary ["JFK", "LGA"] has a smaller lexical order than 
		["JFK", "LGB"].

	All airports are represented by three capital letters (IATA code).
	You may assume all tickets form at least one valid itinerary.
	
	Example 1:
		tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
		Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
	
	Example 2:
		tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
		Return ["JFK","ATL","JFK","SFO","ATL","SFO"].

		Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But 
			it is larger in lexical order.
*/

/*
	Think about preorder and postorder traverse a tree. It would be easier for
		us to merge the path with postorder traversal.
*/

class Solution
{
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        for (auto &p : tickets)
            m[p.first].insert(p.second);
        dfs("JFK");
        return {ret.rbegin(), ret.rend()};
    }
private:
    void dfs(string cur)
    {	//postorder
        while (m[cur].size())
        {
            auto tmp = *m[cur].begin();
            m[cur].erase(m[cur].begin());
            dfs(tmp);
        }
        ret.push_back(cur);
    }
private:
    unordered_map<string, multiset<string>> m;
    vector<string> ret;
};
