#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(string letters);
int count_words(string words);
int count_sentences(string sentences);
int grade_index(int letters,int words, int sentences);

int main(void)
{

    string text= get_string("Text: ");
    // printf(" Letters: %i",count_letter(text));
    // printf(" Words: %i",count_words(text));
    // printf(" Sentences: %i", count_sentences(text));
    grade_index(count_letter(text),count_words(text),(count_sentences(text)));
    printf("\n");
}

int count_letter(string letters)
{
    int count=0;
    for (int i=0,n=strlen(letters);i<n;i++)
    {
        if (isalpha(letters[i]))
        {
            count +=1;
        }
    }
    return count;
}

int count_words(string words)
{
    int count=0;
    for (int i=0,n=strlen(words);i<n;i++)
    {
        if(words[i]== ' ')
        {
            count += 1;
        }
    }
    return count+1;
}

int count_sentences(string sentences)
{
    int count=0;
    for (int i=0, n=strlen(sentences);i<n;i++)
    {
        if(sentences[i]=='.' || sentences[i]=='!' || sentences[i]=='?')
        {
            count += 1;
        }
    }
    return count;
}

int grade_index(int letters, int words, int sentences)
{
    float index= (0.0588 * (((float)letters/words)*100)) - (0.296 * (((float)sentences/words)*100)) - 15.8;
    if (round(index)<1)
    {
        printf("Before Grade 1");
    } else if (round(index)>=16)
    {
        printf("Grade 16+");
    } else
    {
        printf("Grade %i",(int)round(index));
    }
    return 0;
}