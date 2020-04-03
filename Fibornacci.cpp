#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;

int  main()
 {
unsigned long long tmp2 = 1, tmp1 = 1, sum = 0;
 ofstream outfile;
	outfile.open("Fibornacci.txt");
	outfile<<"sum="<<tmp1<<endl;
	usleep(50);
	outfile<<"sum="<<tmp2<<endl;
	usleep(50);
     while(1)
     {
         sum = tmp1 + tmp2;
         tmp1 = tmp2;
         tmp2 = sum;
         outfile<<"sum="<<sum<<endl;
	usleep(50);        
     }
outfile.close();
return 0;
}
