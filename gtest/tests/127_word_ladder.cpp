//
// Created by root on 9/21/17.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <gtest/gtest.h>

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
UPDATE (2017/1/20):
The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 * */

using namespace std;

namespace word_ladder {
    vector<string> getNeighbors(string prev, vector<string>& wordList) {
        int wordSize = prev.size();
        vector<string> mayNeighbors;
        for (int i = 0; i < wordSize; ++i) {
            string word = prev;
            word[i] = '_';
            mayNeighbors.push_back(word);
        }

        vector<string> neighbors;
        for (int i = 0; i < wordList.size();) {
            int j;
            for (j = 0; j < wordSize; ++j) {
                string word = wordList[i];
                word[j] = '_';
                if (std::find(mayNeighbors.begin(), mayNeighbors.end(), word) != mayNeighbors.end()) {
                    neighbors.push_back(wordList[i]);
                    wordList.erase(wordList.begin() + i);
                    break;
                }
            }

            i = (j == wordSize) ? ++i : i;
        }
        return neighbors;
    }
//    最短路径问题
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> neighbors = getNeighbors(beginWord, wordList);
        int breadth = neighbors.size();
        if (0 == breadth) return 0;

        queue<string> q;
        for (int i = 0; i < breadth; ++i) {
            q.push(neighbors[i]);
        }
        int length = 1;
        string tag;
        int nextBreadth = 0;
        while (!q.empty()) {
            tag = q.front();
            q.pop();
            breadth--;

            if (tag == endWord) return length + 1;

            neighbors = getNeighbors(tag, wordList);
            nextBreadth += neighbors.size();
            for (int i = 0; i < neighbors.size(); ++i) {
                q.push(neighbors[i]);
            }

            if (0 == breadth) {
                length++;
                breadth = nextBreadth;
                nextBreadth = 0;
            }
        }

        return 0;
    }

    string vectorToString(vector<string> v) {
        string out;
        for (int i = 0; i < v.size(); ++i) {
            out += v[i] + ", ";
        }
        return out.substr(0, out.size() - 2);
    }
}

namespace word_ladder_try {
    void addNextWords(string word, vector<string>& wordList, queue<string>& toVisit) {
        for (int i = 0; i < (int)word.size(); ++i) {
            char letter = word[i];
            for (int j = 0; j < 26; j++) {
                word[i] = 'a' + j;
                auto index = find(wordList.begin(), wordList.end(), word);
                if (index != wordList.end()) {
                    toVisit.push(word);
                    wordList.erase(index);
                }
            }
            word[i] = letter;
        }

    }
//    最短路径问题
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> toVisit;
        addNextWords(beginWord, wordList, toVisit);
        int dist = 2;
        while (!toVisit.empty()) {
            int num = toVisit.size();
            string word;
            for (int i = 0; i < num; ++i) {
                word = toVisit.front();
                toVisit.pop();
                if (word == endWord) return dist;
                addNextWords(word, wordList, toVisit);
            }
            dist++;
        }

        return 0;
    }

    string vectorToString(vector<string> v) {
        string out;
        for (int i = 0; i < v.size(); ++i) {
            out += v[i] + ", ";
        }
        return out.substr(0, out.size() - 2);
    }
}

namespace two_end_search {
     
}

TEST(leetcode, leetcode_word_ladder__Test) {
    using namespace word_ladder_try;
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    int length = ladderLength("hit", "cog", wordList);

    cout << length << endl;
}