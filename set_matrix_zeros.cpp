//https://leetcode.com/problems/set-matrix-zeroes/description/
// Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

class Solution {
public:
        // TC - (O(N*M)*(N+M))
        // SC - O(N*M)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int> (m, 1));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k<m; k++){
                        if(mat[i][k] !=0) mat[i][k] = 0;
                    }
                    for(int k = 0; k<n; k++){
                        if(mat[k][j]!=0) mat[k][j] = 0;
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0) matrix[i][j] = 0;
            }
        }
        return;
    }




        // TC - (O(N*M))
        // SC - O(N+M)
        // Matrix + Hash Table(2 unordered sets)
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> setRows;
        unordered_set<int> setColumns;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    setRows.insert(i);
                    setColumns.insert(j);
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(setRows.count(i)>0 || setColumns.count(j)>0){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }





        // TC - O(N*M)
        // SC - O(1)
        // Putting 0s in 1st row and 1st column of initial matrix
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false;
        bool flag2 = false;

        for(int i = 0; i<n; i++){
            if(matrix[i][0] == 0) flag1 = true;
        }

        for(int j = 0; j<m; j++){
            if(matrix[0][j] == 0) flag2 = true;
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<n; i++){
            for(int j = 1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(flag1 == true){
            for(int i = 0; i<n; i++){
                matrix[i][0] = 0;
            }
        }

        if(flag2 == true){
            for(int j = 0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
        return;
    }
};