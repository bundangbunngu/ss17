#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int *size) {
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", size);

    *arr = (int *)malloc((*size) * sizeof(int));

    for (int i = 0; i < *size; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", (*arr) + i);
    }
}

void hienThiMang(int *arr, int size) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void tinhDoDaiMang(int size) {
    printf("Do dai cua mang la: %d\n", size);
}

void tinhTongMang(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    printf("Tong cac phan tu trong mang la: %d\n", sum);
}

void timMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapMang(&arr, &size);
                break;
            case 2:
                if (arr != NULL) {
                    hienThiMang(arr, size);
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 3:
                tinhDoDaiMang(size);
                break;
            case 4:
                if (arr != NULL) {
                    tinhTongMang(arr, size);
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 5:
                if (arr != NULL) {
                    timMax(arr, size);
                } else {
                    printf("Mang chua duoc nhap!\n");
                }
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai.\n");
        }
    } while (choice != 6);

    free(arr); 
    return 0;
}

