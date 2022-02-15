/*Name: Kelsey Hughes
  Date: 2/15/2022
  Details: The objective of this header file is to create a function that will hack code time

*/

#ifndef Kelsey0
#define Kelsey0

#include <iostream>
#include <unistd.h>

namespace MiniProject0{
    class TimeHacking{
    public:
       

        TimeHacking(std::string objectToHack); 
        void setTimeToHack(int seconds);
        int getTimeToHack();
        std::string getObjectToHack();
        void hackTime();
    private:
        int time_to_hack;
        std::string objectToHack;

    };
}


#endif