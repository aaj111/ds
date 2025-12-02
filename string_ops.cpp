#include<iostream>
using namespace std;
int strlen(char str[])
{
    int len = 0;
    while(str[len]!='\0')
    {
        len++;
    }
    return len;
}
void strcopy(char dest[],char src[])
{
    int i = 0;
    while(src[i]!='\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void strConcat(char str1[],char str2[])
{
    int len1 = strlen(str1);
    int i = 0;
    while(str2[i] !='\0')
    {
        str1[len1+i] = str2[i];
        i++;
    }
    str1[len1 + i] = '\0';
}
void strReverse(char str[])
{
    int start = 0;
    int end = strlen(str)-1;
    while(start<end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    char str1[100],str2[100],copyStr[100];
     cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

       cout << "\nLength of first string: " << strlen(str1);

    strcopy(copyStr, str1);
    cout << "\nCopied string: " << copyStr;

    strReverse(str1);
    cout << "\nReversed first string: " << str1;

    // Restore original str1 by copying back
    strcopy(str1, copyStr);

    strConcat(str1, str2);
    cout << "\nConcatenated string: " << str1 << endl;

    return 0;
}