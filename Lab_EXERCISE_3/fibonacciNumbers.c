#include <stdio.h>

int main() {
    int n, a = 0, b = 1, c;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d \n", a);
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
