#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    
    while (choice != 0) {
        printf("1 Dec To Bin\n");
        printf("2 Bin To Dec\n");
        printf("0 Quit\n");
        
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
        
        if (choice == 1) {
            int dec, rem;
            printf("Enter a decimal number: ");
            scanf("%d", &dec);
            printf("Binary: ");
            
            int binary[32];
            int i = 0;
            
            while (dec > 0) {
                rem = dec % 2;
                binary[i] = rem;
                dec = dec / 2;
                i++;
            }
            
            for (int j = i - 1; j >= 0; j--) {
                printf("%d", binary[j]);
            }
            printf("\n");
        }
        
        if (choice == 2) {
            char bin[32];
            int dec = 0;
            printf("Enter a binary number: ");
            scanf("%s", bin);
            

            for (int i = 0; bin[i] != '\0'; i++) {
                dec = dec * 2 + (bin[i]);
            }
            
            printf("Decimal: %d\n", dec);
        }
    }

    return 0;
}
