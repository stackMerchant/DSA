// https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    int n = x.size();
    int ret = 0;
    for (int i=0; i<n; i++) {
        // For every point, traverse rest of the array and find their orientation
        int duplicates = 0; // Either it will be duplicate
        int onVerticalLine = 0; // Or on vertical line
        unordered_map<double, int> slopeToCountMap; // Or it will have a slope, in this case count all with same slope
        int maxFromI = 0; // Mac points from i
        for (int j=i+1; j<n; j++) {
            double dx = x[j] - x[i];
            double dy = y[j] - y[i];
            
            if (dx == 0 && dy == 0) duplicates++;
            else if (dx == 0) onVerticalLine++;
            else {
                double m = dy/dx;
                slopeToCountMap[m]++;
                maxFromI = max(maxFromI, slopeToCountMap[m]);
            }
        }
        // Vertical line is infinite slope, so consider that in maxFromI calculation
        maxFromI = max(maxFromI, onVerticalLine);
        ret = max(ret, maxFromI + duplicates + 1);
    }
    return ret;
}
