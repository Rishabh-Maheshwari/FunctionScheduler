#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED
#include "Task.h"
#include <mutex>
#include<thread>
using namespace std;
template<typename T> class Scheduler{
    std::queue<Task<T>> taskQueue;
    std::mutex m;
    std::vector<std::thread> pool;
    std::vector<bool> vis;
public:
    void schedule(T *obj,auto pFun,int arg1,int arg2)
    {
        Task<T> t(obj,pFun,arg1,arg2);
        m.lock();
        taskQueue.push(t);
        int i=0;
        for(;i<pool.size();i++){
            if(!vis[i]){
                vis[i]=true;
                break;
            }
        }
        if(i==pool.size()){
            pool.push_back(std::thread(&Scheduler<T>::trythis,this,i,t));
            vis.push_back(true);
        }
        else{
            pool[i]=std::thread(&Scheduler<T>::trythis,this,i,t);
        }
        pool[i].detach();
        m.unlock();
    }
    void trythis(int j,Task<T> t)
    {
        cout<<"hello";
        t.execute();
        m.lock();
        vis[j]=false;
        m.unlock();
    }
};

#endif // SCHEDULER_H_INCLUDED
