#include<iostream>

#include<vector>

#include<pthread.h>

using namespace std;

vector<int> fibSeq;

void* GenerateFibSeq(void* args)

{

    int num=*(int*) args;

    if(num<0)

    {

        cout<<"Invalid input\n";

        exit(1); //exit the program

    }

    fibSeq.push_back(0);

    if(num==0)

    {

        return NULL;

    }

    fibSeq.push_back(1);

    if(num==1)

    {

        return NULL;

    }

    for(int i=2;i<=num;i++)

    {

        fibSeq.push_back(fibSeq[i-1]+fibSeq[i-2]);

    }

    return NULL;

}

int main()

{

    int num;

    cout<<"Enter the number: ";

    cin>>num;

    pthread_t id;

    pthread_create(&id,NULL,&GenerateFibSeq,&num);

    pthread_join(id,NULL);

    for(int i=0;i<fibSeq.size();i++)

    {

        cout<<fibSeq[i]<<"\t";

    }

    return 0;

}