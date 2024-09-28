#include<iostream>
#include<thread>
#include<atomic>
using namespace std;
#define TIME 1000000000
std::atomic<unsigned int> data(0);



void updateData()
{
 
  for(int i=0;i<TIME;i++)
  {
    data.fetch_add(1);
  }
  
}

int main()
{
 std::thread one(updateData);
 std::thread two(updateData);
 one.join();
 two.join();
 cout<<"Expected value : "<<2*TIME<<endl;
 cout<<"Current value : "<<data.load()<<endl;
}
