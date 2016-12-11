vector<int> dayChange(vector<int> &days, int n) {
    vector<int> newDays(days.size()+2, 0);
    for (int i = 0; i < (int)days.size(); i++) {
        newDays[i+1] = days[i];
    }
    for (int i = 0; i < n; i++) {
        int pre = 0;
        for (int j = 1; j < (int)newDays.size()-1; j++) {
            int tmp = newDays[j];
            newDays[j] = pre != newDays[j+1];
            pre = tmp;
        }
    }
    return vector<int>(newDays.begin()+1, newDays.end()-1);
}
