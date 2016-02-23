class ZigzagIterator 
{
    using VecItr = vector<int>::iterator;
public:
    ZigzagIterator(vector<vector<int>> &v) 
    {
        for (auto &vec: v)
            if (!vec.empty()) lst.push_back({vec.begin(), vec.end()});
        itr= lst.begin();
    }
 
    int next() 
    {
        int ret = *itr->first;
        if (++itr->first == itr->second) itr = lst.erase(itr);
        else ++itr;
        if (itr == lst.end()) itr = lst.begin();
        return ret;
    }
 
    bool hasNext() 
    {
        return !lst.empty(); 
    }
private:
    list<pair<VecItr, VecItr>> lst;
    list<pair<VecItr, VecItr>>::iterator itr;
};

int main()
{
    vector<vector<int>> vec
    {
        {1,2,3,4,5,6},
        {7,8,9,10,11},
        {12,13,14},
        {},
        {15,16,17,18,19,20}
    };
    ZigzagIterator itr(vec);
    while (itr.hasNext())
    {
        cout << itr.next() << ' ';
    }
    cout << endl;
    return 0;
}
