class Solution {
public:
    bool dfs(int node , vector<bool> &vis,vector<vector<int>>& rooms,vector<int> &path)
    {
        vis[node] = true;
        path.push_back(node);
        for(auto a: rooms[node])
        {
            if(!vis[a]){
            dfs(a,vis,rooms,path);}
        }
        return(rooms.size() == path.size());
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {  
        int n = rooms.size();
        vector<bool> vis(n,false);
        vector<int> path;
        if(dfs(0  , vis , rooms,path))  
        return true;
        else return false;
    }
};