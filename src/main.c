/*
Написать программы, реализующие алгоритмы сортировки
вставками (метод Шелла, сортировка с вычислением адреса).
Сравнить их эффективность (число сравнений и перестановок) для
наилучшего и наихудшего вариантов последовательностей
*/
#include <assert.h> /*asset()*/
#include <malloc.h> /*malloc()*/
#include <stdio.h>  /*printf()*/
#include <string.h> /*memmove()*/

int CompCount, SwapCount;

int SortAscInt(void const * a, void const * b)
{
	int const n = *((int *)a);
	int const m = *((int *)b);
	++CompCount;

	/*Если первый аргумент больше второго -- возврат +1*/
	/*Если второй аргумент больше первого -- возврат -1*/
	/*При равенстве возвращается 0*/
	return (n > m) - (m > n);
}

int SortDescInt(void const * a, void const * b)
{
	int const n = *((int *)a);
	int const m = *((int *)b);
	++CompCount;

	/*Если первый аргумент меньше второго -- возврат +1*/
	/*Если второй аргумент меньше первого -- возврат -1*/
	/*При равенстве возвращается 0*/
	return (n < m) - (m < n);
}

/*Сортировка Шелла. Возврат 1 при ошибке выделения памяти, 0 при успехе*/
static int ShellSort(void * const p,
		     size_t const nmemb,
		     size_t const size,
		     int (*compar)(void const *, void const *))
{
	/* Начальный промежуток -- половина массива,
	 * каждый шаг промежуток уменьшается в 2 раза */
	for (size_t gap = nmemb / 2; gap > 0; gap /= 2) {
		for (size_t i = gap; i < nmemb; ++i) {
			/*Сохранение i-го элемента в буфер*/
			void * temp = malloc(size);
			if (!temp)
				return 1;
			memcpy(temp, p + i * size, size);

			size_t j;
			for (j = i;
			     j >= gap && compar(p + (j - gap) * size, temp) > 0;
			     j -= gap) {
				memmove(p + j * size, p + (j - gap) * size,
					size);
				++SwapCount;
			}

			/*Устновка элемента temp (i-го) в нужное место*/
			if (p + j * size != p + i * size)
				++SwapCount;
			memmove(p + j * size, temp, size);
			free(temp);
		}
	}
	return 0;
}

void PrintArr(int * arr, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	putchar('\n');
}

int main()
{
	int nn[] = {1, 9, 0, -1, -3, 4, -3, 1};
	PrintArr(nn, 8);
	if (ShellSort(nn, 8, 4, SortDescInt))
		return 1;

	PrintArr(nn, 8);
	printf("%d сравнений, %d перестановок\n", CompCount, SwapCount);
	return 0;
}
