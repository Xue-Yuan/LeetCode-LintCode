/*
    Additive number is a string whose digits can form additive sequence.

    A valid additive sequence should contain at least three numbers. Except 
        for the first two numbers, each subsequent number in the sequence 
        must be the sum of the preceding two.

    For example:
        "112358" is an additive number because the digits can form an additive
         sequence: 1, 1, 2, 3, 5, 8.

    1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

    "199100199" is also an additive number, the additive sequence is: 1, 99, 
        100, 199.
    1 + 99 = 100, 99 + 100 = 199
    
    Note: Numbers in the additive sequence cannot have leading zeros, so 
        sequence 1, 2, 03 or 1, 02, 3 is invalid.

    Given a string containing only digits '0'-'9', write a function to determine
        if it's an additive number.
*/
class Solution 
{
private:
   //using string to represent number so we can avoid overflow
    string addTwoString(const string &s1, const string &s2)
    {
        int end1 = s1.size() - 1, end2 = s2.size() - 1;
        string res(max(end1, end2) + 1, '0');
        int sum = 0, carry = 0, idx = (int)res.size() - 1;
        while(end1 >= 0 || end2 >= 0)
        {
            sum = 0;
            if(end1 >= 0) sum += (s1[end1--] - '0'); 
            if(end2 >= 0) sum += (s2[end2--] - '0');
            sum += carry;
            carry = sum > 9;
            sum = sum % 10;
            res[idx--] = char(sum + '0');
        }
        return carry ? "1" + res : res;
    }
public:
    bool isAdditiveNumber(string num) 
    {
        for(int i = 1; i < num.size(); ++i)
            for(int j = i + 1; j < num.size(); ++j)
                if(isAdditiveNumber(num, 0, i, j))
                    return true;
        return false;
    }
    //DFS. The end is exclusive.
    bool isAdditiveNumber(string num, int b1, int e1, int e2)
    {
        if(e2 == num.size()) return true;

        string s1 = num.substr(b1, e1 - b1), s2 = num.substr(e1, e2 - e1);
        //avoid leading '0'
        if((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) return false;

        for(int e3 = e2 + 1; e3 <= num.size(); ++e3)
        {
            string s3 = num.substr(e2, e3 - e2);
            if(addTwoString(s1, s2) == s3 && isAdditiveNumber(num, e1, e2, e3))
                return true;
        }
        return false;
    }
};

/*
Taken from https://leetcode.com/discuss/70129/recursive-using-string-represent-number-avoid-overflow-issue
*/

class Solution2 
{
private:
    string addS(string &s1, string &s2)
    {
        int i=s1.size()-1, j=s2.size()-1,k=max(i,j), carrier=0,temp;
        string res(k+1,'0');
        for(; i>=0 || j>=0; --i,--j)
        {
            temp = (i<0?0:(s1[i]-'0')) + (j<0?0:(s2[j]-'0')) + carrier;
            res[k--] = (temp % 10 + '0');
            carrier = temp>9;
        }
        return carrier>0?'1'+res:res;
    }
    
public:
    bool isAdditiveNumber(string num)
    {
        int i, j, curIdx, len = num.size();
        string sum, op1, op2;
        for(i = 1; i <= (num[0] != '0'? (len - 1) / 2 : 1);++i)
        {
            for(j = 1; j <= (num[i] != '0' ? len - i * 2 : 1); ++j)
            {
                if(len < i + j + max(i,j)) break;
                op1 = num.substr(0,i);
                op2 = num.substr(i,j);
                sum = addS(op1, op2);
                curIdx = i + j;
                while(curIdx < len && sum  == num.substr(curIdx,sum.size()) )
                {
                    curIdx += sum.size();
                    op1 = sum;
                    sum = addS(sum, op2);
                    op2 = op1;
                }
                if(curIdx == len) return true;
            }
        }
        return false;
    }
};