#include <stdio.h>
#include <string.h>

int maxSubstringWithAtMostTwoOccurrences(const char* s) {
    int count[26] = {0};  // Contador de ocorrências
    int maxLen = 0;
    int start = 0;
    int n = strlen(s);

    for (int end = 0; end < n; end++) {
        count[s[end] - 'a']++;

        // Enquanto algum caractere aparecer mais de 2 vezes, encolhe a janela
        while (count[s[end] - 'a'] > 2) {
            count[s[start] - 'a']--;
            start++;
        }

        int windowLen = end - start + 1;
        if (windowLen > maxLen) {
            maxLen = windowLen;
        }
    }

    return maxLen;
}

int main(void) {
  char *s = "bcbbbcba";
  int result = maxSubstringWithAtMostTwoOccurrences(s);
  printf("%zu", sizeof(3));
  printf("result: %d", result);
  return 0;
}
