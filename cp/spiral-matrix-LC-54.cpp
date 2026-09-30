#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

//                                                 LEETCODE #54

void print(vector<int>& nums) {
   for(int x : nums) cout << x << "\t";
   cout << endl;
}

/* Works only for matrices with 3 rows
vector<int> spiralOrder(vector<vector<int>> & matrix) {
   int row = (int)matrix.size(), col = (int)matrix[0].size();

   vector<int> output;

   int j = 0, i = 0;
   for(j = 0; j < col; ++ j) {
      output.push_back(matrix[i][j]);
   }
   j -=1;
   for(i = 1; i < row; ++ i) {
      output.push_back(matrix[i][j]);
   }
   i -= 1;
   j -= 1;
   for(; j >= 0; -- j) {
      output.push_back(matrix[i][j]);
   }
   j += 1;
   i -= 1;
   for(; i > 0; -- i) {
      output.push_back(matrix[i][j]);
   }
   i += 1;
   j += 1;
   for(; j < col - 1; ++ j) {
      output.push_back(matrix[i][j]);
   }
   return output;
}
*/

// vector<int> spiralOrder(vector<vector<int>> & matrix) {
//    vector<int> output;
//
//    for(int i = 0; i < (int)matrix.size(); ++ i) print(matrix[i]);
//    int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
//
//    int i;
//
//    while(top <= bottom) {
//       for(i = left; i <= right; ++ i) {
//          output.push_back(matrix[top][i]);
//          // if(top == bottom) break;
//       }
//       top +=1;
//       for(i = top; i <= bottom; ++i) output.push_back(matrix[i][right]);
//
//       right -= 1;
//       for(i = right; i >= left; -- i) { output.push_back(matrix[bottom][i]);
//          if(top == bottom) return output;}
//
//       bottom -= 1;
//       for(i = bottom; i >= top; -- i) output.push_back(matrix[i][left]);
//       left += 1;
//    }
//    cout << "top: " << top << " bottom: " << bottom << " left: " << left << " right: " << right << endl;
//    return output;
// }

vector<int> spiralOrder(vector<vector<int>> & matrix) {
   vector<int> output;

   for(int i = 0; i < (int)matrix.size(); ++ i) print(matrix[i]);
   int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;

   int i;
   while(top <= bottom && left <= right){
      for(i = left; i <= right; ++ i) output.push_back(matrix[top][i]);

      for(i = top + 1; i <= bottom; ++ i) output.push_back(matrix[i][right]);

      for(i = right - 1; i >= left && top != bottom; -- i) output.push_back(matrix[bottom][i]);

      for(i = bottom - 1; i >= top + 1 && left != right; -- i) output.push_back(matrix[i][left]);

      top += 1;
      right -= 1;
      bottom -= 1;
      left += 1;
   }
   cout << "left: " << left << " right: " << right << " top: " << top << " bottom: " << bottom << endl;

   return output;
}

int main(void) {

  // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix = {{1, 2, 3, 4, 5, 6}, {11, 12, 13, 14, 15, 16}, {21, 22, 23, 24, 25, 26}};
   // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
   // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
   vector<int> output = spiralOrder(matrix);

   
   cout << endl << "output:\n";
   print(output);

   return 0;
}
