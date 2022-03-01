#include <iostream>
#include "sqlmanager.hpp"

int main(){

	const sqlInfo Param = sqlInfo("127.0.0.1:3389", "root", "", "DB"); //Parameter of the sql server
	auto db = sqlManager(Param) ; //Init db
	db.Query("select * from TestDB");
	while(db.res->next()){
		std::cout<<db.res->getString("name")<<std::endl;	
	}
	return 0;
}
