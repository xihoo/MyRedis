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
        pair<string,string> command;
        string mycommand1="update testt set title=",mycommand2=" where id=";
        cin >> command.first >> command.second;
        mycommand1=mycommand1+'"'+command.second+'"'+mycommand2+command.first;
        cout << mycommand1;
        mysqlpp::Query query=connmysql.query(mycommand1);
        mysqlpp::StoreQueryResult res=query.store();
        cout << "modify in mysql success" << endl;
        mycommand2="set "+command.first+' '+command.second;
        redisReply* r=(redisReply*)redisCommand(connredis,mycommand2.c_str());
        freeReplyObject(r);  
        redisFree(connredis);
        cout << "update redis success" << endl;
}
