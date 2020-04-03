#include<stdio.h>
#include<iostream>
#include<unistd.h>
#include<fstream>
using namespace std;

int main()
{ofstream outfile;
outfile.open("natural_number.txt");
int count = 100000;
for(int i = 1; i<count+1;i++)
{ outfile<<"number="<<i<<endl;

 usleep(10);
}
outfile.close();
return 0;
}

