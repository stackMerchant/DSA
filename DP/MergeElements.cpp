// https://www.interviewbit.com/problems/merge-elements/

class ColorAndCost {
    public:
        int color;
        int cost;
        
        ColorAndCost(int _color, int _cost) {
            color = _color;
            cost = _cost;
        }
};

ColorAndCost find(vector<int> &A, int a, int b, vector<vector<ColorAndCost>> &dp) {
    if (dp[a][b].cost != -1) return dp[a][b];
    if (a == b) {
        dp[a][b] = ColorAndCost(A[a], 0);
        return dp[a][b];
    }
    
    int minCost = INT_MAX;
    int minColor;
    for (int i=a; i<b; i++) {
        ColorAndCost partition1 = find(A, a, i, dp);
        ColorAndCost partition2 = find(A, i+1, b, dp);
        int mergeCost = partition1.cost + partition2.cost + partition1.color + partition2.color;

        if (mergeCost < minCost) {
            minCost = mergeCost;
            minColor = partition1.color + partition2.color;
        }
    }
    
    dp[a][b] = ColorAndCost(minColor, minCost);
    return dp[a][b];
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<ColorAndCost>> dp(n, vector<ColorAndCost>(n, ColorAndCost(-1, -1)));
    return find(A, 0, n-1, dp).cost;
}
