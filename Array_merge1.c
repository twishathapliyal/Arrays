#include <stdio.h>
#include <stdlib.h>

int* create(int n) {
    int* a = (int*)malloc(n * sizeof(int));

    printf("Enter the elements in the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    return a;
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void merge(int a1[], int n, int a2[], int m, int a3[]) {
    int i = 0, j = 0, k = 0;

    while(i < n && j < m) {
        if(a1[i] < a2[j]) {
            a3[k++] = a1[i++];
        } else {
            a3[k++] = a2[j++];
        }
    }

    while(i < n) {
        a3[k++] = a1[i++];
    }

    while(j < m) {
        a3[k++] = a2[j++];
    }
}

int main() {
    int n, m;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n);
    int* a1 = create(n);

    printf("First array: ");
    display(a1, n);

    printf("Enter number of elements in second array: ");
    scanf("%d", &m);
    int* a2 = create(m);

    printf("Second array: ");
    display(a2, m);

    int* a3 = (int*)malloc((n + m) * sizeof(int));

    merge(a1, n, a2, m, a3);

    printf("Merged array: ");
    display(a3, n + m);

    free(a1);
    free(a2);
    free(a3);
}
