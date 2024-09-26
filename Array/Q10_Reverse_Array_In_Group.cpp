#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr of positive integers. Reverse every sub-array group of size k.
Note: If at any instance, k is greater or equal to the array size, then reverse the entire array. 
You shouldn't return any array, modify the given array in place.
*/

class Solution {
  public:
    void reverseInGroups(vector<long long int> &arr, int k) {
        int n = arr.size() ;
        if(n!=1 && k!=1)
        {
            int i = 0 ;
           
            
            while(i<n)
            {   
                int left = i;
                int right = i+k-1  ;
                if(right >=n)
                    right = n-1 ;
               while(left<right)
               {
                   swap(arr[left],arr[right]);
                   left++ ;
                   right--;
               }
               i = i+k;
            }
        }
            
    }
};




int main() {

        vector<long long int> arr;
        arr = {1,2,3,4,5};
         int k = 3 ;
        Solution ob;
        ob.reverseInGroups(arr, k);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        //ans : 3,2,1,5,4
  
}

