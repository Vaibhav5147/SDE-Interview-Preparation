#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    /*
     Evaluate LPS array
    */
    int lps(string str) {
        int n = str.length();
        int lps[n] ;
        int len = 0,i=1;
        lps[0] = 0;
        while(i<n)
        {
            if(str[i] == str[len])
            {
                len++;
              
                lps[i] = len ;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    len = lps[len-1] ;
                }
            }
        }
        return lps[n-1] ;
    }
};



int main() {


        Solution ob;
        string str = "aaaa";
        cout << ob.lps(str) << "\n";
}

