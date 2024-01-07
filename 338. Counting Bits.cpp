#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector <int> ans(n+1);
    ans[0] = 0;
    int power = 1;
    int count = 1;
    for(int i=1;i<=n;i++){
        if(i == power){
            count = 1;
            ans[i] = count;
            power *= 2;
        }
        else{
            ans[i] = 1 + ans[i - power/2];
        }
    }
    for(int i: ans){
        std::cout<<i<<" ";
    }
    return 0;
}