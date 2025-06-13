#include <stdio.h>
#include <string.h>

int maxSubstringWithAtMostTwoOccurrences(const char *s)
{
    int count[26] = {0};
    int maxLen = 0;
    int left = 0;
    int slen = strlen(s);

    for (int right = 0; right < slen; right++)
    {
        count[s[right] - 'a']++;

        while (count[s[right] - 'a'] > 2)
        {
            count[s[left] - 'a']--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen)
        {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

int main(void)
{
    char *s = "babaacf";
    int result = maxSubstringWithAtMostTwoOccurrences(s);
    printf("result: %d", result);
    return 0;
}
