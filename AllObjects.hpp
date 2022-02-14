#ifndef ALLOBJECTS_H
#define ALLOBJECTS_H "ALLOBJECTS_H"
#include<vector>
#include<string>

class AllObjects
{
public:
	AllObjects(int id_temp, std::string key_temp, std::string type_init);
	AllObjects(std::string key_temp, std::string type_init,int id_init);
	virtual void nested_id_collector(int id_of_nested_item) = 0;
	virtual void print(std::vector<AllObjects*>&all_of_objects_temp) = 0;

	int get_id();
protected:
	std::string key;
	int id;
	std::string type;
};
#endif