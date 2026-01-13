// https://www.interviewbit.com/problems/two-teams/

/************ Solution 1 ************/
// Create enemy graph and see if bipartite

bool dfs(int node, int allowedTeam, vector<int> &team, vector<vector<int>> &adj) {
    // if unvisited
    if (team[node] == 0) {
        team[node] = allowedTeam;
        for (auto &_adj: adj[node]) {
            if (!dfs(_adj, -1 * allowedTeam, team, adj)) return false;
        }
        return true;
    }
    
    // if visited and valid
    if (team[node] == allowedTeam) return true;
    // visited but invalid
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // create adjacency
    vector<vector<int>> adj(A+1);
    for (auto &b: B) {
        adj[b[0]].push_back(b[1]);
        adj[b[1]].push_back(b[0]);
    }
    
    // team assignments
    // 0 unassigned, 1 and -1 are teams
    vector<int> team(A+1, 0);
    
    // start from all unvisited nodes and see if can be bipartite graph
    // why not start from just one node? because graph can be disjoint
    for (int i=1; i<=A; i++) {
        if (team[i] == 0) {
            if (!dfs(i, 1, team, adj)) return false;
        }
    }
    
    return true;
}

/************ Solution 2 ************/
// Backtracking, gives TLE

bool isPossible(int i, int n, vector<vector<int>> &enemyPairs, vector<int> &teams) {
    if (i == n) return true; // all enemy pairs are resolved
    
    // extract players
    int p1 = enemyPairs[i][0];
    int p2 = enemyPairs[i][1];
    
    // if both unassigned
    if (teams[p1] == 0 && teams[p2] == 0) {
        // assign teams and recurse
        teams[p1] = -1;
        teams[p2] = 1;
        if (isPossible(i+1, n, enemyPairs, teams)) return true;
        // reverse assign teams and recurse
        teams[p1] = 1;
        teams[p2] = -1;
        if (isPossible(i+1, n, enemyPairs, teams)) return true;
        // clean both
        teams[p1] = 0;
        teams[p2] = 0;
        return false;
    }
    
    // if p1 is unassigned
    if (teams[p1] == 0) {
        teams[p1] = -1 * teams[p2];
        if (isPossible(i+1, n, enemyPairs, teams)) return true;
        teams[p1] = 0; // clean
        return false;
    }
    
    // if p2 is unassigned
    if (teams[p2] == 0) {
        teams[p2] = -1 * teams[p1];
        if (isPossible(i+1, n, enemyPairs, teams)) return true;
        teams[p2] = 0; // clean
        return false;
    }
    
    // if both assigned to same
    if (teams[p1] == teams[p2]) return false;
    
    // if both assigned to different
    if (isPossible(i+1, n, enemyPairs, teams)) return true;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &enemies) {
    // track team assignment
    // 0 unassigned, 1 and -1 are teams
    vector<int> teams(A+1, 0);
    return isPossible(0, enemies.size(), enemies, teams);
}
