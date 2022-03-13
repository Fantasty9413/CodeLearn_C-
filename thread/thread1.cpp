# include <iostream>
# include <windows.h>

HANDLE hMutex = NULL;       // 互斥量

DWORD WINAPI SubThread_1(LPVOID lpParamter)
{
    for(int i=0; i<10; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);      // 请求一个互斥量锁
        std::cout << "It is in the sub thread: " << "i = " << i << '\n';
        Sleep(100);
        ReleaseMutex(hMutex);       // 释放互斥量锁
    }

    return 0L;      // 表示返回的0是long型的
}

int main()
{
    HANDLE Thread_1 = CreateThread(NULL, 0, SubThread_1, NULL, 0, NULL);
    hMutex = CreateMutex(NULL, FALSE, NULL);
    CloseHandle(Thread_1);

    for(int i=0; i<10; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);      // 请求一个互斥量锁
        std::cout << "It is in the main thread: " << "i = " << i << '\n';
        Sleep(100);
        ReleaseMutex(hMutex);       // 释放互斥量锁
    }

    return 0;
}