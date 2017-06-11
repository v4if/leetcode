//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * */

using namespace std;

namespace solve_first {
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;

//        先插入后合并重叠部分
        vector<Interval>::iterator idx = intervals.begin();
        for (; idx != intervals.end(); ++idx) {
            if (idx->start > newInterval.start) break;
        }
        intervals.insert(idx, newInterval);

        for (int i = 0; i < intervals.size(); ++i) {
            if (ret.empty() || ret.back().end < intervals[i].start) {
                ret.push_back(intervals[i]);
                continue;
            }
            ret.back().end = max(ret.back().end, intervals[i].end);
        }

        return ret;
    }
}

TEST(leetcode, insert_interval) {
    using namespace solve_first;
    vector<Interval> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<Interval> ret = insert(intervals, Interval(4,9));
    for (Interval inter : ret) {
        cout << inter.start << " " << inter.end << endl;
    }
}