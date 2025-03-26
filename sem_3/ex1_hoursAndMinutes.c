#include <stdio.h>

int main() {
    int hour, minutes;
    scanf("%d %d", &hour, &minutes);

    int myHour = hour;
    int myMinutes = minutes + 15;

    if (myMinutes >= 60) {
        myHour += 1;
        myMinutes -= 60;
    }

    if (myHour >= 24) {
        myHour = 0;
    }

    printf("%02d:%02d\n", myHour, myMinutes);

    return 0;
}
