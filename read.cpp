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
        string command,precommand="get ",mycommand="select * from testt where id=";
        cin >> command;
        //command=command+'\0';
        mycommand=mycommand+command;
      //	cout << mycommand << endl;
	     precommand=precommand+command;
        redisReply* r=(redisReply*)redisCommand(connredis,precommand.c_str());
         if(  r->type != REDIS_REPLY_STRING)  
    {  
        printf("Failed to execute command\n");   
        mysqlpp::Query query=connmysql.query(mycommand);
        mysqlpp::StoreQueryResult res=query.store();
                  for(size_t i=0;i<res.num_rows();++i){
			       cout << res[i][1] << endl;
                  command="set "+command+" "+(string)res[i][1];
                     //cout << command;
                  redisCommand(connredis,command.c_str());
                  freeReplyObject(r);  
                  redisFree(connredis);
		 }
        
    }     
         else {
        printf("The value of is %s\n", r->str); 
    freeReplyObject(r);  
     redisFree(connredis);
    printf("Succeed to execute command\n");  }
        
        
}
