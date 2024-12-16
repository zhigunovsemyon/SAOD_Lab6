/*
Написать программы, реализующие алгоритмы сортировки
вставками (метод Шелла, сортировка с вычислением адреса).
Сравнить их эффективность (число сравнений и перестановок) для
наилучшего и наихудшего вариантов последовательностей
*/
#include <stdio.h>
#include <stdlib.h>

int SortAscInt(void * a, void * b) 
{
	int const n = *((int *)a);
	int const m = *((int *)b);

	/*Если первый аргумент больше второго -- возврат +1*/
	/*Если второй аргумент больше первого -- возврат -1*/
	/*При равенстве возвращается 0*/
	return (n > m) - (m > n);
}

int SortDescInt(void * a, void * b)
{
	int const n = *((int *)a);
	int const m = *((int *)b);

	/*Если первый аргумент меньше второго -- возврат +1*/
	/*Если второй аргумент меньше первого -- возврат -1*/
	/*При равенстве возвращается 0*/
	return (n < m) - (m < n);
}

//static void ShellSort(void * const p,
//		      size_t const size,
//		      size_t nmemb,
//		      int (*compar)(void * const, void * const))
//{
//}

int main()
{
	int nn[] = {1, 9, 0, -1, -3, 4, -3, 1};
	qsort((void *)nn, 8, 4, (_CoreCrtNonSecureSearchSortCompareFunction)SortAscInt);
	printf("Hello World!\n");
	return 0;
}
