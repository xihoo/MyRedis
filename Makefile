all:read write delete modify
read:read.cpp
	g++ read.cpp -o read -lhiredis -lmysqlpp
write:write.cpp
	g++ write.cpp -o write -lhiredis -lmysqlpp
delete:delete.cpp
	g++ delete.cpp -o delete -lhiredis -lmysqlpp
modify:modify.cpp
	g++ modify.cpp -o modify -lhiredis -lmysqlpp
clean:
	rm -f read write delete modify
