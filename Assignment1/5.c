// Adisorn Parama 660705001060
//  Grading

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char name[100];
    float score;
} Student;

float Mean(Student *s, int n);
float SD(Student *s, int n, float mean);
char *StudentMax(Student *s, int n);
char *StudentMin(Student *s, int n);

int main()
{
    int n;
    scanf("%d", &n);
    // invalid case
    if (n <= 0 || n > 100)
        return 1;

    Student *student = (Student *)malloc(n * sizeof(Student));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %f", student[i].name, &student[i].score);
        // invalid case
        if (student[i].score < 0 || student[i].score > 100 || strlen(student[i].name) < 1 || strlen(student[i].name) > 100)
            return 1;
    }

    // find Mean, SD, name of max score, name of min score
    float mean = Mean(student, n);
    float sd = SD(student, n, mean);
    char *max_name = StudentMax(student, n);
    char *min_name = StudentMin(student, n);

    // print result
    printf("%.2f %.2f %s %s", mean, sd, max_name, min_name);
    free(student);
    return 0;
}

float Mean(Student *s, int n)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i].score;
    }
    return sum / n;
}

float SD(Student *s, int n, float mean)
{
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += pow(s[i].score - mean, 2);
    }
    return sqrt(sum / n);
}

char *StudentMax(Student *s, int n)
{
    int max_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].score > s[max_index].score)
            max_index = i;
    }
    return s[max_index].name;
}

char *StudentMin(Student *s, int n)
{
    int min_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].score < s[min_index].score)
            min_index = i;
    }
    return s[min_index].name;
}
