/*************************************************************************
      > File Name: thread_spurious_wakeup.cpp
      > Author: 小和尚念经敲木鱼
      > Mail:  
      > Created Time: Sat 16 Oct 2021 06:25:49 PM CST
 ***********************************************************************/

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

/************************************************************************
* 文件说明
* 1.虚假唤醒笔记demo
* 2.后续补充知识点
************************************************************************/
std::mutex g_Mtx;
std::vector<int> g_Data;
std::condition_variable g_ConVar;
static int g_produce_count = 0;

void ConsumeData()
{
  while (1) 
  {
    {
      std::unique_lock<std::mutex> lck(g_Mtx);
      g_ConVar.wait(lck);//如果先执行的是ProductData,但是ConsumeData没有执行到wait则，会丢失nofify信号。则一直阻塞
      std::cout << "Data size = " << g_Data.size() << "\tData =" << *g_Data.begin()<< std::endl;
      g_Data.erase(g_Data.begin());
    }
    std::chrono::milliseconds sleep_time(1);
    std::this_thread::sleep_for(sleep_time);
  }
}

void ProduceData()
{
  while (1) 
  {
    {
      std::unique_lock<std::mutex> lck(g_Mtx);
      g_Data.push_back(g_produce_count);
      g_produce_count++;
      g_ConVar.notify_all();
    }
    std::chrono::milliseconds sleep_time(5);
    std::this_thread::sleep_for(sleep_time);
  }
}

int main(int agc,char * agv[])                                                    
{

  std::cout << "[" << __FILE__ << "]" << " thread note" << std::endl;
  std::thread thread1(ProduceData);
  std::thread thread2(ConsumeData);

  if (thread1.joinable())
    thread1.join();

  if (thread2.joinable())
    thread2.join();

  return 0;
}
/******************************end of file******************************/
