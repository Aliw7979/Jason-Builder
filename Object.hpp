#ifndef OBJECT_H
#define OBJECT_H "OBJECT_H"
#include<vector>
#include<string>
#include"AllObjects.hpp"
class Object :public AllObjects
{
public:
	virtual void nested_id_collector(int id_of_nested_item);
	virtual void print(std::vector<AllObjects*>&all_of_objects_temp);
	Object(int id_temp, std::string data_type_temp, std::string key_temp);
private:
	std::vector<std::string> str_data_type;
	std::string data_type;
	int int_data_type;
	std::vector<int>id_of_nested_objects;
};
#endif
