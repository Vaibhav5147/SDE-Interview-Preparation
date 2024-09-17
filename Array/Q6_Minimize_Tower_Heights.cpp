
#include <bits/stdc++.h>
using namespace std;
/*
Minimize the heights
Given an array arr[] denoting heights of N towers and a positive integer K.
For each tower, you must perform exactly one of the following operations exactly once.
Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.
*/
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {

        /*
            1. first sort the elements
            2. possible ans exist between smallest and tallest tower heights without modification , ans = arr[n-1] - arr[0]
            3. Try to minimize the height difference using +k and -k modification 
                a. One posible way to reduce tower height less then first tower height (arr[0]+k){ it is max possible height of first tower} using -k for all other tower.
                b. Other posible way to get maximize height of other tower as compare to last tower(arr[n-1]-k){minimum  posible height of tower} using +k for all tower .
            Time complexity : O(N)    
        */
        int curMax  , curMin , minDiff  ;
        
        sort(arr.begin(),arr.end());
        int n = arr.size();
        minDiff = arr[n-1]-arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>=k)
            {
                curMax = max(arr[i-1]+k,arr[n-1]-k);
                curMin = min(arr[0]+k,arr[i]-k) ;
                minDiff = min(minDiff,curMax-curMin);
            }
           
        }
        return minDiff ;
    }
};


int main() {
 
     vector<int> a;
     int k ;
     Solution ob;
     a = {1, 5, 8, 10} ;
     k = 2;
     int ans = ob.getMinDiff(a, k);
     cout << ans << "\n";
     
     a.clear() ;
     a = {3, 9, 12, 16, 20};
     k =3 ;
     ans = ob.getMinDiff(a, k);
     cout << ans << "\n";
     
}
