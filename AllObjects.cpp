#include"AllObjects.hpp"

AllObjects::AllObjects(int id_temp, std::string key_temp, std::string type_init) {
	id = id_temp;
	key = key_temp;
	type = type_init;
}
AllObjects::AllObjects(std::string key_temp, std::string type_init,int id_init)
{
	key = key_temp;
	type = type_init;
	id = id_init;
}

int AllObjects::get_id()
{
	return id;
}
