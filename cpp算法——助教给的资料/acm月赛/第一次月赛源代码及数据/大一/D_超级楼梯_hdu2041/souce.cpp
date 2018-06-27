#include <cstdio>
#include<iostream>
using namespace std;
int main()
{
    int i, n;
    int m[41] = {0, 1};
    for (i = 2; i < 41; i++)
        m[i] = m[i-1] + m[i-2];
    scanf("%d", &n);
    while (n-- && scanf("%d", &i))
        printf("%d\n", m[i]);
    return 0;
}
