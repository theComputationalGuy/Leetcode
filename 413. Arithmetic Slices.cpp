#include<bits/stdc++.h>
using namespace std;

// imp test cases: [1,2,3,4,5] -> 6
// [1,2,3,8,9,10] -> 2

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for(int i=2;i<nums.size();i++){
            int n1 = nums[i-1]; // start from i=2 as first 2 elements will not contribute in creating new slice
            int n2 = nums[i-2];
            if(n1-n2 == nums[i]-n1){
                // IDEA : dp[i] stores no. of new slices added by element "nums[i]" REMEMBER new slices
                // if nums[i-1] has n slices then nums[i] will add dp[i-1] + 1 slices as it will extend all previous slices by length 1 & itself add new slice of nums[i-2]<->nums[i-1]<->nums[i]
                // this if statement checks if this element "nums[i]" will or will not add new slice
                // if it will not add new slice it will not extend any previous slice either so it contributes 0 new slices
                dp[i] = dp[i-1] + 1;
            }
        }
        int solution = 0;
        for(int i=0;i<nums.size();i++){
            // since each dp[i] is new slices added, we add all dp[i] to get total slices
            solution += dp[i];
        }

        return solution;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    int input;
    while(cin>>input){
        nums.push_back(input);
    }
    cout<<s.numberOfArithmeticSlices(nums)<<endl;
}
