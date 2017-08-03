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
        string command,mycommand1="insert into testt (id,title) values (",mycommand2=")";
        cin >> command;
        mycommand1=mycommand1+command+mycommand2;
        mysqlpp::Query query=connmysql.query(mycommand1);
        mysqlpp::StoreQueryResult res=query.store();
        cout << "insert into mysql success" << endl;
                  for(int i=0;i<command.size();++i){
                           if(command[i]==',') command[i]=' ';
                           if(command[i]=='"') command[i]=' ';
                           if(command[i]=='"') command[i]=' ';
        }
        command="set "+command;
        redisReply* r=(redisReply*)redisCommand(connredis,command.c_str());
        freeReplyObject(r);  
        redisFree(connredis);
        cout << "update redis success" << endl;
}        
