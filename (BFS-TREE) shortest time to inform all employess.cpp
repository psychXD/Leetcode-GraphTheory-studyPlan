class Solution {
public:
 int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
 {
     vector<int> adj[n];
     for(int i = 0 ; i < manager.size();i++)
     {
         if(manager[i]!=-1)
         {
             adj[manager[i]].push_back(i);
         }
     }

     queue<pair<int, int>> q;
     q.push({headID,0});
     vector<bool>vis(n,false);
     vis[headID]=true;
     int time=0,ans=0;
     while(!q.empty())
     {
         int manager = q.front().first;
         int time = q.front().second;
         ans = max(ans,time);
         q.pop();
           for(auto &temp:adj[manager]){
                if(vis[temp] == false){
                    vis[temp]=true;
                    q.push({temp,time+informTime[manager]});
                }
            }
     }
     return ans;
 }
};