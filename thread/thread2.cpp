# include <iostream>
# include <windows.h>

# define NAME_LINE 40

HANDLE hMutex = NULL;

// 定义线程数据参数结构体
typedef struct __THREAD_DATA
{
    int nMaxNum;
    char strThreadName[NAME_LINE];

    __THREAD_DATA():nMaxNum(0)
    {
        memset(strThreadName, 0, NAME_LINE * sizeof(char));
    }
}THREAD_DATA;

// 线程函数
DWORD WINAPI SubThread(LPVOID lpParamter)
{
    THREAD_DATA* threaddata = (THREAD_DATA*)lpParamter;

    for(int i=0; i<threaddata->nMaxNum; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "It is in the subthread:" << threaddata->strThreadName << "---" << i << '\n';
        Sleep(100);
        ReleaseMutex(hMutex);
    }

    return 0L;
}

int main()
{
    // 互斥量创建
    hMutex = CreateMutex(NULL, FALSE, NULL);

    // 线程数据初始化
    THREAD_DATA threaddata1, threaddata2, threaddata3;
    threaddata1.nMaxNum = 3;
    strcpy(threaddata1.strThreadName, "SubThread_1");
    threaddata2.nMaxNum = 5;
    strcpy(threaddata2.strThreadName, "SubThread_2");
    threaddata3.nMaxNum = 10;
    strcpy(threaddata3.strThreadName, "SubThread_3");   

    // 线程创建
    HANDLE Thread_1 = CreateThread(NULL, 0, SubThread, &threaddata1, 0, NULL);
    HANDLE Thread_2 = CreateThread(NULL, 0, SubThread, &threaddata2, 0, NULL);
    HANDLE Thread_3 = CreateThread(NULL, 0, SubThread, &threaddata3, 0, NULL);
    // 线程关闭
    CloseHandle(Thread_1);
    CloseHandle(Thread_2);
    CloseHandle(Thread_3);

    // 主线程执行
    for(int i=0; i<20; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);
        std::cout << "It is in the main thread:" << i << '\n';
        Sleep(100);
        ReleaseMutex(hMutex);
    }

    system("pause");

    return 0;
}