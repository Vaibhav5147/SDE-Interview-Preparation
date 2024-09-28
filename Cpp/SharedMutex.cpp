#include<iostream>
#include<thread>
#include<mutex>
#include<shared_mutex>
#include<chrono>
using namespace std ;

char weekDay[7][4] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
int today = 0;
std::shared_mutex data_lock;

void read_cal(const int pId) 
{
	for(int i =0;i<7;i++)
	{
	 data_lock.lock_shared();
	 cout<<"Person Id : "<<pId<<" Day :"<<weekDay[today]<<endl;
	 std::this_thread::sleep_for(std::chrono::milliseconds(100));
	 data_lock.unlock_shared();
	}
}

void write_cal(const int pId)
{
  for(int i=0;i<7;i++)
  {
   data_lock.lock();
   today = (today+1)%7;
   cout<<"Person Id : "<<pId<<" updated calender"<<" On day : "<<weekDay[today]<<endl;
   data_lock.unlock();
  }
}

int main()
{
  std::array<std::thread,10> reader;
  for(int i=0;i<10;i++)
  {
    reader[i] = std::thread(read_cal,i);
  }

  std::array<std::thread,3> writers;
  for(int i=0;i<3;i++)
  {
    writers[i] = std::thread(write_cal,i);
  }

  for(int i=0;i<10;i++)
  {
   reader[i].join();
  }

  for(int i=0;i<3;i++)
  {
   writers[i].join();
  }
}
