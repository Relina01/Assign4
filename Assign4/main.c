#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int row;
    int col;
    int val;
} Element;

void transpose(Element* a, Element* b, int n, int m)
{
    int i, j, currentB = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 1; j <= n; j++) 
        {
            if (a[j].col == i)
            {
                b[currentB].row = a[j].col;
                b[currentB].col = a[j].row;
                b[currentB].val = a[j].val;
                currentB++;
            }
        }
    }
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
}

int main()
{
    int n, m, numTerms;
    printf("Enter number of rows, columns, and number of nonzero terms: ");
    scanf_s("%d %d %d", &n, &m, &numTerms);

    if (numTerms == 0) 
    {
        printf("No terms to read\n");
        return 0;
    }

    Element* a = (Element*)malloc((numTerms + 1) * sizeof(Element));
    Element* b = (Element*)malloc((numTerms + 1) * sizeof(Element));

    if (a == NULL || b == NULL) 
    {
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i <= numTerms; i++) 
    {
        scanf_s("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
    }
    // 인덱스를 0부터 시작하므로 a[0], b[0]에 데이터가 있음
    transpose(a, b, n, m);

    printf("Transpose of the matrix:\n");
    for (int i = 0; i <= numTerms; i++) 
    {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);
    }

    free(a);
    free(b);

    return 0;
}