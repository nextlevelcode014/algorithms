#include <stdio.h>
#include <string.h>

// Function to reverse a range of characters in a string
void reverse_range(char *s, int start, int end)
{
    while (start < end)
    {
        // Swap characters at start and end indices
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}

void reverse_each_word(char *s)
{
    int i = 0, start = 0;
    int len = strlen(s);

    // Reverse the entire string first
    while (i <= len)
    {
        // When we reach a space or the end of the string, reverse the word
        if (s[i] == ' ' || s[i] == '\0')
        {
            reverse_range(s, start, i - 1);
            start = i + 1;
        }
        i++;
    }
}

int main(void)
{
    char s[] = "Next Level Code";
    reverse_each_word(s);
    printf("%s\n", s); // s'teL ekat edoCteeL tsetnoc
    return 0;
}
