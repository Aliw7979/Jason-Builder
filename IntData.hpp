#ifndef INTDATA_H
#define INTDATA_H "INTDATA_H"
#include"AllObjects.hpp"

class IntData :public AllObjects
{
public:
	IntData(int data_temp, std::string key_temp,int id_temp);
	virtual void nested_id_collector(int id_of_nested_item);
	virtual void print(std::vector<AllObjects*>&all_of_objects_temp);
private:
	int data;
};
#endif