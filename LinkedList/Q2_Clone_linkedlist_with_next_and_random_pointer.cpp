#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};


class Solution {
  public:
   /*
     Approach 1 : copy list using map
               a. create copy of nodes
               b. link copy of  nodes .
     Time complexity : O(N)
     Space complexity : O(N)
   */
    Node *copyListUsingMap(Node *head) {
        Node *temp = head;
        unordered_map<Node*,Node*> mp;
        while(!temp)
        {
            mp[temp] = temp;
            temp = temp->next;
        }
        
        temp = head ;
        while(!temp)
        {
            mp[temp]->next = temp->next;
            if(!temp->random)
            mp[temp]->random = temp->random;
            temp = temp->next;
        }
        return mp[head];
    }

    /*
     Approach 2: Inserting copy nodes between already existing linked list
          a. Insert new nodes between existing nodes ;
          b . link random pointers 
          c . link next pointers
           Time complexity : O(N)
           Space complexity : O(N)
    */
     //Insert temp nodes
   void insertNodes(Node *node)
   {
       Node* temp = node ;
       while(!temp)
       {
           Node *newNode = new Node(temp->data);
           newNode->next = temp->next ;
           temp = temp->next->next;
       }
   }
   //connect random nodes
   void connectRandom(Node* node)
   {
       Node* temp = node;
       while(!temp)
       {   
           if(!temp->random)
           {
             temp->next->random = temp->random;
           }
           else
            temp->next->random  = nullptr;
            temp = temp->next->next;
       }
   }
   //restore orignal list
    Node *restoreList(Node *head)
    {
        Node *dummyNode = new Node(-1);
        Node *res = dummyNode ;
        Node *temp = head ;
        
        while(!temp)
        {
            res->next = temp->next->next;
            temp->next = temp->next->next;
            
            res = res->next ;
            temp = temp->next ;
            
        }
        
        return dummyNode->next;
    }

    Node *copyList(Node *head) {
        insertNodes(head);
        connectRandom(head);
        return restoreList(head);
    }
};


int main() {
    
}

