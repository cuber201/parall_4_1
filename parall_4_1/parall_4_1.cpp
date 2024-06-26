﻿// parall_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;


int main()
{
    int N;
    double sum = 0;
    cout << "Input count tread (N): ";
    cin >> N;
    int k = rand() % 100 + 1;
    vector<double> randmass(k);
    for (int i = 0; i < k; i++) {
        randmass[i] = rand() % 10;
    }
   
#pragma omp parallel num_threads(N)  reduction(+:sum)
    {
        int temp = 0;
        int id = omp_get_thread_num();
        for (int i = id + 1; i < k; i += N) {
            temp += randmass[i];
        }

#pragma omp critical
        {
            cout << "[" << id << "]: Sum = " << temp << endl;
            sum += temp;
        }
    }
    cout << "Sum = " << sum << endl;
    return 0;
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
