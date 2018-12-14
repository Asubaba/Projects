#include <iostream>
#include  "LinkedList.h"

int main()
{
	LinkedList<int> list;

	for (int i = 0; i < 10; i++)
		list.insert(i);
	list.display();

	std::cin.get();
}