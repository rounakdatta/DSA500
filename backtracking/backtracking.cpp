#include <iostream>
#include "one.h"
//#include "two.h"
//#include "three.h"

int main()
{
	int ch;
	std::cout<<"(1) n-queens problem"<<endl;
	//std::cout<<"(3) three elements in an array whose sum is equal to a given number"<<endl;
	std::cin>>ch;

	switch(ch) {
		case 1: 
			one();
			break; 
		case 2:
			break;
		case 3:
			//three();
			break;
	}
	return 0;
}