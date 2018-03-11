/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

class Solution {
public:
    bool dfs(char* matrix, int rows, int cols, char* str, int idx, vector<pair<int,int>>& used, int curI, int curJ) {
        if (idx == strlen(str)) return true;
        
        vector<pair<int, int>> dirs{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0;i < dirs.size();i++) {
            pair<int, int> next{curI + dirs[i].first, curJ + dirs[i].second};
            if (next.first < 0 || next.first > rows - 1 || next.second < 0 || next.second > cols - 1) continue;
            if (matrix[next.first * cols + next.second] == str[idx] && find(used.begin(), used.end(), next) == used.end()) {
                used.emplace_back(next.first, next.second);
                bool flag = dfs(matrix, rows, cols, str, idx+1, used, next.first, next.second);
                if (flag) return true;
                used.pop_back();
            }
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        vector<pair<int, int>> used;
        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                if (matrix[i * cols + j] == str[0]) {
                    used.emplace_back(i,j);
                    bool flag = dfs(matrix, rows, cols, str, 1, used, i, j);
                    if (flag) return true; 
                    used.pop_back();
                }
            }
        }
        return false;
    }


};
