// https://www.interviewbit.com/problems/commutable-islands/

bool comp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int getParent(vector<int> &parents, int a) {
    if (parents[a] == a) return a;
    parents[a] = getParent(parents, parents[a]);
    return parents[a];
}

void merge(vector<int> &parents, vector<int> &ranks, int a, int b) {
    if (ranks[a] >= ranks[b]) {
        parents[b] = a;
        ranks[a] += ranks[b];
    } else {
        parents[a] = b;
        ranks[b] += ranks[a];
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), comp);
    
    // Initialize parents and ranks
    vector<int> parents(A+1); for (int i=1; i<=A; i++) parents[i] = i;
    vector<int> ranks(A+1, 1);
    
    int ret = 0, src, dest, cost, srcParent, destParent;
    for (auto b: B) {
        src = b[0];
        dest = b[1];
        cost = b[2];
        
        // Get parents
        srcParent = getParent(parents, src);
        destParent = getParent(parents, dest);
        
        // If not already connected
        if (srcParent != destParent) {
            merge(parents, ranks, srcParent, destParent);
            ret += cost;
        }
    }
    return ret;
}
