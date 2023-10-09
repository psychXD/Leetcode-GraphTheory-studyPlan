class Solution {
public:
    vector<int> setu; 
    int papa(int x) {
        if (setu[x] == -1)
            return x;
        return setu[x] = papa(setu[x]);
    }

    void unionmerge(int a, int b) {
        int PapaA = papa(a);
        int PapaB = papa(b);

        if (PapaA == PapaB)
            return;
        setu[PapaA] = PapaB;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        setu.resize(n, -1); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j])
                    unionmerge(i, j);
            }
        }
        int temp = 0;
        for (int i = 0; i < n; i++) {
            if (setu[i] == -1)
                temp++;
        }
        return temp;
    }
};
