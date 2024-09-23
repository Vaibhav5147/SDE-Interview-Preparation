#include<bits/stdc++.h>
using namespace std ;

/*
  Inversion count in array
  Given an integer array arr[] of size n, the task is to find the count inversions of the given array. Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.
  Inversion Count for an array indicates that how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 
*/


class Solution{

     public :
          /*
               Approach 1: Traverse arr using two loop and count inversion based on condition arr[i]>arr[j] where i<j 
               Time complexity : O(N*N) 
               Space complexity : O(1)
          */
          int naiveApproach(vector<int> arr)
          {
               int invCount = 0;
               for(int i=0;i<arr.size()-1;i++)
               {
                    for(int j=i+1;j<arr.size();j++)
                    {
                         if(arr[i]>arr[j])
                              invCount++;
                    }
               }

               return invCount ;
          }
           /*
               Approach 2 : Using Set  , when we insert element in set it will sort the elements
                              1) Create an empty Set in C++ STL (Set in C++ STL is implemented using Self-Balancing Binary Search Tree). 
                              2) Insert first element of array into the set. 
                              3) Initialize inversion count as 0.
                              4) Iterate from 1 to n-1 and do following for every element in arr[i]
                                   a) Insert arr[i] into the set.
                                   b) Find the first element greater than arr[i] in set using upper_bound() defined Set STL.
                                   c) Find distance of above found element from last element in set and add this distance to inversion count.
                              4) Return inversion count.
               Time complexity : O(Nlog(N)) ---> logN for element insertions
               Space complexity : O(N)            
           */
          int usingSet(vector<int> arr)
          {
               
               multiset<int> st ;
               st.insert(arr[0]) ;
               int invCount = 0;
               multiset<int>::iterator itr;
               for(int i=1;i<arr.size();i++)
               {
                    st.insert(arr[i]) ;
                    itr = st.upper_bound(arr[i]);
                    invCount += distance(itr,st.end());
               }
               return invCount ;
          }

};

int main()
{
     vector<int> arr ;
     Solution obj ;
     arr = {1,2,3,4,5};
     cout<<"Using Naive Approach : "<<obj.naiveApproach(arr)<<endl;
     cout<<"Using Set Approach : "<<obj.usingSet(arr)<<endl;
     arr.clear();
     arr = {7, 2, 6, 3} ;
     cout<<"Using Naive Approach : "<<obj.naiveApproach(arr)<<endl;
     cout<<"Using Set Approach : "<<obj.usingSet(arr)<<endl;
     arr.clear();
     arr = {8,4,2,1} ;
     cout<<"Using Naive Approach : "<<obj.naiveApproach(arr)<<endl;
     cout<<"Using Set Approach : "<<obj.usingSet(arr)<<endl;

}