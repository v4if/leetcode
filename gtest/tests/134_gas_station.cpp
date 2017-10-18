//
// Created by root on 10/17/17.
//

#include <iostream>
#include <gtest/gtest.h>
#include <numeric>

/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * */

using namespace std;

namespace gas_station {
    bool helper(vector<int> gas, vector<int> cost, int index) {
        int tank = 0;
        for (int i = 0; i < gas.size(); ++i) {
            int r = (int)((index + i) % gas.size());
            tank += gas[r];
            if (tank < cost[r]) return false;
            tank -= cost[r];
        }

        return true;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        assert(gas.size() == cost.size());

        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] >= cost[i]) {
                if (helper(gas, cost, i))
                    return i;
            }
        }

        return -1;
    }
}

namespace gas_station1 {

//    找到第一个连续子序列（这个子序列的结尾必然是n）大于0的
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int start = 0, netGasSum = 0, curGasSum = 0;
        for(int i=0; i<cost.size(); i++) {
            netGasSum += gas[i] - cost[i];
            curGasSum += gas[i] - cost[i];
            if(curGasSum<0) {
                start = i+1;
                curGasSum = 0;
            }
        }
        if(netGasSum < 0) return -1;
        return start;
    }
}

TEST(leetcode, leetcode_gas_station__Test) {
    vector<int> gas{5,2,1,8};
    vector<int> cost{4,3,2,2};
    std::cout << gas_station1::canCompleteCircuit(gas, cost) << std::endl;
}