/*
    Median is the middle value in an ordered integer list. If the size 
        of the list is even, there is no middle value. So the median is 
        the mean of the two middle value.

    Examples: 
        [2,3,4] , the median is 3

        [2,3], the median is (2 + 3) / 2 = 2.5

    Design a data structure that supports the following two operations:

        void addNum(int num) - Add a integer number from the data stream 
            to the data structure.
        double findMedian() - Return the median of all elements so far.
    
    For example:

        add(1)
        add(2)
        findMedian() -> 1.5
        add(3) 
        findMedian() -> 2
*/

/*
    currentSize odd: median is the rightMinHeap.top()
    currentSize even: median is (rightMinHeap.top() + leftMaxHeap.top()) / 2.0
*/
class MedianFinder
{
public:

    // Adds a number into the data structure.
    void addNum(int num)
    {
        if (smaller.empty()) smaller.push(num);
        else if (smaller.size() == bigger.size())
        {
            if (num > bigger.top())
            {
                smaller.push(bigger.top());
                bigger.pop();
                bigger.push(num);
            }
            else smaller.push(num);
        }
        //make sure smaller.size() == bigger.size() or smaller.size() == bigger.size() + 1
        else if (num < smaller.top())
        {
            bigger.push(smaller.top());
            smaller.pop();
            smaller.push(num);
        }
        else bigger.push(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        if (smaller.size() == bigger.size()) 
            return smaller.top() + double(bigger.top() - smaller.top()) / 2.0;
        return smaller.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> bigger;
    priority_queue<int> smaller;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

class MedianFinder 
{
public:
    MedianFinder():currentSize(0){}
    // Adds a number into the data structure.
    void addNum(int num) 
    {

        if(!(currentSize & 0x1))        //even
        {
            if(currentSize != 0 && num < leftMaxHeap.top()) //have to check for the start condition
            {
                leftMaxHeap.push(num);
                num = leftMaxHeap.top();
                leftMaxHeap.pop();
            }
            rightMinHeap.push(num);
        }
        else
        {
            if(num > rightMinHeap.top())
            {
                rightMinHeap.push(num);
                num = rightMinHeap.top();
                rightMinHeap.pop();
            }
            leftMaxHeap.push(num);
        }
        ++currentSize;
    }

    // Returns the median of current data stream
    double findMedian() 
    {
        if(!currentSize) return -1; //error
        if(currentSize & 0x1)
            return rightMinHeap.top();
        else
            return leftMaxHeap.top() + (rightMinHeap.top() - leftMaxHeap.top()) / 2.0;
    }
private:
    priority_queue<int, vector<int>, less<int>> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    int currentSize;
};
