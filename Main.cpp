#include "LinkedList.h"

#include <iostream>

int main()
{
	LinkedList<int> list;
	list.add(5);
	list.add(10);
	list.add(1);

	list.remove(1);

	std::cout << list[1] << std::endl;
	std::cout << list.size() << std::endl;
	
	return 0;
}