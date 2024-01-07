#include <bits/stdc++.h>
using namespace std;

int main(){
    int numRows;
    cin>>numRows;
    vector<vector<int>> ans;
    for(int i = 0; i < numRows; i++){
        vector<int> v(i+1);
        for(int j=0; j <= i; j++){
            if(j==0 || j==i){
                v[j] = 1;
            }
            else{
                v[j] = ans[i-1][j-1] + ans[i-1][j];
            }
        } 
        ans[i] = v;
    }
    for(vector<int> x: ans){
        for(int y: x){
            std::cout<<y<<" ";
        }
        std::cout<<endl;
    }
}