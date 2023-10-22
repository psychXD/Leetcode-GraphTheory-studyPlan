//not optimised
//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=study-plan-v2&envId=graph-theory
void dfs(int city, int dst, int stops, int& minCost, int currentCost, 
             vector<vector<pair<int, int>>>& graph, unordered_set<int>& visited) {
        if(city == dst) {
            minCost = min(minCost, currentCost);
            return;
        }
        if(stops < 0) return;

        visited.insert(city);

        for(auto next : graph[city]) {
            int nextCity = next.first;
            int priceToNextCity = next.second;

            if(currentCost + priceToNextCity > minCost) continue;
            if(visited.count(nextCity)) continue;

            dfs(nextCity, dst, stops-1, minCost, currentCost + priceToNextCity, graph, visited);
        }

        visited.erase(city);
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n); 
        for(const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});

        }
        
        int minCost = INT_MAX;
        unordered_set<int> visited;
        dfs(src, dst, k, minCost, 0, graph, visited); 

        return minCost == INT_MAX ? -1 : minCost;
    }
