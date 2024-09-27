#include<iostream>
#include<thread>
using namespace std;
#define TIME 1000000000

unsigned int data = 0;
void updateData()
{
  for(int i=0;i<TIME;i++)
  {
    data++;
  }
}


int main()
{
 /*
  Two threads {one, two} will access same data and during updation they will create race condition.
 */	
 std::thread one(updateData);
 std::thread two(updateData);
 one.join();
 two.join();
 cout<<"Expected Value : "<<2*TIME<<endl;
 cout<<"Final Value of data : "<<data<<endl;
	
}	
