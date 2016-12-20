class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < 32; ++i) {
            int high = 0, low = 0;
            for (int num : nums) {
                if ((num >> i) & 0x1) {
                    ++high;
                } else {
                    ++low;
                }
            }
            total += high * low;
        }    
        return total;
    }
};
