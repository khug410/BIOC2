/*
 *  Kelsey Hughes
 *  1/31/2022
 * This code will act as a primer on class design and creation in C++
 */

#include <iostream>
#include <fstream>
#include <string>


// mySpace::yourSpace::myClass
namespace mySpace{
	namespace yourSpace{
		class myClass{
			public:
				//construct myclass with an intitial name, and numbe rof students
				myClass(std::string name, int init_num_students); 
				myClass(std::string name); //std is the namespace, string is the class

				int get_num_students();
				std::string get_name();
				void set_num_student(int num);

			private:
				int num_students;
				std::string className;		
				};
	}
}
