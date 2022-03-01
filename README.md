# OVERALL

Basic way to interface with mysql connector for cpp
Instead of using direcly it, sqlmanager wrap methods to be more "user friendly"

# Installation 

## On unix


## On windows
So far, only msvc can build cpp connector. to compile it : 
- Download connector (header as include + (dll and lib) as lib64 )
- Include directory include as well as include/jdbc include/mysql include/mysqlx (it simplies #include, if you don't want to do it please just modify header include in sqlmanager.hpp )
- Link static file (in lib64/vs14) 
- Put dll in build directory or add it to path 