//https://www.codingninjas.com/codestudio/problems/pascal-s-triangle_8230805?challengeSlug=striver-sde-challenge
//https://leetcode.com/problems/pascals-triangle/description/
// Create Pascal's triangle till n rows

class Solution {
public:
// TC - O(N^2)
// SC - O(N^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){
            vector<int> v(i+1, 1);
            ans.push_back(v);
            for(int j = 1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }




// TC - O(N^2)
// SC - O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i<numRows; i++){
            ans[i].resize(i+1, 1);
            for(int j = 1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};