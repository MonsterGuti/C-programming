#include <stdio.h>
 
double calculateEarnings(int days_per_month, double dollars_per_day, double dollar_to_lev_rate) {
    double monthly_salary = days_per_month * dollars_per_day;
    double annual_salary = (monthly_salary * 12) + (monthly_salary * 2.5);
    double after_tax = annual_salary * 0.75;
    double annual_leva = after_tax * dollar_to_lev_rate;
    double daily_leva = annual_leva / 365;
 
    printf("\nIvan's earnings:\n");
    printf("Monthly salary: $%.2f\n", monthly_salary);
    printf("Annual salary with bonus: $%.2f\n", annual_salary);
    printf("After tax: $%.2f\n", after_tax);
    printf("Annual earnings in leva: %.2f BGN\n", annual_leva);
 
    return daily_leva;
}
 
int main() {
    int days_per_month;
    double dollars_per_day;
    double dollar_to_lev_rate;
 
    printf("Enter the number of days Ivan works per month: ");
    scanf("%d", &days_per_month);
 
    printf("Enter the amount in dollars Ivan earns per day: ");
    scanf("%lf", &dollars_per_day);
 
    printf("Enter the dollar to lev exchange rate: ");
    scanf("%lf", &dollar_to_lev_rate);
 
    double daily_leva = calculateEarnings(days_per_month, dollars_per_day, dollar_to_lev_rate);
    printf("Average daily earnings in leva: %.2f BGN\n", daily_leva);
 
    return 0;
}