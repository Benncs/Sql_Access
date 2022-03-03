#ifndef __SQL_INFO_HPP__
#define __SQL_INFO_HPP__

#include <string>
/**
 * \brief Structur to store sql server's info
 */
struct sqlInfo{
	sqlInfo() = default;
	sqlInfo(std::string s, std::string un, std::string pwd, std::string schem)
		:server(std::move(s)), username(std::move(un)), password(std::move(pwd)), schema(std::move(schem)){
	}
	std::string server;
	std::string username;
	std::string password;
	std::string schema;
};
#endif // !__SQL_INFO_HPP__

