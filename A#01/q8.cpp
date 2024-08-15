// Assignment 01
// Muhammad Azmat
// OOP-B

#include <iostream>
#include <cstring>

using namespace std;

void splitSentence(const string &sentence, char words[][100], int &word_count)
{
    int x = sentence.length();
    int word_index = 0;
    int char_index = 0;

    for (int i = 0; i <= x; ++i)
    {
        if (i == x || sentence[i] == ' ')
        {
            words[word_count][char_index] = '\0';
            ++word_count;
            word_index = 0;
            char_index = 0;
        }
        else
        {
            words[word_count][char_index++] = sentence[i];
        }
    }
}

bool isSubsequence(char words1[][100], int len1, char words2[][100], int len2)
{
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (strcmp(words1[i], words2[j]) == 0) // strcmp to compare the string arguments.
        {
            ++i;
        }
        ++j;
    }
    return i == len1;
}

bool checksimilar(const string &sentence1, const string &sentence2)
{
    char array_1[100][100], array_2[100][100];
    int length1 = 0, length2 = 0;

    splitSentence(sentence1, array_1, length1);
    splitSentence(sentence2, array_2, length2);

    return isSubsequence(array_1, length1, array_2, length2) || isSubsequence(array_2, length2, array_1, length1);
}

int main()
{
    string first_sentence = "My name is Haley";
    string second_sentence = "name";
    bool ans = checksimilar(first_sentence, second_sentence);
    if (ans == true)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
