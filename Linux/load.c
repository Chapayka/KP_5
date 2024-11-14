#include "load.h"
#include <stdio.h>
#include <dlfcn.h> // «аголовок дл€ работы с dlopen, dlsym, dlclose
#include "PR3_matrix.h"
#include "PR3_array.h"

#define SIZE1 23
#define SIZE2 7
#define SIZE3 5

typedef void (*MaxFindFun)();
typedef void (*MaxFindMatrixFun)();

void LoadRun(const char * const s, int is_matrix)
{
    void *lib = dlopen(s, RTLD_LAZY); // загрузка библиотеки в пам€ть
    if (!lib)
    {
        printf("cannot open library '%s': %s\n", s, dlerror());
        return;
    }

    if (!is_matrix)
    {
        MaxFindFun max_find = (MaxFindFun)dlsym(lib, "find_max_negative_array");

        if (!max_find)
        {
            printf("Error loading function 'find_max_negative_array' from library '%s': %s\n", s, dlerror());
            dlclose(lib);
            return;
        }

        int arr[SIZE1];
        max_find();
    }
    else
    {
        MaxFindMatrixFun max_find_2 = (MaxFindMatrixFun)dlsym(lib, "find_max_negative_matrix");

        if (!max_find_2)
        {
            printf("Error loading function 'find_max_negative_matrix' from library '%s': %s\n", s, dlerror());
            dlclose(lib);
            return;
        }

        int arr2[SIZE2][SIZE3];
        max_find_2();
    }

    dlclose(lib);
}
