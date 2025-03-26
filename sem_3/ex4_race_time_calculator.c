#include <stdio.h>

int main() {
    int time1, time2, time3;
    
    scanf("%d", &time1);
    scanf("%d", &time2);
    scanf("%d", &time3);
    
    int total_seconds = time1 + time2 + time3;
    
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;
    
    printf("%d:%02d\n", minutes, seconds);
    
    return 0;
}
