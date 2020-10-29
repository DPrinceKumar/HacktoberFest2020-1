#include<stdio.h>
int main()
{

        int marks[2][4];
        printf("Enter the value by row size:\n");
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<4;j++)
            {

                scanf("%d",&marks[i][j]);
            }

            printf("\n");
        } for(int i=0;i<2;i++)
        {
            for(int j=0;j<4;j++)
            {

                printf("%d ",marks[i][j]);
            }

            printf("\n");
        }

    return 0;
}
//aniketbhalani kindly accept this pull request of mine
