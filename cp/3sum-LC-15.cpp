#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//                                                    LEETCODE: 15

void print(vector<int>&nums){
   for(int x : nums) cout << x << "\t";
   cout << endl;
}

int main(void) {

   vector<int> nums = {-1,0,1,2,-1,-4};
   vector<vector<int>> answer;
   int n = nums.size();

   sort(nums.begin(), nums.end());

   for(int i = 0; i < n; ++ i) {
      for(int j = i + 1; j < n; ++ j) {
         for(int k = j + 1; k < n; ++ k) {
            if(nums[i] + nums[j] + nums[k] == 0) answer.push_back({nums[i], nums[j], nums[k]});
         }
      }
   }

   for(int i = 0; i < (int)answer.size(); ++ i) {
      print(answer[i]);
   }

  cout << "nums: "; print(nums);

   return 0;
}
