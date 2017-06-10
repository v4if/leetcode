//
// Created by root on 6/10/17.
//

#include <iostream>
#include <gtest/gtest.h>

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 * */

using namespace std;

namespace solve_first {
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](Interval first, Interval second){
            return first.start < second.start;
        });
        for (int i = 0; i < n; ++i) {
            int begin = i;
            int max = intervals[begin].end;
            while (i + 1 < n && max >= intervals[i + 1].start) {
                i++;
                if (intervals[i].end > max) max = intervals[i].end;
            }

            ret.push_back(Interval(intervals[begin].start, max));
        }

        return ret;
    }
}

TEST(leetcode, merge_intervals) {
    using namespace solve_first;
    vector<Interval> intervals{{1,3},{2,6},{8,10},{15,18}};
    vector<Interval> ret = merge(intervals);
    for (Interval inter : ret) {
        cout << inter.start << " " << inter.end << endl;
    }
}