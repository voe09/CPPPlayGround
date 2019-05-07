/*
Write a program to find top two candidates winning the election.

You are the administrator of an election system. The back end is offline and election results are requested.
All votes are logged to vote.log(stream). We want to see results in real time.

Rules:

A single voter can vote for 3 candidates.
A voter cannot vote for the same candidate more than once.
Using the log find the top 5 candidates and detect fraud by printing the voter id and not counting the vote.

Fraud is candidate voting more than 3 times and/or a candidate more than once.
*/

/*
@GG Thanks for the interesting question. Here are my thoughts:

Use a Map<Voter, Integer> to track how many candidates a voter voted. If < 3, accept this vote, otherwise, deny and print out this voter as fraud.
Use a Map<Candidate, Integer> to track how many tickets each candidate got.
Use a Heap<Map.Entry<Candidate, Integer>> to monitor the top 2 candidates.
*/
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;


class VotingSystem {
public:
    VotingSystem(int x) : k(x) {};

    void log(pair<int, int> vote) {
        int voter = vote.first, candidate = vote.second;
        if (voterId.count(voter)) {
            if (voterId[voter].size() >= 3) {
                std::cout << voter << " vote for more than 3 times." << std::endl;
                return;
            } else if (voterId[voter].count(candidate)) {
                std::cout << voter << " vote for the same candidate multiple times." << std::endl;
                return;
            }
        }
        voterId[voter].insert(candidate);

        if (candidateId.count(candidate)) {
            auto iter = candidateId[candidate];
            int freq = iter->second;
            votes[freq].erase(iter);
            if (!votes.count(freq)) {
                votes.erase(freq);
            }
            votes[freq + 1].push_front({candidate, freq + 1});
            candidateId[candidate] = votes[freq + 1].begin();
        } else {
            votes[1].push_front({candidate, 1});
            candidateId[candidate] = votes[1].begin();
        }
    }

    vector<int> request() {
        vector<int> res;
        int cnt = k;
        auto iter = votes.rbegin();
        while (cnt > 0) {
            auto tmp = iter->second;
            for (auto it = tmp.begin(); it != tmp.end(); ++it) {
                res.push_back(it->first);
                --cnt;
            }
            ++iter;
        }
        return res;
    }
private:
    int k;
    unordered_map<int, unordered_set<int>> voterId;
    unordered_map<int, list<pair<int, int>>::iterator> candidateId; 
    map<int, list<pair<int, int>>> votes;
};

int main() {
    VotingSystem vote = VotingSystem(2);
    vote.log({1, 1});
    vote.log({1, 1});
    vote.log({1, 3});
    vote.log({1, 2});
    vote.log({1, 4});
    vote.log({2, 1});
    vote.log({3, 1});
    vote.log({4, 1});
    vote.log({2, 2});
    auto res1 = vote.request();
    for (const auto &c : res1) {
        std:: cout << c << " ";
    }
    std::cout << std::endl;
    vote.log({2, 3});
    auto res2 = vote.request();
    for (const auto &c : res2) {
        std:: cout << c << " ";
    }
    std::cout << std::endl;
}
