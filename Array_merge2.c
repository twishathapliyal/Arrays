#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void merge(int a1[], int n, int a2[], int m) {
    int i = n - 1;
    int j = m - 1;
    int k = n + m - 1;

    while(i >= 0 && j >= 0) {
        if(a1[i] > a2[j])
            a1[k--] = a1[i--];
        else
            a1[k--] = a2[j--];
    }

    while(j >= 0)
        a1[k--] = a2[j--];
    
    while(i >= 0)
        a1[k--] = a1[i--];
}
//void merge_no_duplicates()
int main() {
    int n, m;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n);
    printf("Enter number of elements in second array: ");
    scanf("%d", &m);

    int* a1 = (int*)malloc((n + m) * sizeof(int));
    printf("Enter elements of first array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a1[i]);

    printf("First array: ");
    display(a1, n);

    int* a2 = (int*)malloc(m * sizeof(int));
    printf("Enter elements of second array: ");
    for(int i = 0; i < m; i++)
        scanf("%d", &a2[i]);

    printf("Second array: ");
    display(a2, m);

    merge(a1, n, a2, m);

    printf("Merged array: ");
    display(a1, n + m);

    free(a1);
    free(a2);
}

