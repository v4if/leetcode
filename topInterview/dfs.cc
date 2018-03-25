//dfs 正向演绎 bottomUp  <--> 终局思维 upDown 需要做cache 记忆化递归
/*
 * params : 当前状态， 终止状态， 已经访问过的状态， 全局最终解
 * vis <状态，达到该状态下的解>
 * 
    int result = 0;
    map<S_t, int> vis;
    S_t root = make_pair(1,1);
    vis[root] = 0;
    dfs_bottomUp(root, 6, vis, result);
    cout << result << endl;
 * */
typedef pair<int, int> S_t;
void dfs_bottomUp(S_t cur, int n, map<S_t, int>& vis, int& result) {
    int curRes = vis[cur];
    if (cur.first == n) {
        if (curRes < result) result = curRes;
        return;
    }

    if (cur.first > n || curRes >= result) return;

    S_t next = make_pair(cur.first * 2, cur.first);
    if (!vis[next]) {
        vis[next] = curRes + 1 ;
        dfs_bottomUp(next, n, vis, result);
    }

    next.first = cur.first + cur.second;
    next.second = cur.second;
    if (!vis[next]) {
        vis[next] = curRes + 1;
        dfs_bottomUp(next, n, vis, result);
    }
}
