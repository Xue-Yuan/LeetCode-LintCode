/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
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
private:
    priority_queue<int, vector<int>, less<int>> leftMaxHeap;
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    int currentSize;
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
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();