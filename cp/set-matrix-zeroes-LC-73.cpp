#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>&nums) {
   for(int x : nums) cout << x << "\t";
   cout << endl;
}

/*
 * Time Complexity: O(mn + k(m+ n)) Space Complexity: O(mn)
void setZero(vector<vector<int>>&nums, int i, int j) {
   int m = (int)nums.size(); // m rows
   int n = (int)nums[0].size(); // n columns

   for(int row = 0; row < m; ++ row) {
      nums[row][j] = 0;
   }

   for(int col = 0; col < n; ++ col) {
      nums[i][col] = 0;
   }

}
void setZeroes(vector<vector<int>>& matrix) {
   int m = (int)matrix.size(); // m rows
   int n = (int)matrix[0].size(); // n columns
   vector<vector<int>> indices;

   for(int i = 0; i < m; ++ i) {
      for(int j = 0; j < n; ++ j) {
          if(matrix[i][j] == 0) { cout << "i: " << i << " j: " << j << endl; indices.push_back({i, j}); }
      }
   }

   for(int i = 0; i < (int)indices.size(); ++ i) {
          setZero(matrix, indices[i][0], indices[i][1]);
   }

}
*/

int main(void) {

   vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
   // vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
   
   for(int i = 0; i < (int)matrix.size(); ++ i)
      print(matrix[i]);

   // setZeroes(matrix);

   cout << endl;

   for(int i = 0; i < (int)matrix.size(); ++ i)
      print(matrix[i]);

   return 0;
}
