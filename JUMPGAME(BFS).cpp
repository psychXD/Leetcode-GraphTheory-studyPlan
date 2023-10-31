//leetcode.com/problems/jump-game-iii/description/?envType=study-plan-v2&envId=graph-theory
class Solution {
public:
bool canReach(vector<int>& arr, int start) {
    queue<int> q;
    vector<bool> visited(arr.size(), false);  
    q.push(start);
    while (!q.empty()) {
        int k = q.front(); 
        if (k < 0 || k >= arr.size() || visited[k]) {
            q.pop();
            continue;
        }
        visited[k] = true;  // Mark the position as visited
        if (arr[k] == 0) {
            return true;  // If we reach a 0, return true
        }
        q.push(k + arr[k]);  // Push forward and backward positions
        q.push(k - arr[k]);
        q.pop();
    }   
    return false;  
}
};