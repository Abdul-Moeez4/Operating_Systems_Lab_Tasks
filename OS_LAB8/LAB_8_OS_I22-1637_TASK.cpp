#include <iostream>
#include <pthread.h>
using namespace std;

int global_array[20];




//function for sum 
void* sum_func(void* meh)
{
    int sum = 0;

    for (int i = 0 ; i < 20; i++)
    {
        sum += global_array[i];
    }

    cout<<"SUM is : "<<sum;

    pthread_exit(NULL);


}


void* multi_func(void* wo)
{
    int product = 1;

    for (int i = 0 ; i < 20 ; i++)
    {
        product = product * global_array[i];
    }

    cout<<"Product is: "<<product;

    pthread_exit(NULL);

}

void* specific_func(void* mo)
{
    bool found;

    int n = *(int*) mo;
    for (int i=0; i <20; i++)
    {
        if (global_array[i] == n)
        {
            found = true;
            cout<<"FOUND! index: "<<global_array[i];
        }
    }

    pthread_exit(NULL);

}





int main()
{

    for (int i=0; i< 20; i++)
    {
        global_array[i] = i + 1;
    }

    int n = 5;

    pthread_t thread1;

    pthread_t thread2;
    
    pthread_t thread3;
    
    //create attributes for three threads
    pthread_attr_t sum_attr;  //attribute for sum

    pthread_attr_t multi_attr; //attribute for multiplication

    pthread_attr_t specific_attr; //attribute for specific 

    //intilize these attributes
    pthread_attr_init(&sum_attr);  //initlised sum attribute

    pthread_attr_init(&multi_attr);  //initlised sum attribute

    pthread_attr_init(&specific_attr); //initlised  specific attribute

     //set detach thread
    pthread_attr_setdetachstate(&sum_attr, PTHREAD_CREATE_DETACHED);

    pthread_attr_setdetachstate(&multi_attr, PTHREAD_CREATE_DETACHED);

    pthread_attr_setdetachstate(&specific_attr, PTHREAD_CREATE_DETACHED);

    //create threads
    pthread_create(&thread1, &sum_attr, sum_func, NULL);

    pthread_create(&thread2, &multi_attr, multi_func, NULL);

    pthread_create(&thread3, &specific_attr, specific_func, (void*)&n);

    //set d
    pthread_attr_destroy(&sum_attr);

    pthread_attr_destroy(&multi_attr);

    pthread_attr_destroy(&specific_attr);

    pthread_exit(NULL);





}
