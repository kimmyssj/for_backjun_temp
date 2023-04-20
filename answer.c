#include <stdio.h>
#include <stdlib.h>

/*
	가장 빠른 병합정렬을 채택해야 뚫을 수 있는 과제인 모양이다.
	일단 계획은 아래와 같다.
	1. 인자 뗴오기. n
	2. 각각 다른 인자 종류를 집어넣고 그 갯수들을 떼 온 배열을 만들기. n
	3. 그 배열을 nlogn으로 가장 빠른 merge sort를 구현해서 정렬해내기. nlogn
	4. 그 배열의 순서에 따라 순서에 따라 함수 압축을 구현하기. n
	5. 출력. n

	그러면 총 알고리즘의 시간복잡도는...
	대충 계산해보면 3n + nlogn이라 우수리 떼면 nlogn이 되지 않을까?

	merge sort를 구현하기 위한 단계.
	1. 배열을 각각 반으로 쪼개기.
	2. 각각의 크기가 1이 될 때 까지 반복...
	3. 쪼갠 것을 두 배열 씩 비교해가며 합치기.
	4. 배열이 다 합쳐질 떄 까지 반복...

	이걸 array로 구현할 생각을 하니 정신이 아득해져서 linked list로 구현하기로 했다.
	생각해보니 linked list가 훨씬 정신이 아득하다 ㅋㅋ
	array와 재귀함수로 구현할 생각이다.
*/

int	check_dup(int *indexed_coor, int numb, int idx)
{
	int	idx1;

	idx1 = 0;
	while (idx1 < idx)
	{
		if (indexed_coor[idx1] == numb)
		{
			return (0);
		}
		idx1 ++;
	}
	return (1);
}

void	split_to_half(int *arr, int **a, int **b, int number_of_sort)
{
	int	*arr;
	int	*a1;
	int	*b1;

	split_to_half(a, &a1, &b1,  number_of_sort / 2);
}

int	*merge_sort(int **arr, int number_of_sort)
{
	int	*a;
	int	*b;
	int	*answer;

	split_to_half(*arr, &a, &b, number_of_sort); // 쪼개기
	answer = combine_together(&a, &b); // 합치기
	free(a);
	free(b);
	free(*arr);
	return (answer);
}

int	main(void)
{
	int	number_of_arg;
	int	*coordinate;
	int	*indexed_coor;
	int	*sorted_arr;
	int	idx;

	scanf("%d", &number_of_arg);
	coordinate = malloc(sizeof(int) * number_of_arg);
	indexed_coor = malloc(sizeof(int) * number_of_arg);
	sorted_arr = malloc(sizeof(int) * number_of_arg);

	int	number_of_sort;
	t_node *node;
	t_node *start;

	idx = 0;
	number_of_sort = 0;
	while (idx < number_of_arg)
	{
		scanf("%d", coordinate + idx);
		if (check_dup(indexed_coor, coordinate[idx], number_of_sort) == 1)
		{
			sorted_arr[number_of_sort] = coordinate[idx];
			number_of_sort ++;
		}
		idx ++;
	}

	sorted_arr = merge_sort(&sorted_arr);
	idx = 0;
	while (idx < number_of_arg)
	{
		printf("%d", indexed_coor[idx]);
		idx ++;
		if (idx != number_of_arg)
			printf(" ");
	}
	free(indexed_coor);
	free(coordinate);
	free(num);
}
