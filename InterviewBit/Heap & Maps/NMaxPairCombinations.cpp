// https://www.interviewbit.com/problems/n-max-pair-combinations/

class Item {
    public:
        int sum;
        int a;
        int b;
        Item (int _sum, int _a, int _b) {
            sum = _sum;
            a = _a;
            b = _b;
        }
};

class Compare {
    public:
        bool operator()(const Item &i1, const Item &i2) {
            return i1.sum < i2.sum;
        }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int C = A.size();
    
    // Sort arrays
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    set<pair<int, int>> set; // to keep track of processed pairs
    priority_queue<Item, vector<Item>, Compare> pq; // top sum values
    pq.push(Item(A[0] + B[0], 0, 0)); // push initial value
    
    vector<int> ans;
    while (C > 0 && !pq.empty()) {
        // Pop top item and its values
        Item topItem = pq.top(); pq.pop();
        int sum = topItem.sum;
        int a = topItem.a;
        int b = topItem.b;
        
        if (set.find({a, b}) != set.end()) continue; // see if already processed
        set.insert({a, b}); // mark processed
        ans.push_back(sum); // push this value
        
        // Push next values
        if (a+1 < A.size()) pq.push(Item(A[a+1] + B[b], a+1, b));
        if (b+1 < B.size()) pq.push(Item(A[a] + B[b+1], a, b+1));
        
        C--;
    }
    return ans;
}
