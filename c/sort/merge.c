/*归并排序*/
#include <stdlib.h>

void mergeList(int *list1, int n1, int *list2, int n2)
{
    int i, j, k;
    int *list = malloc((n1 + n2) * sizeof(int));

    i = j = k = 0;

    while (i < n1 && j < n2) {
        if(list1[i] < list2[j]) {
            list[k++] = list1[i++];
        } else {
            list[k++] = list2[j++];
        }
    }

    while (i < n1) {
        list[k++] = list1[i++];
    }

    while (j < n2) {
        list[k++] = list2[j++];
    }

    /*把排序好的数组放到list1*/
    for(i = 0; i < (n1 + n2); i++) {
        list1[i] = list[i];
    }

    free(list);
}

void mergeSort(int *L, int n)
{
    if (n > 1) {
        /*把数组从中间分成两个*/
        int *list1 = L;
        int length1 = n / 2;
        int *list2 = L + length1;
        int length2 = n - length1;

        mergeSort(list1, length1);
        mergeSort(list2, length2);
        mergeList(list1, length1, list2, length2);
    }
}
