#include<iostream>

#include<sys/wait.h>

#include<unistd.h>

using namespace std;

int main()

{

int fd[2];

int current_number;

cout<<"Enter the Number: ";

cin>>current_number;

while(current_number<1)

{

cout<<"\nEnter a positive number!!!\n";

cout<<"Enter the Number: ";

cin>>current_number;

}

if(pipe(fd)<0)

{

perror("pipe failed");

exit(1);

}

while(current_number!=1)

{

pid_t p=fork();

if(p<0)

{

perror("fork failed");

exit(1);

}

else if(p==0)

{

if(current_number%2==0)

{

current_number=current_number/2;

}

else

{

current_number=current_number*3+1;

}

cout<<"Current Number: "<<current_number<<endl;

close(fd[0]); //close reading end of the file from child

if(write(fd[1],&current_number,sizeof(int))<0)

{

perror("write failed in child");

exit(1);

}

close(fd[1]);

exit(0);

}

else

{

wait(NULL);

if(read(fd[0],&current_number,sizeof(int))<0)

{

perror("read failed in parent");

exit(1);

}

}

}

close(fd[1]); //closing write descriptor

close(fd[0]); //closing read descriptor

cout<<"Parent is terminating since current Number is: "<<current_number<<endl;

return 0;

}