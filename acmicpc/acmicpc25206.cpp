#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    float majorGpa = 0.0F;
    float totalSubjectCredit = 0.0F;

    string subjectName;
    float subjectCredit;
    string subjectGrade;

    unordered_map<string, float> gpaByGradeLut = {
        { "A+", 4.5F },
        { "A0", 4.0F },
        { "B+", 3.5F },
        { "B0", 3.0F },
        { "C+", 2.5F },
        { "C0", 2.0F },
        { "D+", 1.5F },
        { "D0", 1.0F },
        { "F",  0.0F }
    };

    for (int i = 0; i < 20; i++)
    {
        cin >> subjectName >> subjectCredit >> subjectGrade;

        if (subjectGrade == "P")
        {
            continue;
        }

        totalSubjectCredit += subjectCredit;
        majorGpa += (subjectCredit * gpaByGradeLut[subjectGrade]);
    }

    majorGpa /= totalSubjectCredit;
    cout << majorGpa;
    return 0;
}

// below is an alternative way
// int main()
// {
//     float majorGpa = 0.0F;
//     float totalSubjectCredit = 0.0F;

//     string subjectName;
//     float subjectCredit;
//     string subjectGrade;
//     float subjectGpa = 0.0F;

//     for (int i = 0; i < 20; i++)
//     {
//         cin >> subjectName >> subjectCredit >> subjectGrade;

//         if (subjectGrade == "P")
//         {
//             continue;
//         }

//         totalSubjectCredit += subjectCredit;

//         if (subjectGrade != "F")
//         {
//             subjectGpa = 'E' - subjectGrade[0];
//             if (subjectGrade[1] == '+')
//             {
//                 subjectGpa += 0.5F;
//             }
//         }
//         else
//         {
//             subjectGpa = 0.0F;
//         }

//         majorGpa += (subjectCredit * subjectGpa);
//     }

//     majorGpa /= totalSubjectCredit;
//     cout << majorGpa;
//     return 0;
// }