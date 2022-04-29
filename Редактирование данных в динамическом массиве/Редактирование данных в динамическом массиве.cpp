#include <iostream>
#include<ctime>

using namespace std;

const char TAB = '\t';
const char NEW_LINE = '\n';

void CreateDynamicMemory(int*&, const int);
void AddDataInArray(int* const, const int);
void ShowArray(const int* const, const int);
void push_back(int*&, int&, const int);
void pop_back(int*&, int&, const int);
void DeleteValueFromArray(int*&, int&, const int); // удаляет первый равный передаваемому элементу из массива, если он там есть
void DeleteDMemory(int*);

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int size1, size2;
    char exit = '0';

    int* arr1 = nullptr;
    int* arr2 = nullptr;

    cout << "Введите размер первого массива: ";
    cin >> size1;
    CreateDynamicMemory(arr1, size1);
    AddDataInArray(arr1, size1);

    cout << "Введите размер второго массива: ";
    cin >> size2;
    CreateDynamicMemory(arr2, size2);
    AddDataInArray(arr2, size2);

    ShowArray(arr1, size1);
    ShowArray(arr2, size2);

    int value, num;
    do {
        int add;
        cout << "0 - добавление элемента в начало массива, 1 - добавление элемента в конец массива, 2 - удаление элемента из массива: ";
        cin >> add;
        switch (add) {
        case 0:
            cout << "Введите число и номер массива, куда добавляем значение: ";

            cin >> value >> num;
            switch (num) {
            case 1:
                pop_back(arr1, size1, value);
                break;
            case 2:
                pop_back(arr2, size2, value);
                break;
            default:
                cout << "Введены не корректные значения!" << endl;
                exit = 1;
                goto r_exit;
                break;
            }
            break;
        case 1:
            cout << "Введите число и номер массива, куда добавляем значение: ";

            cin >> value >> num;
            switch (num) {
            case 1:
                push_back(arr1, size1, value);
                break;
            case 2:
                push_back(arr2, size2, value);
                break;
            default:
                cout << "Введены не корректные значения!" << endl;
                exit = 1;
                goto r_exit;
                break;
            }
            break;
        case 2:
            cout << "Введите число и номер массива, откуда удаляем значение: ";

            cin >> value >> num;
            switch (num) {
            case 1:
                DeleteValueFromArray(arr1, size1, value);
                break;
            case 2:
                DeleteValueFromArray(arr2, size2, value);
                break;
            default:
                cout << "Введены не корректные значения!" << endl;
                exit = 1;
                goto r_exit;
                break;
            }
            break;
            break;
        default:
            cout << "Введено некорректное значение" << endl;
            exit = '1';
            goto r_exit;
            break;
        }

        cout << "Новые массивы:" << endl;
        ShowArray(arr1, size1);
        ShowArray(arr2, size2);

        cout << "Нажмите 0 - для продолжения, любую другую клавишу для выхода: ";
        cin >> exit;
    r_exit:
        cout << "" << endl;
    } while (exit == '0');


    DeleteDMemory(arr1);
    DeleteDMemory(arr2);


}

void DeleteValueFromArray(int*& arr, int& size, const int value)
{
    int count = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value) 
        {
            count = i;
            break;
        }
    }

    if (count != -1) 
    {
        size--;
        int* arrn = new int[size];
        int num_elem = 0; // номер для перебора динамического массива нового
        for (int i = 0; i < size + 1; i++)
        {
            if (i == count) {
                continue;
            }
            arrn[num_elem] = arr[i];
            num_elem++;
        }

        DeleteDMemory(arr);
        arr = arrn;
    }
    else {
        cout << "Данного элемента " << value << " нет в массиве" << endl;
    }
}

void push_back(int*& arr, int &size, const int value)
{
    size++;
    int* arrn = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
        *(arrn + i) = *(arr + i);
    }

    arrn[size-1] = value;
    delete[] arr;
    arr = nullptr;

    arr = arrn;
}

void pop_back(int*& arr, int& size, const int value)
{
    size++;
    int* arrn = new int[size];
    *arrn = value;
    for (int i = 1; i < size; i++)
    {
        *(arrn + i) = *(arr + i - 1);
    }
    DeleteDMemory(arr);
    arr = arrn;
}

void CreateDynamicMemory(int*& arr, const int size)
{
    DeleteDMemory(arr);
    int* arrn = new int[size];
    arr = arrn;
}

void AddDataInArray(int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 10;
    }
}

void ShowArray(const int* const arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr+i) << TAB;
    }
    cout << NEW_LINE;
}

void DeleteDMemory(int* arr)
{
    delete[] arr;
    arr = nullptr;
}