#include <bits/stdc++.h>
using namespace std;
/*
Given an array arr. Find the majority element in the array. If no majority exists, return -1.
a majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.
*/
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int cnt = 0;
        int ele ;
        for(auto x: arr)
        {
            if(cnt==0)
            {
                ele = x ;
                cnt++;
            }
            else if(ele == x)
            cnt++;
            else
            cnt--;
        }
        
        cnt = 0;
        for(auto x:arr)
        {
            if(x == ele)
            cnt++;
        }
        
        if(cnt > arr.size()/2)
            return ele ;
        else
            return -1 ;
    }
};



int main() {

     vector<int> a ;
     Solution obj;
     //TestCase 1 
     a = {2,2,1,1,1,2,2};
     cout << obj.majorityElement(a) << endl;
    //TestCase 2
     a.clear() ;
     a = {3, 1, 3, 3, 2} ;
     cout << obj.majorityElement(a) << endl;

    return 0;
}

