#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 81

char **text = NULL;
int line_count = 0;

void add_line(const char *line) {
    char **new_text = realloc(text, (line_count + 1) * sizeof(char *));
    if (new_text == NULL) {
        printf("Memory allocation error.\n");
        return;
    }
    text = new_text;
    text[line_count] = malloc(strlen(line) + 1);
    if (text[line_count] != NULL) {
        strcpy(text[line_count], line);
        line_count += 1;
    }
}

int is_word_char(char c) {
    return !(c == ' ' || c == '\t' || c == '\0' || c == '.' || c == '!' || c == '?');
}

int count_words() {
    int count = 0;
    int i = 0;
    while (i < line_count) {
        char *p = text[i];
        while (*p != '\0') {
            while (*p != '\0' && !is_word_char(*p)) {
                p += 1;
            }
            if (*p != '\0') {
                count += 1;
            }
            while (*p != '\0' && is_word_char(*p)) {
                p += 1;
            }
        }
        i += 1;
    }
    return count;
}

void align_left(int line_num) {
    if (line_num < 0 || line_num >= line_count) return;
    char buffer[MAX_LINE_LENGTH];
    sscanf(text[line_num], "%[^\n]", buffer);
    char *trimmed = buffer;
    while (isspace(*trimmed)) {
        trimmed += 1;
    }
    strcpy(text[line_num], trimmed);
}

void align_right(int line_num) {
    if (line_num < 0 || line_num >= line_count) return;
    char buffer[MAX_LINE_LENGTH];
    int len = strlen(text[line_num]);
    int space = MAX_LINE_LENGTH - 1 - len;
    if (space < 0) {
        space = 0;
    }
    sprintf(buffer, "%*s", space + len, text[line_num]);
    strcpy(text[line_num], buffer);
}

void reverse_line(int line_num) {
    if (line_num < 0 || line_num >= line_count) return;
    int len = strlen(text[line_num]);
    int i = 0;
    while (i < len / 2) {
        char temp = text[line_num][i];
        text[line_num][i] = text[line_num][len - 1 - i];
        text[line_num][len - 1 - i] = temp;
        i += 1;
    }
}

int count_word_occurrences(const char *word) {
    int count = 0;
    unsigned long len = strlen(word);
    int i = 0;
    while (i < line_count) {
        char *p = text[i];
        while (strstr(p, word) != NULL) {
            p = strstr(p, word);
            if ((p == text[i] || !is_word_char(*(p - 1))) && !is_word_char(p[len])) {
                count += 1;
            }
            p += len;
        }
        i += 1;
    }
    return count;
}

void replace_word(const char *old_word, const char *new_word) {
    int i = 0;
    while (i < line_count) {
        char *pos = strstr(text[i], old_word);
        while (pos != NULL) {
            int old_len = strlen(old_word);
            char buffer[1024];

            int prefix_len = pos - text[i];
            strncpy(buffer, text[i], prefix_len);
            buffer[prefix_len] = '\0';
            strcat(buffer, new_word);
            strcat(buffer, pos + old_len);

            free(text[i]);
            text[i] = malloc(strlen(buffer) + 1);
            if (text[i] != NULL) {
                strcpy(text[i], buffer);
            }

            pos = strstr(text[i], old_word);
        }
        i += 1;
    }
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Enter new line\n");
    printf("2. Count all words\n");
    printf("3. Align line to the left\n");
    printf("4. Align line to the right\n");
    printf("5. Reverse line\n");
    printf("6. Count word occurrences\n");
    printf("7. Replace word\n");
    printf("8. Exit\n");
    printf("Choice: ");
}

int main() {
    int choice;
    char buffer[MAX_LINE_LENGTH];

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); // clear '\n' from input buffer

        if (choice == 1) {
            printf("Enter line: ");
            fgets(buffer, MAX_LINE_LENGTH, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            add_line(buffer);
        } else if (choice == 2) {
            printf("Total word count: %d\n", count_words());
        } else if (choice == 3) {
            int lnum;
            printf("Line number: ");
            scanf("%d", &lnum);
            getchar();
            align_left(lnum);
        } else if (choice == 4) {
            int lnum;
            printf("Line number: ");
            scanf("%d", &lnum);
            getchar();
            align_right(lnum);
        } else if (choice == 5) {
            int lnum;
            printf("Line number: ");
            scanf("%d", &lnum);
            getchar();
            reverse_line(lnum);
        } else if (choice == 6) {
            printf("Word to search: ");
            fgets(buffer, MAX_LINE_LENGTH, stdin);
            buffer[strcspn(buffer, "\n")] = 0;
            printf("Found %d times.\n", count_word_occurrences(buffer));
        } else if (choice == 7) {
            char old_word[50], new_word[50];
            printf("Old word: ");
            fgets(old_word, 50, stdin);
            old_word[strcspn(old_word, "\n")] = 0;
            printf("New word: ");
            fgets(new_word, 50, stdin);
            new_word[strcspn(new_word, "\n")] = 0;
            replace_word(old_word, new_word);
        } else if (choice == 8) {
            int i = 0;
            while (i < line_count) {
                free(text[i]);
                i += 1;
            }
            free(text);
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
