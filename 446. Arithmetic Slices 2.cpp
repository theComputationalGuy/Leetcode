#include<bits/stdc++.h>
using namespace std;

// imp test cases: [1,2,3,4,5] -> 6
// [1,2,3,8,9,10] -> 2

class Solution {
public:

    int numberOfArithmeticSlices(vector<int>& nums) {

        int n= nums.size();
        vector<unordered_map<int,int>> dp(nums.size());
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int length = nums[i]-nums[j];
                dp[i][length] += dp[j][length] + 1;
            }
        }

        vector<int> seqSum(nums.size(), 0);
        for(int i=0;i<nums.size();i++){
            for(auto it: dp[i]){
                seqSum[i] += it.second;
            }
        }

        int solution = 0;
        for(int i=0;i<nums.size();i++){
            solution += seqSum[i];
        }

        return solution - (n*(n-1))/2;
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
