// https://www.interviewbit.com/problems/seats/

// The idea is that everyone will come close to middle x

int Solution::seats(string A) {
    // Store all x positions
    int n = A.size(), mod = 1e7 + 3;
    vector<int> x_positions;
    for (int i=0; i<n; i++)
        if (A[i] == 'x')
            x_positions.push_back(i);
    
    // Calculate x_mid, all x will hop and come to x_mid
    int x_positions_size = x_positions.size();
    if (x_positions_size == 0) return 0;
    int x_mid = x_positions[x_positions.size() / 2];
    
    // For counting hops
    int curr_hops = 0, total_hops = 0;

    // Move all x before x_mid, to x_mid
    for (int i = x_mid; i >= 0; i--) {
        if (A[i] == '.')
            curr_hops++;
        else
            total_hops = (total_hops + curr_hops) % mod;
    }
    
    // Move all x after x_mid, to x_mid
    curr_hops = 0;
    for (int i = x_mid + 1; i < n; i++) {
        if (A[i] == '.')
            curr_hops++;
        else
            total_hops = (total_hops + curr_hops) % mod;
    }

    return total_hops;
}
