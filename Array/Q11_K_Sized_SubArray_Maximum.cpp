#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    /*
      Approach 1: Using Max-Heap (n Log n) Time and O(N) Space
    */
    vector<int> max_of_subarrays_pq(int k, vector<int> &arr) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans ;
        for(int i=0;i<k;i++)
            pq.push({arr[i],i}) ;
        ans.push_back(pq.top().first);
        
        for(int i=k;i<arr.size();i++)
        {
            pq.push({arr[i],i});
            
            while(pq.top().second <= i-k)
                pq.pop();
            ans.push_back(pq.top().first) ;        
        }
        return ans;
            
    }
    /*
     Approach 2: Using Set O(n Log n) Time and O(k) Space
    */
     vector<int> max_of_subarrays_set(int k, vector<int> &arr) {
          set<pair<int,int>,greater<pair<int,int>>> st;
          vector<int> ans ;
          for(int i=0;i<k;i++)
               st.insert({arr[i],i});
          ans.push_back(st.begin()->first); 

          for(int i=0;i<arr.size();i++)
          {
               st.insert({arr[i],i});
               st.erase({arr[i-k],i-k});
               ans.push_back(st.begin()->first);
          } 

          return ans ;   
     }
     /*
      Approach 3: Using Deque O(n) Time and O(k) Space
      Idea is to maintain number in decreasing order in deque
     */
    vector<int> max_of_subarrays_deque(int k, vector<int> &arr) {
        deque<int> dq(k) ;
        vector<int> ans ;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);        
        }
        ans.push_back(arr[dq.front()]) ;
        
        for(int i=k;i<arr.size();i++)
        {
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front() ;
            while(!dq.empty() && arr[i]>=arr[dq.back()])
                dq.pop_back(); 
             dq.push_back(i);        
              ans.push_back(arr[dq.front()]) ;
        }
        return ans;
    }
};



int main() {

        vector<int> arr;
        arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
        int k = 3 ;
        Solution obj;
        vector<int> res = obj.max_of_subarrays_pq(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
  
}

