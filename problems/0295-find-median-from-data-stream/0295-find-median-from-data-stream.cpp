class MedianFinder {
public:
    
    priority_queue<int> maxheap;  
    priority_queue<int, vector<int>, greater<int>> minheap;
    int curr_size;    
    
    MedianFinder() {
        curr_size = 0;
    }
    
    void addNum(int num) {
        if (maxheap.empty() || maxheap.top() >= num) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } 
        else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }

        curr_size++;
    }
    
    double findMedian() {
        if (curr_size % 2 == 1) {
            return maxheap.top();
        } else {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
    }
};