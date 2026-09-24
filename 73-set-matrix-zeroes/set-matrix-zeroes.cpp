class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Valid! Solves in O(K*(N + M)) time complexity but takes O(K) space. 
        // vector<pair<int, int>> v;
        // int n = matrix.size(), m = matrix[0].size();
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(matrix[i][j] == 0){
        //             pair<int, int> p = {i, j};
        //             v.push_back(p);
        //         }
        //     }
        // }
        // for(auto& i : v){
        //     for(int j = 0; j < n; j++){
        //         matrix[j][i.second] = 0;
        //     }
        //     for(int j = 0; j < m; j++){
        //         matrix[i.first][j] = 0;
        //     }
        // }
        // return;
        //----------------------------------------------------------O(1) Space solution------------------------------------------------------
        bool firstRowZero = false;
        bool firstColumnZero = false;

        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0) {
                firstColumnZero = true;
                break;
            }
        }

        for(int j = 0; j < m; j++){
            if(matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstColumnZero){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
        if(firstRowZero){
            for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
            }
        }
        return;
    }
};