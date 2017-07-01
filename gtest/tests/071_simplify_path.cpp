//
// Created by root on 2/25/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <stack>
#include <string>

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
 * */

using namespace std;

namespace solve_first {
    bool eat(string path, int& pos) {
        unsigned int end = path.find_first_of("/", pos);
        if (end != string::npos) pos = ++end;
        else return false;

        while (end < path.length() && path[end] == '/') {
            end++;
            pos++;
        }
        return end < path.length();
    }
    string get_value(string path, int& pos) {
        unsigned int end = path.find_first_of("/", pos);
        if(end != string::npos) {
            string v = path.substr(pos, end - pos);
            pos = end;
            return v;
        } else {
            return path.substr(pos, path.length() - pos);
        }
    }
    string simplifyPath(string path) {
        if (path.length() == 0) return nullptr;

        std::vector<string> v_path;
        int pos = 0;
        while (eat(path, pos)) {
            string v = get_value(path, pos);
            if (v.compare("..") == 0 && !v_path.empty()) {
                v_path.pop_back();
            } else if (v.compare(".") != 0){
                v_path.push_back(v);
            }
        }

        if (v_path.empty()) return "/";

        string ans;
        for (int i = 0; i < v_path.size(); ++i) {
            ans.push_back('/');
            ans.append(v_path[i]);
        }
        return ans;
    }
}

TEST(leetcode, leetcode_simplify_path_test) {
    cout << solve_first::simplifyPath("/.") << endl;
}