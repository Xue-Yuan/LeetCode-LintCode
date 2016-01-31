/*
    一个数据流，里面是很多对象，每个对象里存了一艘船的id，这艘船主人的id，
    这艘船的价格。找到每个人价格最高的五艘船。
*/
struct Boat
{
    int boat_id;
    int owner_id;
    int price;
    Boat(int bi, int oi, int p): boat_id(bi), owner_id(oi), price(p){}
};

class Solution
{
    //boat_id and price
    using PII = pair<int, int>;
private:
    struct myLess
    {
        bool operator()(PII &a, PII &b) {return a.second < b.second;}
    };
public:
    unordered_map<int, vector<int>> top5PriceBoat(vector<Boat> &vec)
    {
        unordered_map<int, priority_queue<PII, vector<PII>, myLess>> m;
        for (auto &boat : vec)
            m[boat.owner_id].push({boat.boat_id, boat.price});

        unordered_map<int, vector<int>> ret;
        for (auto &boat :vec)
        {
            auto &pq = m[boat.owner_id];
            for (int i = 0; i < 5 && !pq.empty(); ++i)
            {
                ret[boat.owner_id].push_back(pq.top().first);
                pq.pop();
            }
        }
        return ret;
    }
}; 
