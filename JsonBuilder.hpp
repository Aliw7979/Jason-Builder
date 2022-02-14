#ifndef JSONBUILDER_H
#define JSONBUILDER_H "JSONBUILDER_H"
#include"AllObjects.hpp"
class JsonBuilder
{
public:

	void addStringToObject(int parent_id, std::string key, std::string value);
	void addIntegerToObject(int parent_id, std::string key, int value);
	int addContainerToObject(int parent_id, std::string key, std::string type);
	void addStringToArray(int parent_id, std::string value);
	void addIntegerToArray(int parent_id, int value);
	int addContainerToArray(int parent_id, std::string type);
	int id_creator();
	int object_creator(std::string key, std::string type);
	void print(int id);
private:
	std::vector<int>all_ids;
	std::vector<AllObjects*>all_objects;

};
#endif