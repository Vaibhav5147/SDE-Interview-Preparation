#include<bits/stdc++.h>
using namespace std;


/*
implement the function strstr. The function takes two strings as arguments (s,x) and  locates the occurrence of the string x in the string s. 
The function returns an integer denoting the first occurrence of the string x in s (0 based indexing).
*/

//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    
     int n = s.length() ;
     int m = x.length() ;
     for(int i = 0;i<= n-m;i++)
     {
         if(s[i] == x[0])
         {
             int j =0;
             for(j = 0;j<m;j++)
             {   
                 if(s[i+j] != x[j])
                   break ;
             }
          
             if(j == m)
               return i ;
               
         }
     }
     return -1 ;
}

int main()
{
  
string a;
string b;
a = "abcabcabcd";
b = "abcd";
cout<<strstr(a,b)<<endl;
}





