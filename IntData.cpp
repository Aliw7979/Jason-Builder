#include"IntData.hpp"
#include<iostream>
#include"Defines.hpp"
void IntData::print(std::vector<AllObjects*>&all_of_objects_temp)
{
	if (key != DEFAULT_KEY) {
		std::cout << "\t" << '"' << key << '"' << ':' << " " << data;
	}
	else if (key == DEFAULT_KEY) {
		std::cout << "\t" << " " << data;
	}
	if (all_of_objects_temp.size() == 1) {
		std::cout << std::endl;
	}
	else {
		std::cout << "," << std::endl;
	}

}

IntData::IntData(int data_temp, std::string key_temp,int id_temp)
	: AllObjects(key_temp, "int",id_temp)
{
	data = data_temp;
}

void IntData::nested_id_collector(int id_of_nested_item)
{
	return;
}
