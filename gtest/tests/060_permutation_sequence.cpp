//
// Created by root on 6/11/17.
//

#include <iostream>
#include <unordered_map>
#include <gtest/gtest.h>

/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 * */

using namespace std;

namespace solve_first {
    void backtrace(int n, int k, int idx, int& n_solve, string& solve, unordered_map<int, bool>& visited) {
        if (idx == n) {
            n_solve++;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (visited[i]) continue;

            visited[i] = true;
            solve.push_back(static_cast<char>(i + '0'));
            backtrace(n, k, idx + 1, n_solve, solve, visited);

            if (n_solve == k) break;
            visited[i] = false;
            solve.pop_back();
        }
    }
    
    string getPermutation(int n, int k) {
        string solve;
        unordered_map<int, bool> visited;
        int n_solve = 0;
        backtrace(n, k, 0, n_solve, solve, visited);
        
        return solve;
    }
}

TEST(leetcode, permution_sequence) {
    EXPECT_EQ("132", solve_first::getPermutation(3, 2));
}