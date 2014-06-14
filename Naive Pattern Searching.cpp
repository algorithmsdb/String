#include<bits/stdc++.h>
using namespace std;

void search (char *text , char *pat)
{
    int n=strlen(text);         // length of text
    int m=strlen(pat);          // length of pattern
    int s,j;
    for(s=0;s<=n-m;s++)         // Iteration over n-m+1 values of shift
    {
        for(j=0;j<m;j++)
        {
        if(pat[j]!=text[s+j]) break;
        }
    if(j==m) cout<<"Pattern found at : "<<s<<endl;
    }
}

int main()
{
char a[500],b[500];

cout<<"\n\nEnter the data string\n\n"<<endl;
scanf(" %[^\n]%*c",a);

cout<<"\n\nEnter the pattern you wish to search for\n\n"<<endl;
scanf(" %[^\n]%*c",b);

cout<<"\n\n";

search(a,b);

}
