#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

unsigned int itemsOnList = 0;
std::mutex pen ;


void updateList(string personName)
{
	int itemToAdd = false;
	while(itemsOnList<=10)
	{
	  if(itemToAdd && pen.try_lock())
	  { 
	    //Use pen to update list on paper
            //pen.lock();
	    itemsOnList++;
	    cout<<personName<<" : Added item in list "<<endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(300));//Time spent to update list
	    itemToAdd = false;
	    pen.unlock();
	    
	  }
	  else
	  {
	    //Search Item  to add in list 
            std::this_thread::sleep_for(std::chrono::milliseconds(100)); //Time spent for seaching 		  
	    itemToAdd = true;
	    cout<<"Some Items found by :  "<<personName<<endl;
	  }
	}

}

int main()
{
	auto start_time = std::chrono::high_resolution_clock::now();
	std::thread one(updateList,"Brother");
	std::thread two(updateList,"Sister");
	one.join();
	two.join();
        
	auto end_time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<chrono::microseconds>(end_time-start_time);
	cout<<"Time taken : "<<duration.count()<<" microseconds"<<endl;
}


