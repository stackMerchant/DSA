// https://www.interviewbit.com/problems/egg-drop-problem/

// Solution: Reference + Binary search
// Reference: https://www.youtube.com/watch?v=3hcaVyX00_4

int getAns(int eggs, int floors, vector<vector<int>> &dp) {
    if (eggs == 1) return floors;
    if (floors == 0) return 0;
    
    if (dp[eggs][floors] != -1) return dp[eggs][floors];
    
    int high = floors;
    int low = 1;
    int minSteps = INT_MAX;
    
    while (low <= high) {
        int mid = (high + low) / 2;
        int eggNotBreak = getAns(eggs, floors-mid, dp);
        int eggBreak = getAns(eggs-1, mid-1, dp);
        
        if (eggBreak > eggNotBreak) {
            minSteps = min(minSteps, eggBreak + 1);
            high = mid-1;
        } else {
            minSteps = min(minSteps, eggNotBreak + 1);
            low = mid+1;
        }
    }
    dp[eggs][floors] = minSteps;
    return minSteps;
}

int Solution::solve(int eggs, int floors) {
    vector<vector<int>> dp(eggs+1, vector<int>(floors+1, -1));
    return getAns(eggs, floors, dp);    
}
