class Solution
{
public:
    bool add1(vector<int> &num)
    {
        if (num.empty())
        {
            num.push_back(1);
            return true;
        }
        bool positive = num[0] >= 0;
        if (!positive)
            return subtract1(num);
        else
        {
            int idx = (int)num.size()-1;
            int sum = 0, carry = 1;
            while (idx >= 0)
            {
                if (num[idx] < 0) return false;
                sum = carry + num[idx];
                carry = sum > 9;
                sum %= 10;
                num[idx--] = sum;
            }
            if (carry) num.insert(num.begin(), 1);
            return true;
        }
    }

    bool subtract1(vector<int> &num)
    {
        num[0] = -num[0];
        int carry = 1;
        int idx = (int)num.size() - 1;
        while (idx >= 0)
        {
            if (num[idx] < 0) return false;
            carry = (num[idx] -= carry) < 0;
            if (carry) num[idx] += 10;
            idx--;
        }
        num[0] = -num[0];
        return true;
    }
};
