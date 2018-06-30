#include<iostream>
using namespace std;

int main(){
	char first, last;
	first = std::cin.get();
	std::cin.ignore(256,' ');
	last = std::cin.get();
	std::cout<<"Your initials are: "<<first<<last<<std::endl;
	return 0;
}
