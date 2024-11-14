#include "load.h"
#include <stdio.h>
#include <windows.h>
#include "PR3_matrix.h"
#include "PR3_array.h"
#define SIZE1 23
#define SIZE2 7
#define SIZE3 5

typedef void (*MaxFindFun)();
typedef void (*MaxFindMatrixFun)();

void LoadRun(const char * const s, int is_matrix)
{
    void *lib;
    lib = LoadLibrary(s); // загрузка библиотеки в память
    if (!lib)
    {
        printf("cannot open library '%s'\n", s);
        return;
    }
    if (!is_matrix)
    {

        MaxFindFun max_find = (MaxFindFun)GetProcAddress((HINSTANCE)lib, "find_max_negative_array");

        if (!max_find)
        {
            printf("Error loading functions from library '%s'\n", s);
            FreeLibrary((HINSTANCE)lib);
            return;
        }
        int arr[SIZE1];
        max_find();
    }
    else
    {

        MaxFindMatrixFun max_find_2 = (MaxFindMatrixFun)GetProcAddress((HINSTANCE)lib, "find_max_negative_matrix");


        if (!max_find_2)
        {
            printf("Error loading functions from library '%s'\n", s);
            FreeLibrary((HINSTANCE)lib);
            return;
        }

        int arr2[SIZE2][SIZE3];
        max_find_2();

    }

    FreeLibrary((HINSTANCE)lib);
}

