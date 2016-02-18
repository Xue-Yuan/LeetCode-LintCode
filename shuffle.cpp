/*
shuffle，但要求是每个元素的下标不能和原来的index一样
*/
class Solution
{
public:
    vector<int> shuffle(vector<int> &vec)
    {
        vector<bool> index(vec.size(), true);
        vector<int> res;
        default_random_engine generator(time(nullptr));
        while (res.size() != vec.size())
        {
            for (size_t i = 0; i < vec.size(); ++i)
            {
                vector<size_t> remain_idx;
                for (size_t j = 0; j < vec.size(); ++j)
                {
                    if (j == i || !index[j]) continue;
                    remain_idx.push_back(j);
                }
                if (!remain_idx.empty())
                {
                    uniform_int_distribution<size_t> distribution(0, remain_idx.size()-1);
                    size_t dice_roll = distribution(generator);
                    index[remain_idx[dice_roll]] = false;
                    res.push_back(vec[remain_idx[dice_roll]]);
                }
                else index.assign(vec.size(), true);
            }
        }
        return res;
    }
};

int main()
{   
    vector<int> vec(10);
    iota(vec.begin(), vec.end(), 0);
    for (int &i : vec)
        cout << i << ' ';
    cout << endl;
    auto ret = Solution{}.shuffle(vec);
    for (int &i : ret)
        cout << i << ' ';
    cout << endl;
    return 0;
}
