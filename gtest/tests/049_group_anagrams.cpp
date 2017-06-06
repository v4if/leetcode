//
// Created by root on 6/6/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
 * */

using namespace std;

namespace brute {
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> ret;
            if (strs.empty()) return ret;

            int index;
            for (auto str : strs) {
                if ((index = isGroup(ret, str)) == -1) {
                    vector<string> first{str};
                    ret.push_back(first);
                } else {
                    ret[index].push_back(str);
                }
            }

            return ret;
        }

        int isGroup(vector<vector<string>> ret, string str) {
            sort(str.begin(), str.end());
            for (int i = 0; i < ret.size(); i++) {
                string lhs = ret[i][0];
                sort(lhs.begin(), lhs.end());
                if (!lhs.compare(str)) return i;
            }

            return -1;
        }
    };
}

namespace hash_optimize {
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (strs.empty()) return ret;

        unordered_map<string, int> stored;
        for (auto str : strs) {
            string temp{str};
            sort(temp.begin(), temp.end());

            unordered_map<string, int>::iterator ite = stored.find(temp);
            if (ite == stored.end()) {
                stored[temp] = static_cast<int>(ret.size());
                vector<string> first{str};
                ret.push_back(first);
            } else {
                ret[ite->second].push_back(str);
            }
        }

        return ret;
    }
}

// 省去了判断，直接利用unordered_map的key存储string向量组
namespace perfect_ {
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> um;
            int m = strs.size();

            for (int i = 0; i < m; i++) {
                string str = strs[i];
                sort(str.begin(), str.end());
                um[str].push_back(strs[i]);
            }

            vector<vector<string>> res;
            for (unordered_map<string, vector<string>>::iterator iter = um.begin(); iter != um.end(); iter++) {
                res.push_back(iter->second);
            }
            return res;
        }
    };
}

TEST(leetcode, group_anagrams) {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ret = hash_optimize::groupAnagrams(strs);
    for (auto v : ret) {
        for (auto str : v) {
            cout << str << " ";
        }
        cout << endl;
    }
}