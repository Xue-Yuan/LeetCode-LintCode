class Solution
{
public:
    void shuffle(vector<int> &nums)
    {
        default_random_engine generator(time(0));
        for (int i = (int)nums.size()-1; i > 0; i--)
        {
            uniform_int_distribution<int> distribution(0, i);
            int j = distribution(generator);
            swap(nums[i], nums[j]);
        }
    }
};
