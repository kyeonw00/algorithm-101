#include <iostream>

using namespace std;

int N, B, C;
int A[1000001];
long long answer;

int main()
{
    scanf("%d", &N);

    for (int a = 0; a < N; ++a)
    {
        scanf("%d", &A[a]);
    }

    scanf("%d %d", &B, &C);

    for (int i = 0; i < N; ++i)
    {
        answer++;
        A[i] -= B;

        if (A[i] > 0)
        {
            answer += A[i] / C;
            if (A[i] % C > 0)
            {
                ++answer;
            }
        }
    }

    printf("%lld\n", answer);
}

#include <iostream>
#define max_int 1000001
#define lld long long

using namespace std;

int n, a[max_int], b, c;
lld result;

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d %d", &b, &c);

    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i] - b;
        result++;
        if (a[i] > 0)
        {
            result += a[i] / c;
            if (a[i] % c > 0)
            {
                result++;
            }
        }
    }

    printf("%lld\n", result);
}