#ifndef STRDATA_H
#define STRDATA_H "STRDATA_H"
#include"AllObjects.hpp"
class StrData :public AllObjects
{
public:
	StrData(std::string data_temp, std::string key_temp,int id_temp);
	virtual void nested_id_collector(int id_of_nested_item);
	virtual void print(std::vector<AllObjects*>&all_of_objects_temp);
private:
	std::string data;
};

#endif
