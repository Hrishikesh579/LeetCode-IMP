class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    pair<int, int> p = {i, j};
                    v.push_back(p);
                }
            }
        }
        for(auto& i : v){
            for(int j = 0; j < n; j++){
                matrix[j][i.second] = 0;
            }
            for(int j = 0; j < m; j++){
                matrix[i.first][j] = 0;
            }
        }
        return;
    }
};