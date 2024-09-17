#include <bits/stdc++.h>
using namespace std;

/*   
     Minimum Platforms
     Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
     Consider that all the trains arrive on the same day and leave on the same day. 
     Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. 
     At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
*/

class Solution {
  public:
   /* Approach : 1
      Time complexity : O(N)
      Space complexity : O(N)
    */
   int findPlatformUsingExtraSpace(vector<int>& arrivalTime, vector<int>& departureTime)
   {
      // 1 for arrival
      // 2 for departure

      vector<pair<int,int>> combineData ;
      int n = arrivalTime.size() ;
      for(int i=0;i<n;i++)
      {
          combineData.push_back({arrivalTime[i],1});
          combineData.push_back({departureTime[i],2});
      }
      sort(combineData.begin(),combineData.end());
      int maxPlatform = 0, platformcount = 0;
      for(auto x : combineData)
      {
          if(x.second == 1)
               platformcount++;
          else
               platformcount--;
          maxPlatform = max(maxPlatform,platformcount)   ;  
      }

      return maxPlatform ;
   }
    /*
      Approach : 2
      Time complexity : O(N)
      Space complexity : O(1)
    */
    int findPlatform(vector<int>& arrivalTime, vector<int>& departureTime) {
        
        int n = arrivalTime.size() ;
        sort(arrivalTime.begin(),arrivalTime.end());
        sort(departureTime.begin(),departureTime.end());

        int i = 0,j=0,cnt=0,platform = 0;
        while(i<n && j<n)
        {
          if(arrivalTime[i]<=departureTime[j])
          {
               cnt++;
               i++;
          }
          else
          {
               cnt--;
               j++;
          }
          platform = max(platform,cnt);
        }
         return platform;
    }
};


int main() {
      
     vector<int> arr;
     vector<int> dep;
     arr = {900, 940, 950, 1100, 1500, 1800};
     dep = {910, 1200, 1120, 1130, 1900, 2000};
     Solution ob;
     cout << ob.findPlatform(arr, dep) << endl;  
     cout << ob.findPlatformUsingExtraSpace(arr, dep) << endl;  
}
