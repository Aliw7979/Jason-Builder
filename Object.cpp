#include"Object.hpp"
#include"Defines.hpp"
#include<iostream>


void Object::print(std::vector<AllObjects*>&all_of_objects_temp)
{
	if (type == "array") {
		if (key != DEFAULT_KEY) {
			std::cout << "\t" << '"' << key << '"' << ':' << ' ' << '[' << std::endl << "\t";
		}
		else {
			std::cout << "\t" << ' ' << '[' << std::endl;
		}

		for (int i = 0; i < id_of_nested_objects.size(); i++) {
			for (int j = 0; j < all_of_objects_temp.size(); j++) {
				if (all_of_objects_temp[j]->get_id() == id_of_nested_objects[i]) {
 					all_of_objects_temp[j]->print(all_of_objects_temp);
					all_of_objects_temp.erase(all_of_objects_temp.begin() + j);
				}
			}

		}

		for (int i = 0; i < all_of_objects_temp.size(); i++) {
			if (id == all_of_objects_temp[i]->get_id()) {
				all_of_objects_temp.erase(all_of_objects_temp.begin() + i);
				break;
			}
		}

		
		std::cout << "\t" << "]" << std::endl;

	}
	else if (type == "object") {
		if (key != DEFAULT_KEY) {
			std::cout << "\t" << '"' << key << '"' << ':' << ' ' << '{' << std::endl << "\t";
		}
		else {
			std::cout << "\t" << ' ' << '{' << std::endl;
		}
		for (int i = 0; i < id_of_nested_objects.size(); i++) {
			for (int j = 0; j < all_of_objects_temp.size(); j++) {
				if (all_of_objects_temp[j]->get_id() == id_of_nested_objects[i]) {
					all_of_objects_temp[j]->print(all_of_objects_temp);
					all_of_objects_temp.erase(all_of_objects_temp.begin() + j);
				}
			}
			
		}

		for (int i = 0; i < all_of_objects_temp.size(); i++) {
			if (id == all_of_objects_temp[i]->get_id()) {
				all_of_objects_temp.erase(all_of_objects_temp.begin() + i);
				break;
			}
		}

		std::cout << "\t" << "}" << std::endl;
	}
}



Object::Object(int id_temp, std::string data_type_temp, std::string key_temp)
	: AllObjects(id_temp, key_temp, data_type_temp)
{
	data_type = data_type_temp;
}

void Object::nested_id_collector(int id_of_nested_item)
{
	id_of_nested_objects.push_back(id_of_nested_item);
}