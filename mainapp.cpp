#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fstream>
#include<signal.h>
#include<cmath>
using namespace std;

pid_t pid1,pid2,pid3;
int  pid11,pid22,pid33,pid12;//getpid();

void wait_pid(int signo)
{cout<<"get signal"<<" "<<signo<<endl;
//kill(pid12,SIGINT);
int count = 0;
while(1)
{
	int pid = waitpid(-1,NULL,WNOHANG);
	if(pid>0){
	cout<<"recycle child process"<<pid<<endl;
	count++;}
if(count == 3)
break;
}
exit(0);
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

void prime()
{ signal(SIGINT,wait_pid);
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

void  process()
{
	pid1=fork();
        if(pid1 == 0 )
        { 
        pid11=getpid();
        std::cout<< "I am son1"<<" " <<pid11<<std::endl;
        execl("/home/rootyy/Desktop/unix/Fibornacci","Fibornacci",NULL);
        exit(0);}

        pid2=fork();
         if(pid2 == 0)
        { 
        pid22 =getpid();
        std::cout<< "I am son2"<<" " <<pid22<<std::endl;
        execl("/home/rootyy/Desktop/unix/natural-number","natural-number",NULL);
        exit(0);
        }


        pid3=fork();
         if(pid3 == 0)
        {
        pid33=getpid();
        std::cout<< "I am son3"<<" " <<pid33<<std::endl;
         execl("/home/rootyy/build-unix-Desktop_Qt_5_14_1_GCC_64bit-Debug/unix","unix",NULL);

        exit(0);}
         if(pid1<0||pid2<0||pid3<0)
                { std::cout<<"Error"<<std::endl;
                        exit(0);}
           else{ 
		pid12 = getpid();
                std::cout<< "I am father"<<" " <<pid12<<std::endl;
		prime();
		exit(0);
	 }
}

int main()
{
        process();
        return 0;
}  
