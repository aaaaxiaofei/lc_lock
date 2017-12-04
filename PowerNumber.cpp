
/*
 * Complete the function below.
 */

struct Node {
    long base;
    int power;
    long val;
    Node(long b, int p, long v) : base(b), power(p), val(v) {}
};

struct Comp {
    bool operator() (Node a, Node b) {
        return a.val > b.val;
    }
};

long getPowerNumber(long index) {

    const int POWER_LIMIT = 32;
    long initial_base = 2;
    long count = 0;
    long pre = 0;
    
    priority_queue<Node, vector<Node>, Comp> q;
    
    for (int i = 2; i < POWER_LIMIT; i++) {
        long base = initial_base;
        int power = i;
        long val = pow(base, power);
        Node nd(base, power, val);
        q.push(nd);
    }
    
    while (count < index + 1) {
        Node nd = q.top();
        q.pop();
        
        // Count each power number only once
        if (nd.val != pre) count++;
        pre = nd.val;
        
        long base = nd.base + 1;
        int power = nd.power;
        long val = pow(base, power);
        
        Node new_nd(base, power, val);
        q.push(new_nd);
    }
    
    return pre;
    
}
