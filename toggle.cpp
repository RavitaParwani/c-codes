#include <iostream>
#include<string.h>
using namespace std;

int main()
{
    char str[101];
    scanf("%s",&str);
    int l=strlen(str);
    
    for(int i=0;i<l;i++)
    {
        if(str[i]>='A'||str[i]<='Z')
        {
            str[i]=str[i]+32;
        }
        else
        {
            str[i]=str[i]-32;
        }
    }
    
    printf("%s",str);
    return 0;
}

