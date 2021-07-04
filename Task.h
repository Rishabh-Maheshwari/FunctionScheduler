#include "common.h"

template <class T> class Task{
    long delay,initalDelay;
    T *ownerObj;
    void (T::*func)(int,int);
public:
    Task(T *ownerObj,void (T::*funcPointer)(int,int),int id,int delay)
    {
        this->ownerObj=ownerObj;
        func=funcPointer;
        initalDelay=id;
        this->delay=delay;
    }
    void execute()
    {
        std::cout<<"executing";
        std::invoke(func,*ownerObj,initalDelay,delay);
    }
};
