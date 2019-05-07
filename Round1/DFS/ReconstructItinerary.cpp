/*
Given a list of airline tickets represented by pairs of departure and arrival
airports [from, to], reconstruct the itinerary in order. All of the tickets
belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that 
has the smallest lexical order when read as a single string. For example, the 
itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But 
it is larger in lexical order.
 */

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        vector<string> path;
        unordered_map<string, multiset<string>> ht;
        for (const auto& pair : tickets) {
            ht[pair.first].insert(pair.second);
        }

        dfs(ht, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }

private:
    void dfs(unordered_map<string, multiset<string>>& ht, string s, vector<string>& res) {
        while (ht[s].size()) {
            string tmp = *ht[s].begin();
            ht[s].erase(ht[s].begin());
            dfs(ht, tmp, res);
        }
        res.push_back(s);
    }
};


// http://www.cnblogs.com/grandyang/p/5183210.html
class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            ++graph[ticket.first][ticket.second];
        }
        const string from{"JFK"};
        vector<string> ans{from};
        routeHelper(from, tickets.size(), &graph, &ans);
        return ans;
    }

private:
    bool routeHelper(const string& from, const int ticket_cnt,
                     unordered_map<string, map<string, int>> *graph, vector<string> *ans) {

        if (ticket_cnt == 0) {
            return true;
        }

        for (auto& to : (*graph)[from]) {
            if (to.second) {
                --to.second;
                ans->emplace_back(to.first);
                if (routeHelper(to.first, ticket_cnt - 1, graph, ans)) {
                    return true;
                }
                ans->pop_back();
                ++to.second;
            }
        }
        return false;
    }
};
