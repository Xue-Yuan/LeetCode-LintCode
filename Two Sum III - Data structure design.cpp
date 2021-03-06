/*
    Design and implement a TwoSum class. It should support the following operations: 
        add and find.

    add - Add the number to an internal data structure.
    find - Find if there exists any pair of numbers which sum is equal to the value.

    For example,
        add(1); add(3); add(5);
        find(4) -> true
        find(7) -> false
*/

class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto itr = m.begin(); itr != m.end(); itr++)
        {
            int remain = value - itr->first;
            if (m.find(remain) != m.end() && m[remain] - (remain == itr->first) > 0)
                return true;
        }
        return false;
	}
private:
    unordered_map<int, int> m;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
