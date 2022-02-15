/*Name: Kelsey Hughes
  Date: 2/15/2022
  Details: The objective of  this code is to hack time
*/

#include "hughesk_MiniProject0.hpp"
using namespace MiniProject0;

//define constructor
TimeHacking::TimeHacking(std::string objectToHack){

}

void MiniProject0::TimeHacking::setTimeToHack(int seconds){
    this -> time_to_hack = seconds;
}

int MiniProject0::TimeHacking::getTimeToHack(){
    return time_to_hack;
}

std::string MiniProject0::TimeHacking::getObjectToHack(){
    return objectToHack;
}

void MiniProject0::TimeHacking::hackTime(){
    //the user should sleep for the number of seconds the user indicated before indicating the time was hacked    
    sleep(time_to_hack);
}

int main(int argc, char* argv[]){
    std::string object;
    std::cout <<"What object do you want to hack? \n";
    char store[50];
    scanf("%s", store);

    std::cout <<"How many seconds do you want to hack for? \n";
    int seconds;
    scanf("%i", &seconds);

    std::cout <<"The object is: " << store << "\n";
    std::cout <<"The number of seconds for hacking is: " << seconds << "\n";

    MiniProject0::TimeHacking hackers(object);

    hackers.setTimeToHack(seconds);
    hackers.getTimeToHack();
    hackers.getObjectToHack();
    std::cout << "Hacking object " << object << "currently \n";
    hackers.hackTime();
    std::cout << "Hacking is Complete \n";
    return 0;

    



    




}