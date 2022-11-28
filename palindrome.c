# include <stdio.h>
# include <ctype.h>
# include <string.h>

int main()
{
    char word[30];
    int l,flag=0;
    printf("Enter the word");
    gets(word);
    l = strlen(word);
    for(int i=0;i<l;i++)
    {
        if (word[i] != word[l-i-1])
        {
            flag = 1;
            break;
        }
    }
    
    if (flag == 0)
    printf("Palindrome");
    else
    printf("Not a plindrome");

    return 0;
}
