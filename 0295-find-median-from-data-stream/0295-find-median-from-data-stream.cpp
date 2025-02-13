class MedianFinder {
public:
    priority_queue<int> max_heap; // Max heap (left half)
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap (right half)

    void addNum(int num) {
        // Step 1: Add to the appropriate heap
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        // Step 2: Balance the heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if (max_heap.size() == min_heap.size()) {
            return (max_heap.top() + min_heap.top()) / 2.0; // Convert to double for correct division
        }
        return max_heap.top();
    }
};
