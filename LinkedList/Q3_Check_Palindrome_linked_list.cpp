//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
   
    bool isPalindrome(Node *head) {
        // 1. Find the middle of linked list
        
        
         if(head->next == NULL)
            return true ;
            
         Node *fast = head;
         Node *slow = head ;
         while(fast != nullptr && fast->next != nullptr)
         {
             fast = fast->next->next;
             slow = slow->next;
         }
         
         //2. reverse the linked list from middle to end
            Node* prev = slow ;
            Node* cur = slow->next;
            slow->next = nullptr;
            
            while(cur!=NULL)
            {
                Node *nextPtr = cur->next ;
                cur->next = prev ;
                
                prev = cur ;
                cur = nextPtr ;
            }
            Node* head2 = prev ;
           
          //3. compare the linked list element from start to end to check palindrome
            while(head != NULL && head2 != NULL)
            {
                if(head->data != head2->data)
                return false ;
                
                head = head->next ;
                head2 = head2->next;
            }
         return true ;
    }
};


void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
       
        vector<int> arr ;
        arr = {1,2,9,8,9,2,1};
        struct Node *head = new Node(arr[0]);

        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    
    return 0;
}
