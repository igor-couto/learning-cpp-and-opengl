#include <iostream>
 
int main()
{
    char ch;
    std::cout << "Say something with 3 letters: ";
	std::cin >> ch;
    std::cout << static_cast<int>(ch) << std::endl;
    std::cin >> ch;
	std::cout << static_cast<int>(ch) << std::endl;
	std::cin >> ch;
	std::cout << static_cast<int>(ch) << std::endl;

    return 0;
}