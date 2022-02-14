#include"JsonBuilder.hpp"
#include"Object.hpp"
#include"StrData.hpp"
#include"IntData.hpp"
#include"Defines.hpp"

void JsonBuilder::print(int id)
{
	std::vector<AllObjects*>temp_of_all_objects = all_objects;
	if (id == MOTHER_OBJECT) {
		for (int i = 0; i < temp_of_all_objects.size(); i++) {
			temp_of_all_objects[i]->print(temp_of_all_objects);
		}
	}
	else {
		for (int i = 0; i < temp_of_all_objects.size(); i++) {
			if (id == temp_of_all_objects[i]->get_id()) {
				temp_of_all_objects[i]->print(temp_of_all_objects);
				break;
			}
		}
	}
}




int JsonBuilder::id_creator()
{
	srand((unsigned)time(0));
	int all_ids_temp = rand() % 99999;
	all_ids.push_back(all_ids_temp);
	return all_ids_temp;
}

int JsonBuilder::addContainerToArray(int parent_id, std::string type)
{
	int temp_id;
	int created_id;
	if (parent_id == MOTHER_OBJECT) {
		created_id = id_creator();
		Object * new_object = new Object(created_id, type, DEFAULT_KEY);
		all_objects.push_back(new_object);
	}
	else {
		for (int i = 0; i < all_objects.size(); i++) {
			if (all_objects[i]->get_id() == parent_id) {
				created_id = id_creator();
				temp_id = i;
				Object * new_object = new Object(created_id, type, DEFAULT_KEY);
				all_objects.push_back(new_object);
				all_objects[temp_id]->nested_id_collector(created_id);
				break;
			}
		}

	}
	return created_id;
}

void JsonBuilder::addStringToArray(int parent_id, std::string value)
{
	int created_id;
	int temp_id;
	for (int i = 0; i < all_objects.size(); i++) {
		if (all_objects[i]->get_id() == parent_id) {
			temp_id = i;
			created_id = id_creator();
			StrData *new_str_data = new StrData(value, DEFAULT_KEY,created_id);
			all_objects.push_back(new_str_data);
			all_objects[temp_id]->nested_id_collector(created_id);
			break;
		}
	}
}
void JsonBuilder::addIntegerToArray(int parent_id, int value)
{	
	int created_id;
	int temp_id;
	for (int i = 0; i < all_objects.size(); i++) {
		if (all_objects[i]->get_id() == parent_id) {
			temp_id = i;
			created_id = id_creator();
			IntData *new_str_data = new IntData(value, DEFAULT_KEY,created_id);
			all_objects.push_back(new_str_data);
			all_objects[temp_id]->nested_id_collector(created_id);
			break;
		}
	}
}

void JsonBuilder::addStringToObject(int parent_id, std::string key, std::string value)
{
	int created_id;
	int counter;
	int temp_id;
	if (parent_id == MOTHER_OBJECT) {
		created_id = id_creator();
		StrData *new_str_data = new StrData(value, key,created_id);
		all_objects.push_back(new_str_data);
	}
	else {
		for (int i = 0; i < all_objects.size(); i++) {
			if (all_objects[i]->get_id() == parent_id) {
				temp_id = i;
				created_id = id_creator();
				StrData *new_str_data = new StrData(value, key,created_id);
				all_objects.push_back(new_str_data);
				all_objects[temp_id]->nested_id_collector(created_id);
				counter = 1;
				break;
			}
		}
		if (counter != 1) {
			created_id = id_creator();
			StrData *new_str_data = new StrData(value, key,created_id);
			all_objects.push_back(new_str_data);
		}
	}

}


void JsonBuilder::addIntegerToObject(int parent_id, std::string key, int value)
{	
	int created_id;
	int temp_id;
	if (parent_id == MOTHER_OBJECT) {
		created_id = id_creator();
		IntData *new_str_data = new IntData(value, key,created_id);
		all_objects.push_back(new_str_data);
	}
	else {
		for (int i = 0; i < all_objects.size(); i++) {
			if (all_objects[i]->get_id() == parent_id) {
				temp_id = i;
				created_id = id_creator();
				IntData *new_str_data = new IntData(value, key,created_id);
				all_objects.push_back(new_str_data);
				all_objects[temp_id]->nested_id_collector(created_id);
				break;
			}
			else {
				created_id = id_creator();
				IntData *new_str_data = new IntData(value, key,created_id);
				all_objects.push_back(new_str_data);
			}
		}

	}
}

int JsonBuilder::addContainerToObject(int parent_id, std::string key, std::string type)
{
	int temp_id;
	int created_id;
	if (parent_id == MOTHER_OBJECT) {
		created_id = id_creator();
		Object * new_object = new Object(created_id, type, key);
		all_objects.push_back(new_object);
	}
	else {
		for (int i = 0; i < all_objects.size(); i++) {
			if (all_objects[i]->get_id() == parent_id) {
				created_id = id_creator();
				temp_id = i;
				Object * new_object = new Object(created_id, type, key);
				all_objects.push_back(new_object);
				all_objects[temp_id]->nested_id_collector(all_objects.size() - 1);
				break;
			}
		}

	}
	return created_id;
}
