#include <mysql++/mysql++.h>
#include <iostream>
#include <hiredis/hiredis.h>
#include <string>
#include <vector>
#include <strings.h>
using namespace std;

int main(){
        redisContext* connredis =redisConnect("127.0.0.1",6379);
        mysqlpp::Connection connmysql(true);
        connmysql.connect("test", "localhost", "root", "812666", 3306);
        string command,mycommand="delete from testt where id=";
        cin >> command;
        mycommand=mycommand+command;
        mysqlpp::Query query=connmysql.query(mycommand);
        mysqlpp::StoreQueryResult res=query.store();
        cout << "delete success" << endl;
        command="del "+command;
        redisReply* r=(redisReply*)redisCommand(connredis,command.c_str());
        freeReplyObject(r);  
        redisFree(connredis);
        cout << "update redis success" << endl;
}
