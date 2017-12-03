346. Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        limit = size;
        sum = 0;
    }
    
    double next(int val) {
        
        sum += val;
        q.push(val);
        
        if (q.size() > limit) {
            sum -= q.front();
            q.pop();
        }
        
        return (double) sum / (double) q.size();
    }
    
private:
    int limit;
    int sum;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */