#include "Header.h"

main() {
	system("chcp 1251 >null");
	LOS* los = NewLOS(10);
	Add(los, 51);
	Show(los);
	Delete(los, 3);
	Show(los);
	los = Swap(los, 1, 5);
	Show(los);
	FreeLOS(los);
}

LOS* NewLOS(size_t n) {
	LOS* los = calloc(1, sizeof(LOS));
	los->i = 0;
	los->next = NULL;
	LOS* headCopy,*next;
	headCopy = los;
	for (size_t i = 0; i < n-1; i++)
	{
		next = calloc(1, sizeof(LOS));
		next->i = headCopy->i + 1;
		headCopy->next = next;
		headCopy = next;
	}
	headCopy->next = NULL;
	return los;
}

void Delete(LOS* los, size_t i) {
	for (size_t n = 0; n < i-1; n++)
	{
		los = los->next;
	}
	LOS* copy = los;
	los = los->next;
	copy->next = los->next;
	free(los);
}

void Add(LOS* los, size_t i) {
	while (los->next != NULL)
	{
		los = los->next;
	}
	LOS* next = calloc(1, sizeof(LOS));
	next->i = i;
	next->next = NULL;
	los->next = next;

}

LOS* Swap(LOS* los, size_t i, size_t m) {
	LOS* min = los;
	LOS* max = los;
	LOS* _max = los;
	if (i != 0) {
		for (size_t n = 0; n < i - 1; n++)
		{
			min = min->next;
		}
		for (size_t n = 0; n < m - 1; n++)
		{
			_max = _max->next;
		}
		LOS* l2 = _max->next;
		max = l2->next;
		LOS* l1 = min->next;
		min->next = l2;
		_max->next = l1;
		l2->next = l1->next;
		l1->next = max;
		return los;
	}
	else {
		for (size_t n = 0; n < m - 1; n++)
		{
			_max = _max->next;
		}
		LOS* l2 = _max->next;
		max = l2->next;
		LOS* l1 = min->next;
		l2->next = l1;
		_max->next = min;
		min->next = max;
		return l2;
	}
}

void FreeLOS(LOS* los) {
	LOS* copy = los;
	while (copy)
	{
		copy = los->next;
		free(los);
		los = copy;
	}
}

void Show(LOS* los) {
	if (los == NULL) {
		printf("?????? ?? ??????????\n");
		return;
	}

	while (los)
	{
		printf("%d ", los->i);
		los = los->next;
	}
	printf("\n");
}
