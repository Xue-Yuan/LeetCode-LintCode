int solution(vector<int> &nums) {
    int total = 0, l = -2;
    nums.push_back(0), nums.push_back(1);
    for (int r=0; r<(int)nums.size(); r++) {
        if (nums[r]) {
            if (int diff = r-l-1) {
                total += diff / 2 - (0x1 ^ (diff & 0x1));
            }
            l = r;
        }
    }
    return total;
}
