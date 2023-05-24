#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsVPS(const string *ps)
{
    int openCaseCounter = 0;
    for (int i = 0; i < ps->length(); ++i)
    {
        if (ps->at(i) == ')')
        {
            if (--openCaseCounter < 0)
            {
                return false;
            }
        }
        else
        {
            openCaseCounter++;
        }
    }

    return openCaseCounter == 0;
}

int main()
{
    int T;
    cin >> T;

    string ps;
    bool isVPS;
    for (int t = 0; t < T; ++t)
    {
        cin >> ps;

        isVPS = IsVPS(&ps);
        cout << (isVPS ? "YES" : "NO") << endl;
    }
}