#include<bits/stdc++.h>
using namespace std;
/*
 Question : https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
*/
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
       
        vector<int> mp(26,0);
        int required = p.size();
        //Find all occurence of char in patern string
        for(auto  ch:p)
            mp[ch-'a']++ ;
        int left = 0,right = 0,minLen = INT_MAX,minStart=0;
        while(right<s.size())
        {  
            
            if(mp[s[right]-'a']>0) 
            {   
                //char mathed with patern string string 
                //reduce the count of required chars
                required--;
            }
             //reduce the count of used chars
             mp[s[right]-'a']--;
             //Increment the size of window
             right++;
             
             //when all elements are matched
             //shrink the window size
             while(required==0)
             {
                 if(right-left<minLen)
                 {  //update starting index and min length of window
                     minStart = left;
                     minLen = right-left;
                 }
                 
                 //Increase the unused char count in map 
                 mp[s[left]-'a']++;
                 
                 if(mp[s[left]-'a']>0)
                  {  // un-used char belongs to patern which voilates the required number 
                     //It means all the repeted char are exahusted in window which required to match with patern
                      required++;
                  }
                //shrink window  
                left++;    
             }
        }
         return minLen == INT_MAX ? "-1" : s.substr(minStart, minLen);
    }
};


int main()
 {
     string s;
     string pat;
     s = "timetopractice";
     pat = "toc";
     Solution obj;
     cout<<obj.smallestWindow(s, pat)<<endl;
}
