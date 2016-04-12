/*
    Given a nested list of integers, implement an iterator to flatten it.

    Each element is either an integer, or a list -- whose elements may also 
        be integers or other lists.

    Example 1:
    Given the list [[1,1],2,[1,1]],

    By calling next repeatedly until hasNext returns false, the order of elements
         returned by next should be: [1,1,2,1,1].

    Example 2:
    Given the list [1,[4,[6]]],

    By calling next repeatedly until hasNext returns false, the order of elements
         returned by next should be: [1,4,6].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    using vitr = vector<NestedInteger>::iterator;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty())
            stk.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        return cur;
    }

    bool hasNext() {
        if (stk.empty()) return false;
        auto p = stk.top();
        if (++stk.top().first == stk.top().second)
            stk.pop();
        if (p.first->isInteger())
        {
            cur = p.first->getInteger();
            return true;
        }
        auto &lst = p.first->getList();
        if (!lst.empty())
            stk.push({lst.begin(), lst.end()});
            
        return hasNext();
    }
private:
    stack<pair<vitr, vitr>> stk;
    int cur;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

class NestedIterator {
    using vitr = vector<NestedInteger>::iterator;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (!nestedList.empty())
            stk.push({nestedList.begin(), nestedList.end()});
    }

    int next() {
        return cur;
    }

    bool hasNext() {
        if (stk.empty()) return false;
        
        auto p = stk.top();
        while (true)
        {
            if (++stk.top().first == stk.top().second)
                stk.pop();
            
            if (p.first->isInteger())
            {
                cur = p.first->getInteger();
                return true;
            }
            
            auto &lst = p.first->getList();
            if (!lst.empty())
                stk.push({lst.begin(), lst.end()});
                
            if (!stk.empty()) p = stk.top();
            else return false;
        }
    }
private:
    stack<pair<vitr, vitr>> stk;
    int cur;
};

