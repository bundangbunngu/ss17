#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    fflush(stdin);
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // Xóa ký t? xu?ng dòng
}

void inChuoi(char *str) {
    printf("Chuoi vua nhap la: %s\n", str);
}

void demChuCai(char *str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu cai trong chuoi: %d\n", count);
}

void demChuSo(char *str) {
    int count = 0;
    while (*str) {
        if (isdigit(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong chu so trong chuoi: %d\n", count);
}

void demKyTuDacBiet(char *str) {
    int count = 0;
    while (*str) {
        if (!isalnum(*str) && !isspace(*str)) {
            count++;
        }
        str++;
    }
    printf("So luong ky tu dac biet trong chuoi: %d\n", count);
}

int main() {
    char str[100];
    int choice;
    int nhap = 0;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); // Xóa b? nh? d?m sau khi nh?p s?

        switch (choice) {
            case 1:
                nhapChuoi(str);
                nhap = 1;
                break;
            case 2:
                if (nhap)
                    inChuoi(str);
                else
                    printf("Ban chua nhap chuoi!\n");
                break;
            case 3:
                if (nhap)
                    demChuCai(str);
                else
                    printf("Ban chua nhap chuoi!\n");
                break;
            case 4:
                if (nhap)
                    demChuSo(str);
                else
                    printf("Ban chua nhap chuoi!\n");
                break;
            case 5:
                if (nhap)
                    demKyTuDacBiet(str);
                else
                    printf("Ban chua nhap chuoi!\n");
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }
    } while (choice != 6);

    return 0;
}

