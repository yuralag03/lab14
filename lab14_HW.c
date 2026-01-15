#define _CRT_SECURE_NO_DEPRECATE
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 50

double find_max_on_positions(double* ptr_array, int n, int type);

int main() {
    setlocale(LC_ALL, "");
    double array[N];
    int size;

    printf("ЗАДАНИЕ 3: ФУНКЦИЯ ОБРАБОТКИ МАССИВА\n");
    printf("Вариант 10: Максимальное значение на четных/нечетных позициях\n");
    printf("================================================================\n\n");

    printf("Введите размер массива (1-%d): ", N);
    scanf("%d", &size);

    if (size < 1 || size > N) {
        printf("Ошибка: размер должен быть от 1 до %d\n", N);
        return 1;
    }

    printf("\nВыберите способ заполнения массива:\n");
    printf("1 - Автоматически (случайные числа)\n");
    printf("2 - Вручную\n");
    printf("Ваш выбор: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        srand(time(NULL));
        printf("\nЗаполнение массива случайными числами в диапазоне [-50, 50]...\n");

        for (int i = 0; i < size; i++) {
            array[i] = -50.0 + 100.0 * (rand() / (double)RAND_MAX);
        }
    }
    else {
        printf("\nВведите %d элементов массива:\n", size);
        for (int i = 0; i < size; i++) {
            printf("array[%d] = ", i);
            scanf("%lf", &array[i]);
        }
    }

    printf("\nСОДЕРЖАНИЕ МАССИВА:\n");
    printf("+---------+------------------+------------------+\n");
    printf("| Индекс  |    Значение      |      Тип         |\n");
    printf("+---------+------------------+------------------+\n");

    for (int i = 0; i < size; i++) {
        printf("| %7d | %16.6f |", i, array[i]);

        if (i % 2 == 0) {
            printf("  Четная позиция  |\n");
        }
        else {
            printf("  Нечетная позиция |\n");
        }
    }
    printf("+---------+------------------+------------------+\n");

    printf("\n\n1. ПОИСК МАКСИМАЛЬНОГО ЗНАЧЕНИЯ НА ЧЕТНЫХ ПОЗИЦИЯХ:\n");
    printf("   (индексы: 0, 2, 4, ...)\n");
    printf("   -------------------------------------------------\n");

    double max_even = find_max_on_positions(array, size, 0);

    printf("   Элементы на четных позициях:\n");
    int even_count = 0;
    for (int i = 0; i < size; i += 2) {
        printf("   array[%d] = %10.6f", i, array[i]);
        if (fabs(array[i] - max_even) < 0.000001) {
            printf("  <- МАКСИМУМ");
        }
        printf("\n");
        even_count++;
    }
    printf("   Всего элементов на четных позициях: %d\n", even_count);
    printf("   Максимальное значение: %10.6f\n", max_even);

    printf("\n\n2. ПОИСК МАКСИМАЛЬНОГО ЗНАЧЕНИЯ НА НЕЧЕТНЫХ ПОЗИЦИЯХ:\n");
    printf("   (индексы: 1, 3, 5, ...)\n");
    printf("   ---------------------------------------------------\n");

    double max_odd = find_max_on_positions(array, size, 1);

    printf("   Элементы на нечетных позициях:\n");
    int odd_count = 0;
    for (int i = 1; i < size; i += 2) {
        printf("   array[%d] = %10.6f", i, array[i]);
        if (fabs(array[i] - max_odd) < 0.000001) {
            printf("  <- МАКСИМУМ");
        }
        printf("\n");
        odd_count++;
    }
    printf("   Всего элементов на нечетных позициях: %d\n", odd_count);
    printf("   Максимальное значение: %10.6f\n", max_odd);

    printf("\n\n3. СРАВНЕНИЕ РЕЗУЛЬТАТОВ:\n");
    printf("   ---------------------\n");

    printf("   Общие данные:\n");
    printf("   * Размер массива: %d элементов\n", size);
    printf("   * Элементов на четных позициях: %d\n", even_count);
    printf("   * Элементов на нечетных позициях: %d\n", odd_count);
    printf("   * Максимум на четных позициях: %10.6f\n", max_even);
    printf("   * Максимум на нечетных позициях: %10.6f\n", max_odd);

    if (max_even > max_odd) {
        printf("   * Вывод: Максимальное значение на ЧЕТНЫХ позициях больше\n");
        printf("     Разница: %10.6f\n", max_even - max_odd);
    }
    else if (max_even < max_odd) {
        printf("   * Вывод: Максимальное значение на НЕЧЕТНЫХ позициях больше\n");
        printf("     Разница: %10.6f\n", max_odd - max_even);
    }
    else {
        printf("   * Вывод: Максимальные значения РАВНЫ\n");
    }

    printf("\n\n4. ДОПОЛНИТЕЛЬНЫЙ АНАЛИЗ:\n");
    printf("   --------------------\n");

    double overall_max = array[0];
    int overall_max_index = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] > overall_max) {
            overall_max = array[i];
            overall_max_index = i;
        }
    }

    printf("   Общий максимум во всем массиве: %10.6f\n", overall_max);
    printf("   Индекс общего максимума: %d\n", overall_max_index);
    printf("   Общий максимум находится на %s позиции\n",
        (overall_max_index % 2 == 0) ? "четной" : "нечетной");

    if (overall_max_index % 2 == 0) {
        if (fabs(overall_max - max_even) < 0.000001) {
            printf("   + Общий максимум совпадает с максимумом на четных позициях\n");
        }
        else {
            printf("   - Ошибка: общий максимум не совпадает с максимумом на четных позициях\n");
        }
    }
    else {
        if (fabs(overall_max - max_odd) < 0.000001) {
            printf("   + Общий максимум совпадает с максимумом на нечетных позициях\n");
        }
        else {
            printf("   - Ошибка: общий максимум не совпадает с максимумом на нечетных позициях\n");
        }
    }

    printf("\n\n5. ТЕСТИРОВАНИЕ ФУНКЦИИ:\n");
    printf("   -------------------\n");

    printf("   Тест 1: type = 0 (четные позиции) -> %.6f\n",
        find_max_on_positions(array, size, 0));
    printf("   Тест 2: type = 1 (нечетные позиции) -> %.6f\n",
        find_max_on_positions(array, size, 1));
    printf("   Тест 3: type = 2 (некорректный) -> %.6f\n",
        find_max_on_positions(array, size, 2));
    printf("   Тест 4: type = -1 (некорректный) -> %.6f\n",
        find_max_on_positions(array, size, -1));

    printf("\n\n6. ЗАКЛЮЧЕНИЕ:\n");
    printf("   -----------\n");
    printf("   Функция find_max_on_positions() успешно определила:\n");
    printf("   * Максимальное значение на четных позициях: %.6f\n", max_even);
    printf("   * Максимальное значение на нечетных позициях: %.6f\n", max_odd);

    return 0;
}

double find_max_on_positions(double* ptr_array, int n, int type) {

    if (n <= 0) {
        printf("Ошибка: массив пустой\n");
        return 0.0;
    }

    if (ptr_array == NULL) {
        printf("Ошибка: нулевой указатель на массив\n");
        return 0.0;
    }

    int start_index;

    if (type == 0) {

        start_index = 0;
    }
    else if (type == 1) {

        start_index = 1;
    }
    else {

        printf("Предупреждение: некорректный type=%d, используется type=1\n", type);
        start_index = 1;
    }

    if (start_index >= n) {
        printf("Предупреждение: нет элементов на указанных позициях\n");
        return 0.0;
    }
    double max_value = ptr_array[start_index];

    for (int i = start_index; i < n; i += 2) {
        if (ptr_array[i] > max_value) {
            max_value = ptr_array[i];
        }
    }

    return max_value;
}