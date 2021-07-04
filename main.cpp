#include <iostream>
#include<conio.h>
#include "Scheduler.h"

using namespace std;

class sampleClass
{
    int a;
public:
    void add(int,int);
    void multiply(int,int);
    void show();
};
void sampleClass::add(int num1,int num2)
{
    a=num1+num2;
}
void sampleClass::multiply(int num1,int num2)
{
    a=num1*num2;
}
void sampleClass::show()
{
    cout<<"The value of a is "<<a<<endl;
}
int main()
{
    Scheduler<sampleClass> scheduleObj;
    sampleClass sampleObj;
    scheduleObj.schedule(&sampleObj,&sampleClass::add,80,1000);
    //sampleObj.show();
    scheduleObj.schedule(&sampleObj,&sampleClass::multiply,80,19880);
    //sampleObj.show();
    return 0;
}
