#include "f.h"

int main() 
{
    setlocale(LC_ALL, "RUS");
    srand(time(NULL));

    double* array = NULL;
    int size;
    bool exitProgram = false;

    while (!exitProgram) {
        printf("������� ���������� ��������� �������: ");
        scanf("%d", &size);

        printf("�������� ������ ���������� �������:\n");
        printf("1. �������\n");
        printf("2. �������� (1-100)\n");
        printf("3. �������� � ������� ������\n");
        int fillChoice;
        scanf("%d", &fillChoice);

        if (array != NULL) {
            free(array);
        }
        array = arrayAllocat(size);

        switch (fillChoice) {
        case 1:
            arrayFillUser(array, size);
            break;
        case 2:
            arrayFillRand(array, size);
            break;
        case 3:
            arrayFillRandomInRange(array, size);
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
            continue;
        }

        printf("�������� ������ ����������:\n");
        printf("1. Bubble Sort\n");
        printf("2. Mod Bubble Sort\n");
        printf("3. Merge Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Selection Sort\n");
        printf("6. Quick Sort\n");
        int sortChoice;
        scanf("%d", &sortChoice);

        printf("��������� ������:\n");
        printf("1. �������� �������� ����������\n");
        printf("2. �������� ������ ���������\n");
        printf("3. �������� ���������, ���������� �������� � ����� ����������\n");
        int outputChoice;
        scanf("%d", &outputChoice);

        // ����� ������� ��� ���������� �������� ������
        double* originalArray = arrayAllocat(size);
        for (int i = 0; i < size; i++) {
            originalArray[i] = array[i];
        }

        // ���������� ����������
        clock_t start = clock();
        int iterations = 0;

        switch (sortChoice) {
        case 1:
            bubbleSort(array, size);
            break;
        case 2:
            modbubbleSort(array, size);
            break;
        case 3:
            mergeSort(array, 0, size - 1);
            break;
        case 4:
            insertSort(array, size);
            break;
        case 5:
            selectionSort(array, size);
            break;
        case 6:
            quickSort(array, 0, size - 1);
            break;
        default:
            printf("�������� �����. ���������� �����.\n");
            free(originalArray);
            continue;
        }

        clock_t end = clock();
        double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;

        if (outputChoice == 1) {
            printf(".......\n");
        }
        else if (outputChoice == 2) {
            printf("��������������� ������: ");
            arrayPrint(array, size);
        }
        else if (outputChoice == 3) {
            printf("��������������� ������: ");
            arrayPrint(array, size);
            printf("����� ����������: %.6f ������\n", timeSpent);
        }

        // ���������� ��������
        printf("������ ����������?\n");
        printf("1. ���������� � ������� �������� (�� ����������)\n");
        printf("2. ������� ����� ������\n");
        printf("3. �����\n");
        int nextChoice;
        scanf("%d", &nextChoice);

        if (nextChoice == 1) {
            // ������� � ��������� �������
            for (int i = 0; i < size; i++) {
                array[i] = originalArray[i];
            }
        }
        else if (nextChoice == 2) {
            free(array);
            array = NULL;
        }
        else if (nextChoice == 3) {
            exitProgram = true;
        }

        free(originalArray);
    }

    if (array != NULL) {
        free(array);
    }
    printf("��������� ���������.\n");
    return 0;
}