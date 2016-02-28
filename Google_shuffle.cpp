/*
shuffle，但要求是每个元素的下标不能和原来的index一样
*/
class Solution
{
public:
    void shuffle(vector<int> &nums)
    {
        default_random_engine generator(time(0));
        for (int i = (int)nums.size()-1; i > 0; i--)
        {
            uniform_int_distribution<int> distribution(0, i-1);
            int j = distribution(generator);
            swap(nums[i], nums[j]);
        }
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
