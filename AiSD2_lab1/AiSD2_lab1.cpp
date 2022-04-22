
#include <iostream>
#include "Map.h"

int main(){

	Map<int, int> map;

	map.insert(1, 11);
	map.insert(2, 22);
	map.insert(3, 33);
	map.insert(4, 44);
	map.insert(5, 55);
	map.insert(6, 66);
	map.insert(7, 77);
	map.insert(8, 88);
	
	std::cout << "my map: " << std::endl;
	map.print();
	std::cout << std::endl;

	std::cout << "deleting a note with key 1..." << std::endl;
	map.removeNote(1);
	std::cout << "my map: " << std::endl;
	map.print();
	std::cout << std::endl;

	std::cout << "deleting a note with key 3..." << std::endl;
	map.removeNote(3);
	map.print();
	std::cout << std::endl;

	std::cout << "vector of the keys: " << std::endl;
	std::vector<int> getKeys = map.getKeys();
	for (int i = 0; i < getKeys.size(); i++)
		std::cout << getKeys[i] << " ";
	std::cout << std::endl << std::endl;
	
	std::cout << "vector of the values: " << std::endl;
	std::vector<int> getValue = map.getValues();
	for (int i = 0; i < getValue.size(); i++)
		std::cout << getValue[i] << " ";
	std::cout << std::endl<< std::endl;

	std::cout << "clearing map... " << std::endl;
	map.clear();
	std::cout << "my map: " << std::endl;
	map.print();
	return 0;
}

