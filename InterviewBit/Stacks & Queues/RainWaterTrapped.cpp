// https://www.interviewbit.com/problems/rain-water-trapped/

/************ Solution 1 ************/

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    
    // For each element, get maximum element on left
    vector<int> left(n, -1);
    int maxLeft = A[0];
    for (int i=0; i<n; i++) {
        maxLeft = max(maxLeft, A[i]);
        left[i] = maxLeft;
    }
    
    // For each element, get maximum element on right
    vector<int> right(n, -1);
    int maxRight = A[n-1];
    for (int i=n-1; i>=0; i--) {
        maxRight = max(maxRight, A[i]);
        right[i] = maxRight;
    }
    
    int ret = 0, height, waterStore;
    for (int i=0; i<n; i++) {
        // Height upto which water can be stored at current index
        height = min(left[i], right[i]);
        // Amount of water that can be stored at current index
        waterStore = max(height - A[i], 0);
        ret += waterStore;
    }
    return ret;
}

/************ Solution 2 ************/

// Keep increasing height and add water at each level

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int currHeight = 0, sum = 0, x, y;
    while(1) {
        // Calculate left and right limits on currHeight
        x = 0; while (x < n && A[x] < currHeight) x++;
        y = n-1; while (y >= 0 && A[y] < currHeight) y--;
        
        // i is past max height
        if(x==n && y==-1) break;
        // For indexes where A[i] < i, 1 unit of water will be counted
        for (int j=x; j<=y; j++) if(A[j] < currHeight) sum += 1;
        currHeight++;
    }
    return sum;
}