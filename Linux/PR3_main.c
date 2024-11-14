#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <windows.h>
#define SIZE1 2
#define SIZE2 5
#include <time.h>
#include "PR3_array.h"
#include "PR3_matrix.h"
#include "load.h"
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int a[SIZE2], b[SIZE1][SIZE2];

    int x=0,y=1, type=0;
    printf("Choose library:\n1-library of arrays.\n2-library of matrix,\n3-quit\n");
    while(y)
    {
        scanf("%d",&x);
        if(x==1)
            LoadRun("lib1.dll",0);
        if(x==2)
            LoadRun("lib2.dll",1);
        if(x==3)
            y=0;
    }
    return 0;
}
