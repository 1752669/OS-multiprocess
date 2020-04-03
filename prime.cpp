#include<iostream>
#include<stdio.h>
#include<cmath>
#include<unistd.h>
#include<fstream>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>
using namespace std;

void kill_process(int pid11,int pid22,int pid33)
{
        kill(pid11,SIGTERM);
        kill(pid22,SIGTERM);
        kill(pid33,SIGTERM);
        while(waitpid(-1,NULL,WNOHANG)>0)
        std::cout<<"endl_process"<<std::endl;
}


int  prim( long n)
{
        long  i;
        int flag = 0;
 for(i = 2; i<sqrt(n);i++)
{
        if(n%i==0)
        {flag = 1;break;}
}

return flag;
}

void p(int pid11,int pid22,int pid33){
signal(SIGINT,kill_process(pid11,pid22,pid33));
ofstream outfile;
outfile.open("prime.txt");
 long  n = 0 ,k = 0;
for(n =2;;n++)
{
        k =prim(n);
       if(k == 0)
        outfile<<"prime="<<n<<endl;
	usleep(100);
}
outfile.close();
}
int main(){
p();
return 0;
}
