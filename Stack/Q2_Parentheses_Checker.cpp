#include<bits/stdc++.h>
using namespace std;
/*
     Parenthese checker
     Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
     For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
*/
class Solution
{  
     private:
     bool isMatch(char c1, char c2)
     {
        if (c1 == '(' && c2 == ')') return true;
        if (c1 == '[' && c2 == ']') return true;
        if (c1 == '{' && c2 == '}') return true;
            return false;
     }

    public:
    
    /*
    Approach : 1 using stack
    Time complexity : O(N)
     Space complexity : O(N)
    */
    bool isValidUsingStack(string x)
    {
    int n = x.size();
    if(n==1)
        return false;
    stack<char> st;
    for(char ch: x)
    {
        switch(ch)
        {
            case '(':
                    st.push(ch);
                     break;
            case '[':
                    st.push(ch);
                    break;
            case '{': 
                    st.push(ch);
                    break;
            case ')': 
                    if(st.empty() || st.top() != '(')
                    return false;
                    else st.pop();
                    break;
            case ']': 
                    if(st.empty() || st.top() != '[')
                        return false; 
                    else st.pop(); 
                    break;
            case '}': if(st.empty() || st.top() != '{') 
                return false;
                    else st.pop();
                    break;
            default:;
         }
    }
     return st.empty();
    }
    /*
     Approach : 2 , using same string as stack , 
     Time complexity : O(N)
     Space complexity : O(1)
    */
    bool isValid(string x)
    {
        // Your code here
        int n = x.size();
        int top = -1;
        for(int i=0;i<n;i++)
        {
            if(top < 0  || !isMatch(x[top],x[i]))
            {
                top++;
                x[top] = x[i];
            }
            else
                top--;
        }
        
        return top == -1;
        
    }
    
    

};



int main()
{
  
     string a;
     a ="{{()(){[[]]}}}";
     cin>>a;
     Solution obj;
     if(obj.isValid(a))
     cout<<"balanced"<<endl;
     else
     cout<<"not balanced"<<endl;
   
}
