#include <iostream>
#include <vector>
using namespace std;

//                                                    LEETCODE #238

// // Time Complexity: O(n2) Space: O(n)
// vector<int> productExceptSelf(vector<int>& nums) {
//    vector<int> answer;
//    answer.reserve(n);
//
//    int prod = 1;
//    for(int i = 0; i < (int)n; ++ i){
//       for(int j = 0; j < (int)n; ++ j){
//           if(j == i) continue;
//           prod *= nums[j];
//       }
//       answer.push_back(prod);
//       prod = 1;
//    }
//    return answer;
// }
//
void print(vector<int>&nums) {
   for(int x : nums) cout << x << "\t";
   cout << endl;
}

// Time: O(n) Space: O(n)
// vector<int> productExceptSelf(vector<int>&nums){
//
//    int n = (int)nums.size();
//    vector<int> answer(n, 1), pref_prod(n, 1), suff_prod(n, 1);
//
//    int pre_prod = 1, post_prod = 1;
//    for(int i = 1; i < n; ++ i) {
//       pre_prod *= nums[i - 1];
//       pref_prod[i] = pre_prod;
//    }
//
//    for(int i = n - 1; i > 0; -- i) {
//       post_prod *= nums[i];
//       suff_prod[i - 1] = post_prod;
//    }
//
//    for(int i = 0; i < n; ++ i) {
//       answer[i] = pref_prod[i] * suff_prod[i];
//    }
//
//    return answer;
// }

// Time: O(n) Space: O(1)
vector<int> productExceptSelf(vector<int> &nums){
   int n = nums.size();
   vector<int> answer(n, 0);

   int prod = 1, zeros = 0, idx = -1;
   for(int i = 0; i < n; ++ i) {
      if(nums[i] == 0){
         zeros ++; idx = i;
      } else prod *= nums[i];
   }

   cout << prod << endl;

   if(zeros == 0) {
      int x = 0;
      for(int i : nums) {
         answer[x] = prod / i;
         x ++;
      }
   } else if(zeros == 1) answer[idx] = prod;

   return answer;
}

int main(void) {

   // vector<int> nums = {1, 2, 3, 4}; // 24, 12, 8, 6
   vector<int> nums = {-1, 1, 0, -3, 3}; // 0, 0, 9, 0, 0
   vector<int> answer = productExceptSelf(nums);
   cout << "_nums_: "; print(nums);
   cout << "answer: "; print(answer);

   return 0;
}
