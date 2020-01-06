#include "words.h"
using namespace std;

void reverse(const char *str1, char *str2) {
    int str_len = strlen(str1);
    for (int i = 1; i <= str_len; ++i)
        str2[str_len-i] = str1[i-1];

    str2[str_len] = '\0';
}

int compare(const char *str1, const char *str2) {
    int i1 = 0, i2 = 0;

    while (str1[i1] != '\0' && !isalpha(str1[i1]))
        ++i1;

    while (str2[i2] != '\0' && !isalpha(str2[i2]))
        ++i2;
    
    if (str1[i1] == '\0' && str2[i2] == '\0')
        return 1;

    if (toupper(str1[i1]) != toupper(str2[i2]))
        return 0;

    return compare(str1+i1+1, str2+i2+1);
}

int palindrome(const char *sentence) {
    char rev_sentence[strlen(sentence)];
    reverse(sentence, rev_sentence);
    return compare(sentence, rev_sentence);
}

int anagram(const char *str1, const char *str2) {
    char sorted_str1[strlen(str1)];
    char sorted_str2[strlen(str2)];
    sort(str1, sorted_str1);
    sort(str2, sorted_str2);

    return compare(sorted_str1, sorted_str2);
}

void sort(const char *str, char *sorted_str) {
    strcpy(sorted_str, str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (toupper(sorted_str[j]) < toupper(sorted_str[i])) {
                char temp = sorted_str[j];
                sorted_str[j] = sorted_str[i];
                sorted_str[i] = temp;
            }
        }
    }
}