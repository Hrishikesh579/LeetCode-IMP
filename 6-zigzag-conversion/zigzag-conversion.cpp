class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(n == 0 || numRows == 0 || numRows == 1) return s;
        int numColumns = ((n/(2*(numRows) - 2) + 1)*(numRows - 2 + 1));
        n%(2*numRows - 2) <= numRows ? numColumns += 1 : numColumns += (n%(2*numRows - 2)%numRows);
        bool goDown = true;
        vector<vector<char>> zigzag(numRows, vector<char>(numColumns, ' '));
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if(k >= numColumns || j > numRows) break;
            zigzag[j][k] = s[i];
            if (j == 0) {
                goDown = true;
            }
            if (j == numRows - 1)
                goDown = false;

            if (goDown) {
                j++;
            } else {
                j--;
                k++;
            }
        }
        string res = "";
        for(int i = 0; i < numRows; i++){
            for(int l = 0; l < numColumns; l++){
                if(zigzag[i][l] != ' ') res += zigzag[i][l];
            }
        }
        return res;
    }
};