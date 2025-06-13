#include <stdio.h>
#include <string.h>

int firstUniqChar(const char *s)
{
    int freq[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        freq[s[i] - 'a']++;
    }

    for (i = 0; s[i] != '\0'; i++)
    {
        if (freq[s[i] - 'a'] == 1)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    const char *s = "leetcode";
    int index = firstUniqChar(s);
    if (index != -1)
        printf("First unique character is at index: %d\n", index);
    else
        printf("No unique character found.\n");

    return 0;
}
