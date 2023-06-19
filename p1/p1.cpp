#include <iostream>

int add(int x, int y);

int main(){
	int x;
	std::cout << "digite um numero: ";
	std::cin >> x;
	std::cout << add(x,5);
	
	return 0;
}