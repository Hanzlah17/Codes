#include <iostream>

#include <string.h>

#include<climits>

#include<pthread.h>

#include <climits>

using namespace std;



float average=0;

int maximum= INT_MIN;

int minimum= INT_MAX;



void *CalculateAverage(void* args)

{



 int* array=(int*) args;

 int size=array[0]; 

 int sum=0;

 for(int i=1;i<=size;i++)

 {

    sum+=array[i];

 }

average=sum/size;

return NULL;

}

void* FindArrayMax(void* args)

{

   int* array=(int*) args;

   int size=array[0]; 

   for(int i=1;i<size;i++)

   {

      if(array[i]>maximum)

      {

         maximum=array[i];

      }

   }

   return NULL;

}

void* FindArrayMin(void* args)

{

   int* array=(int*) args;

   int size=array[0]; 

   for(int i=1;i<size;i++)

   {

      if(array[i]<minimum)

      {

         minimum=array[i];

      }

   }

   return NULL;

}

int main()

{

  pthread_t avg_id;

  pthread_t max_id;

  pthread_t min_id;

  int array[8]={7,90,81,78,95,79,72,85};

  //average thread

  if (pthread_create(&avg_id, NULL, &CalculateAverage, &array)==-1)

  {

      cout<<"Thread Creation Failed!"<<endl;

      return 1;

  }

  //max thread

  if(pthread_create(&max_id,NULL,&FindArrayMax,&array)==-1)

  {

      cout<<"Thread Creation Failed!"<<endl;

      return 1;

   }

   //min thread

   if(pthread_create(&min_id,NULL,&FindArrayMin,&array)==-1)

  {

      cout<<"Thread Creation Failed!"<<endl;

      return 1;

   }

   pthread_join(avg_id, NULL); 

   cout << "Average: " << average << endl;

   pthread_join(max_id, NULL);

   cout << "Maximum: " << maximum<< endl;

   pthread_join(min_id, NULL);

   cout << "Minimum: " << minimum<< endl;

   return 0;

  



}