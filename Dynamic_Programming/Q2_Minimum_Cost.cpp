#include <bits/stdc++.h>
using namespace std;


/*
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, 
where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. 
Find the minimum possible total cost incurred before the Geek reaches the last stone.
Greedy solution will not work
Approach 1: Using dynamic programming
*/
class Solution {
  public:
int minCost(vector<int> &arr,vector<int> &dp ,int i,int k,int n)
    {
        if(i>=n)
            return INT_MAX ;
        if(i==n-1)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
            
        int ans = INT_MAX ;
        for(int steps =i+1;steps<= min(i+k,n-1) ;steps++)
        {
            ans = min(ans, (abs(arr[i]-arr[steps])+ minCost(arr,dp,steps,k,n))); 
        }
        return dp[i] = ans;
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = minCost(arr,dp,0,k,n);
        return ans ;
    }
};



int main() {
   
        int k = 2;
        vector<int> arr;


        arr = {35, 1 ,70 ,25 ,79 ,59, 63, 65};

        //Ans Dp: 62
        //Ans greedy : 98
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;

}
