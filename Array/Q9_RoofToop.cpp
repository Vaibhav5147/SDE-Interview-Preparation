#include <bits/stdc++.h>
using namespace std;
/*
Roof Top : https://www.geeksforgeeks.org/problems/roof-top-1587115621/1
You are given the heights of consecutive buildings. 
You can move from the roof of a building to the roof of the next adjacent building. 
You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.
1, 2, or 2, 3 are the only consecutive buildings with increasing heights thus maximum number of consecutive steps with an increase in gain in altitude would be 1 in both cases.
*/
class Solution {
  public:
    int maxStep(vector<int>& arr) {
        int ans = INT_MIN;
        int maxStep=0 ;
        int i = 0,j=1;
        while(i<arr.size() && j<arr.size())
        {
            if(arr[i]<arr[j])
            {
                j++;
                i++;
                maxStep++;
                ans = max(maxStep,ans);
            }
            else
            {
                maxStep=0;
                i++;
                j++;
            }
        }
        return ans ;
        
    }
};



int main() {
   
        vector<int> arr;
        arr ={1, 2, 2, 3, 2};
        Solution ob;
        cout << ob.maxStep(arr) << endl;
}
