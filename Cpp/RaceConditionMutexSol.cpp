#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
#define TIME 1000000000
unsigned int data = 0;
std::mutex data_lock ;


void updateData()
{
  data_lock.lock();
  for(int i=0;i<TIME;i++)
  {
    data++;
  }
  data_lock.unlock(); 
}

int main()
{
 std::thread one(updateData);
 std::thread two(updateData);
 one.join();
 two.join();
 cout<<"Expected value : "<<2*TIME<<endl;
 cout<<"Current value : "<<data<<endl;
}
