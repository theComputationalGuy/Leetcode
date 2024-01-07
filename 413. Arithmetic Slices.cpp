#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);

        for(int i=2;i<nums.size();i++){
            int n1 = nums[i-1];
            int n2 = nums[i-2];
            if(n1-n2 == nums[i]-n1){
                dp[i] = dp[i-1] + 1;
            }
        }
        int solution = 0;
        for(int i=0;i<nums.size();i++){
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
