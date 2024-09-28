#include<iostream>
#include<thread>
#include<mutex>
using namespace std ;

#define TIME 1000
unsigned int firstData = 0;
unsigned int secondData = 0;
std::recursive_mutex data_lock ;
void updateSecondData();

/*
 
   recursive mutex to avoid deadlock situation.

*/

void updateFirstData()
{
	data_lock.lock();
	firstData++;
	updateSecondData(); //Recursive mutex
	data_lock.unlock();
}

void updateSecondData()
{
	data_lock.lock();
	secondData++;
	data_lock.unlock();
}

void startUpdate()
{
	for(int i=0;i<TIME;i++)
	{
	  updateFirstData();
	  updateSecondData();
	}
}

int main()
{
	std::thread one(startUpdate) ;
	std::thread two(startUpdate);

	one.join();
	two.join();
	cout<<"First data : "<<firstData<<endl;
	cout<<"Second data : "<<secondData<<endl;
}
