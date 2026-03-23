#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];#include <stdio.h>

int main() {

    int at[5]  = {0,0,0,0,0};
    int bt1[5] = {5,7,6,8,5};
    int io[5]  = {2,2,3,1,2};
    int bt2[5] = {3,2,4,2,5};

    int pct[5], ct[5];
    int i;

    // ----- PCT -----
    pct[0] = at[0]+bt1[0] + io[0];

    for(i = 1; i < 5; i++) {
        pct[i] = pct[i-1] + bt1[i] + io[i];
    }

    // ----- CT -----
    ct[0] = pct[0] + bt2[0];

    for(i = 1; i < 5; i++) {

        if(ct[i-1] > pct[i])
            ct[i] = ct[i-1] + bt2[i];
        else
            ct[i] = pct[i] + bt2[i];
    }

    printf("PN\tAT\tBT1\tIO\tBT2\tPCT1\tCT\n");

    for(i = 0; i < 5; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt1[i], io[i], bt2[i], pct[i], ct[i]);
    }

    return 0;
}
    i = 0; 
    j = 0; 
    k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
