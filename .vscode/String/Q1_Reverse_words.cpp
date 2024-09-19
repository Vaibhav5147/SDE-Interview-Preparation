
#include <bits/stdc++.h>
using namespace std;

/*
 Reverse Words
 Given a String str, reverse the string without reversing its individual words. Words are separated by dots.
*/
class Solution {
  public:
    /*
     Approach : 1
          a. reverse individual string .
          b. reverse combined string.
     Time complexity : O(N)     
    */
    string reverseWords(string str) {
    string word ="" ;
    string combineStr ="" ;
    
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!='.')
        {
            word = str[i]+word;
        }
        else
        {
            combineStr += word + ".";
            word = "";
            
        }
    }
     combineStr += word;
     reverse(combineStr.begin(),combineStr.end());
    return combineStr ;
    }
};


int main() {

        string str = "i.like.coding.very.much"; 
        Solution obj;
        cout << obj.reverseWords(str) << endl;
    
}
