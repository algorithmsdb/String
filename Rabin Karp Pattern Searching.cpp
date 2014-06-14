/*
Rabin Karp Fingerprint Algorithm:
The average and best case running time of the Rabin-Karp algorithm is O(n+m)
Worst-case time is O(nm).
*/

#include<bits/stdc++.h>
using namespace std;
#define d 256                  // The dictionary of 256 characters

void search(char *txt , char *pat , int q)
{
int m=strlen(pat);
int n=strlen(txt);

int i,j;
int p=0;                       // hash value for pattern
int t=0;                       // hash value for text
int h=1;                       // d^(m-1) value

// Compute the value of d^(m-1) --> Pre-processing in linear time
for(i=0;i<m-1;i++)
    {
    h=(d*h)%q;
    }

// Multiply each character by its place value and obtain the hash value
// Initial Hash values of current sliding text window and the pattern is being calculated
for(i=0;i<m;i++)
    {
    p=(d*p+pat[i])%q;
    t=(d*t+txt[i])%q;
    }

for(i=0;i<=n-m;i++)
    {
    // Check if the current sliding window of text and pattern have same hash values
    if(t==p)
    {
    // Check if all characters are same or it's a SPURIOUS HIT !
        for(j=0;j<m;j++)
        {
        if(txt[i+j]!=pat[j]) break;     //it's a SPURIOUS HIT
        }
    if(j==m) cout<<"Pattern matched at index "<<i<<endl;     // pattern found
    }

// Now compute the next sliding window for the text using previous value..
    if(i<n-m)
        {
        t = (d*(t - txt[i]*h) + txt[i+m])%q;

        // We might get negative value of t, converting it to positive
        if(t < 0)
        t = (t + q);
        }
    }
}

int main()
{
char a[500],b[500];

cout<<"\n\nEnter the string\n\n"<<endl;
scanf(" %[^\n]%*c",a);

cout<<"\n\nEnter the sub-string you wish to search for\n\n"<<endl;
scanf(" %[^\n]%*c",b);

int q=7;                      // Let the prime number for computation be 7

cout<<"\n\n";
search(a,b,q);
}
