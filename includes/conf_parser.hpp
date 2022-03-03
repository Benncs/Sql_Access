#ifndef __CONF_PARSER_HPP
#define __CONF_PARSER_HPP

#include <fstream>
#include <string>
#include "sql_info.hpp"

/*
config file in like :

	[mysql_server]
	server_ip = 127.0.0.1
	user = root
	password = 1234
	default_schema = dev

	[other]
	otherkey = value

while key is lhs, value is rhs and token is =

As we know what key is wanted, we can use key size to find out which key is read, so far there is no key with the same size

*/

//Number of character of key, use to compare with switch statement
constexpr size_t server_ip = 9;
constexpr size_t user = 4;
constexpr size_t password = 8;
constexpr size_t schema = 14;



sqlInfo Conf_Parser(const std::string& path = "./.sql_cnf.cnf");

bool MySqlSection(sqlInfo& DB, const std::string& key, const std::string& value);

#endif // !__CONF_PARSER_HPP