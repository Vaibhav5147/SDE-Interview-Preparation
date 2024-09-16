#include <bits/stdc++.h>
using namespace std;

/*
     for problem refer 
     1. Minimum jumps , gfg
     Similar problems
     2. Jump game 1 , leetcode
     3. Jump game 2 ,leetcode

     Time complexity : O(N)
     Problem can be solve using dynamic programing with O(N^2) time complexity .
*/
class Solution {
  public:
    int minJumps(vector<int>& arr) {
       
        int dst = arr.size();
        int maxIndx = 0;
        //if there is no possible way to reach end of arr
        for(int i=0;i<dst;i++)
        {
            if(maxIndx<i)
                return -1 ;
           maxIndx = max(maxIndx,i+arr[i]) ;       
        }
        
        // find minimum jumps required to reach the end of arr
        int r = 0,l =0,minJump = 0;
        
        while(r<dst-1)
        {
            maxIndx = INT_MIN ;
            for(int i=l;i<=r;i++)
                maxIndx = max(maxIndx,i+arr[i]) ;
            l = r+1;
            minJump++;
            r = maxIndx ;
        }
        
        return minJump ;
    }
};




int main() {
   
 
     int n, i, j;
     vector<int> arr;
     Solution obj;
     //Testcase 1
     //{1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
     arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} ;
     cout << obj.minJumps(arr) << endl;
     //Testcase 2
     //{1, 4, 3, 2, 6, 7}
     arr.clear() ;
     arr = {1, 4, 3, 2, 6, 7} ;
     cout << obj.minJumps(arr) << endl;
     //Testcase 3
     //[3,2,1,0,4]
     arr.clear() ;
     arr = {3,2,1,0,4} ;
     cout << obj.minJumps(arr) << endl;
     //Testcase 4
     //{0, 10, 20}
     arr.clear() ;
     arr = {0, 10, 20} ;
     cout << obj.minJumps(arr) << endl;
    return 0;
}

// } Driver Code Ends