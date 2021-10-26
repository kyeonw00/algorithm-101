#include <stdio.h>

using namespace std;

int main()
{
    int T;
    int a, b, temp;

    scanf("%d", &T);
    // cin >> T;

    while (T > 0)
    {
        T--;
        scanf("%d %d", &a, &b);
        // cin >> a >> b;

        temp = a;
        for (int i = 0; i < b - 1; i++)
            a = temp * a % 10;
        
        if (a % 10 == 0)
            a = 10;
        else
            a = a % 10;

        printf("%d\n", a);
    }
}