#include <stdio.h>
#include <string.h>

void reverse_range(char *s, int start, int end) {
    while (start < end) {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void reverse_each_word(char *s) {
    int i = 0, start = 0;
    int len = strlen(s);

    while (i <= len) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverse_range(s, start, i - 1);
            start = i + 1;
        }
        i++;
    }
}

int main(void) {
    char s[] = "Let's take LeetCode contest";
    reverse_each_word(s);
    printf("%s\n", s); // s'teL ekat edoCteeL tsetnoc
    return 0;
}

