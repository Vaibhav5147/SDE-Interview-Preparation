
#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  /*
   Approach 1 : Using replace and n natural sum of number equation.
  */
    vector<int> findTwoElement(vector<int>& arr) {
        
        long long int n = arr.size();
        long long int sum = n*(n+1)/2;
        long long int repeted ;
        vector<int > ans ;
        for(long long int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]>0)
            {
               
                arr[abs(arr[i])-1] = -arr[abs(arr[i])-1] ;
                 sum = sum - abs(arr[i]);
            }
            else
            {
                repeted = abs(arr[i]) ;
            }        
        }
        ans = {repeted,sum};
        return ans ;
    }
};



int main() {
  
        vector<int> a;
        a = {1,2,4,4,5};
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    
    return 0;
}
