/*
 Implement your own string class like std::string class
*/

#include<iostream>
#include<ostream>
#include <string.h>
using namespace std ;

class myString{
     private:
          //pointing to char array
          char *buffer = nullptr; 
          size_t  curSize = 0;
          void __reset__()
          {
               if(buffer!=nullptr)
                    delete[] buffer ;
               curSize = 0;     
          }
     public:
          //dafault constructor
          myString():buffer(nullptr) ,curSize(0){}
          //constructor
          myString(const char * str)
          {
               curSize = strlen(str);
               buffer= new char[curSize+1];
               strncpy(buffer,str,curSize+1);
          }
          //copy constructor
          myString(const myString& obj)
          {
               curSize = obj.curSize;
               // +1 to handel null character
               buffer= new char[curSize+1];
               // copy from the incoming buffer to character buffer of the new object
               strncpy(buffer,obj.buffer,curSize+1);
          }

          //move constructor
          myString(myString && dyingObj)
          {
               //clear all the previous data
               __reset__();
               curSize = dyingObj.curSize;
               buffer = dyingObj.buffer;
               dyingObj.buffer = nullptr;
          }
          //copy assignment
          myString& operator =(const myString& obj)
          {    
               //clear all the previous data
               __reset__();
               curSize = obj.curSize;
               buffer= new char[curSize+1];
               strncpy(buffer,obj.buffer,curSize+1);
               return *this ;
          }
          
          //move assignment
          // && is a reference operator defined in the C++11 standard 
          // which means "dyingObj" is an r-value reference.
          // Compiler calls this constructor when the object passed in the argument
          // is about to die due to scope end or such
          myString& operator=(myString && dyingObj)
          {
               //clear all the previous data
               __reset__();
               //copy data from incoming object 
               curSize = dyingObj.curSize ;
               //Transfer ownership of underlying char buffer from incoming object to this obj
               buffer = dyingObj.buffer;
               dyingObj.buffer = nullptr;
               return *this;
          }
          //overload + operator
          myString operator +(const myString& obj)
          {    
               //create new temporary string
               myString tempStr;
               tempStr.curSize = this->curSize + obj.curSize ;
               tempStr.buffer = new char[ tempStr.curSize+1];
               //copy existing string in  tempStr
               strncpy(tempStr.buffer,this->buffer,this->curSize+1);
               //copy new srting in tempStr
               //shift tempStr.buffer pointer to this->size  and copy remaining string
               strncpy(tempStr.buffer + this->curSize,obj.buffer,obj.curSize+1);
               
               return tempStr ;
          }

          //overload [] operator
          char& operator [](size_t index)
          {
               if(index <0 || index >= this->curSize)
                    throw std::invalid_argument("Index must be less than vector's size");
               return buffer[index];     
          }
          const char* c_str() const
          {
               return buffer;
          }

          char& at(size_t pos)
          {
                if(pos <0 || pos >= this->curSize)
                    throw std::invalid_argument("Index must be less than vector's size");
               return  buffer[pos] ;     

          }

          size_t size() const
          {
               return curSize;
          }
          
          ~myString()
          {
               __reset__();
          }

};

ostream& operator <<(ostream & cout, myString &obj)
{
     cout<<obj.c_str();
     return cout;
}



int main()
{
     myString str("Hello world");
     myString str2("Start coding  ");
     cout<<str<<endl;
     cout<<str[1]<<endl;
     for(int i=0;i<str.size();i++)
       cout<<str.at(i);
     cout<<endl;
     cout << "The size of str is " << str.size() << " bytes.\n";
     myString newStr = str + str2;
     cout<<newStr<<endl;
}