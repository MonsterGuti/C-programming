#include <stdio.h>

int main()
{
    float vegetablePrice, fruitPrice;
    int vegetableKg, fruitKg;

    printf("Enter price for vegetables: ");
    scanf_s("%f", &vegetablePrice);

    printf("Enter price for fruits: ");
    scanf_s("%f", &fruitPrice);

    printf("Enter kilograms for vegetables: ");
    scanf_s("%d", &vegetableKg);

    printf("Enter kilograms for fruit: ");
    scanf_s("%d", &fruitKg);

    float vegetableIncome = (vegetablePrice * vegetableKg) / 1.95;
    float fruitIncome = (fruitPrice * fruitKg) / 1.95;

    float totalIncome = vegetableIncome + fruitIncome;
    printf("The total income is: %.2f", totalIncome);

    return 0;
}
