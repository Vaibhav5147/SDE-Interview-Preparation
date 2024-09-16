#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*
    Approach :1 Use stack 
    -------------------------------------------------------------------------------------------
     1. Push -1 into stack to handel base case : eg "()"
     2. If encounter opening bracket "(" , push index  into stack .
     3. If encounter closing bracket ")" , pop index from stack , check following cases
          a. If stack becomes empty , push index of current bracket 
          b .If stack is not empty , then update maxlength of substring till now .
     Time complexity : O(N) , N-> length of string
     Space complexity : O(N)   
     ------------------------------------------------------------------------------------------            
    */
    int maxLengthUsingStack(string& str) 
    {
       stack<int> st ;
       st.push(-1) ;
        
        int maxLen = 0;
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
                st.push(i) ;
            else
            {  
                st.pop() ;
                if(st.empty())
                    st.push(i) ;
                else
                maxLen = max(maxLen,i-st.top()) ;
            }
        }
        return maxLen ;
    }

    /*
    Approach :2 Use two counter , open and close 
    -------------------------------------------------------------------------------------------
    1.Treaverse left to right of string 
          a.Increment  open counter for "(" and close counter for ")" for close.
          b. In case of open==close , update ans  = max(ans,2*open)
          c. In case of close>open , set counter open = 0 ,close = 0 .
     This case will find rightmost longest valid substring end with ")" .
    2. Traverse for right to left of string
          a. repeat steps a and b from above .
          b In case of open>close , set counter open = 0 , close = 0.
     This case will find leftmost valid string start with "(".    
     Time complexity : O(N) , N-> length of string
     Space complexity : O(1)         
    -------------------------------------------------------------------------------------------
    */

    int maxLengthUsingCounter(string &str)
    {
      int open=0,close = 0,maxLen = 0;
      for(int i = 0;i<str.length();i++)
      {
          if(str[i] == '(')
               open++;
          if(str[i] == ')')
               close++;

          if(open==close)
               maxLen = max(maxLen,2*open);
          if(close>open)
               open = close = 0;                         
      }
      open = close = 0;

      for(int i=str.length()-1;i>=0;i--)
      {
          if(str[i] == '(')
               open++;
          if(str[i] == ')')
               close++;

          if(open==close)
               maxLen = max(maxLen,2*open);

           if(close<open)
               open = close = 0;          
      }
      
      return maxLen ;
    }

};



int main() {
   
     string str;
     Solution obj;
     str = "(((())))" ;
     cout << obj.maxLengthUsingStack(str) << "\n";
     cout << obj.maxLengthUsingCounter(str) << "\n";
     str = ")()())" ;
     cout << obj.maxLengthUsingStack(str) << "\n";
     cout << obj.maxLengthUsingCounter(str) << "\n";
     return 0;
}
