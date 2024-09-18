#include<bits/stdc++.h>
using namespace std;
/*
     Parenthese checker
     Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
     For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).
*/
class Solution
{
    public:
    
    bool isValid(string x)
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
