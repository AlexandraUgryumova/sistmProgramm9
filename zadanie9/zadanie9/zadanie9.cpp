// zadanie9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
using namespace std;

DWORD WINAPI analyzeTime1(LPVOID lpParam) {

    cout << "Анализ временных рядов в потоке 1\n";
    return 0;
}

DWORD WINAPI analyzeTime2(LPVOID lpParam) {

    cout << "Анализ временных рядов в потоке 2\n";
    return 0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    //int inc = 10;

    HANDLE thread1;
    DWORD IDThread; 
    thread1 = CreateThread(NULL, 0, analyzeTime1, NULL, 0, &IDThread);
    if (thread1 == NULL)
        return GetLastError();

    WaitForSingleObject(thread1, INFINITE);
    CloseHandle(thread1);

    HANDLE thread2;
    DWORD IDThread2; 
    thread2 = CreateThread(NULL, 0, analyzeTime2, NULL, 0, &IDThread2);

    if (thread2 == NULL)
        return GetLastError();

    WaitForSingleObject(thread2, INFINITE);
    CloseHandle(thread2);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
