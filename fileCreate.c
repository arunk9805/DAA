#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i,n;
    FILE *fp;
    scanf("%d",&n);
    srand(time(NULL));
    fp = fopen("Rand.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d\n", rand() % 1000 + 1);
    fclose(fp);
    fp = fopen("asc.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d\n", i+1);
    fclose(fp);
    fp = fopen("des.txt", "w");
    for (i = 0; i < n; i++)
        fprintf(fp, "%d\n", n-i);
    fclose(fp);

    return 0;
}
