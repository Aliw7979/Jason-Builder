#include"StrData.hpp"
#include"Defines.hpp"
#include<iostream>
void StrData::print(std::vector<AllObjects*>&all_of_objects_temp)
{
	if (key != DEFAULT_KEY) {
		std::cout << "\t" << '"' << key << '"' << ':' << " " << '"' << data << '"';
	}
	else if (key == DEFAULT_KEY) {
		std::cout << "\t" << " " << '"' << data << '"' ;
	}
	if (all_of_objects_temp.size() == 1) {
		std::cout << std::endl;
	}
	else {
		std::cout << "," << std::endl;
	}

}

StrData::StrData(std::string data_temp, std::string key_temp,int id_temp)
	: AllObjects(key_temp, "str",id_temp)
{
	data = data_temp;
}

void StrData::nested_id_collector(int id_of_nested_item)
{
	return;
}