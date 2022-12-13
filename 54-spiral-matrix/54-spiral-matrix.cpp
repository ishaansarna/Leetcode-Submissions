class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left, right, top, bottom;
        left = top = 0;
        bottom = matrix.size();
        right = matrix[0].size();
        right = right == 1 ? 0 : right;
        int i=0, j=0;
        vector<int> res;
        while (true) {
            res.push_back(matrix[i][j]);
            if (j+1 < right && i == top) {
                j++;
                if (j == right-1) {
                    right--;
                }
            }
            else if (i+1 < bottom && j == right) {
                i++;
                if (i == bottom-1) {
                    bottom--;
                }
            }
            else if (j-1 >= left && i == bottom) {
                j--;
                if (j == left) {
                    left++;
                }
            }
            else if (i-1 > top && j == left-1) {
                i--;
                if (i == top+1) {
                    top++;
                }
            }
            else {
                break;
            }
        }
        return res;
    }
};