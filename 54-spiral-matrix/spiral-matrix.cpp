class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        int LastRow = n - 1, LastColumn = m - 1;
        int FirstRow = 0, FirstColumn = 0;
        while (FirstRow <= LastRow && FirstColumn <= LastColumn) {
            for (int i = FirstColumn; i <= LastColumn; i++) {
                res.push_back(matrix[FirstRow][i]);
            }
            FirstRow++;

            for (int i = FirstRow; i <= LastRow; i++) {
                res.push_back(matrix[i][LastColumn]);
            }
            LastColumn--;

            if (FirstRow <= LastRow) {
                for (int i = LastColumn; i >= FirstColumn; i--) {
                    res.push_back(matrix[LastRow][i]);
                }
                LastRow--;
            }
            if (FirstColumn <= LastColumn) {

                for (int i = LastRow; i >= FirstRow; i--) {
                    res.push_back(matrix[i][FirstColumn]);
                }
                FirstColumn++;
            }
        }
        return res;
    }
};