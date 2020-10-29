// calender

// by utsav jain
// date : 03.10.2020

#include<stdio.h>
void prntmonth(int strtno, int no);

void main()
{
    int strtno, no;

    printf("the no of the day from which the month begins \n 0 for sunday \n 1 for monday \n 2 for tuesday \n 3 for wednesday \n 4 for thursday \n 5 for friday \n 6 for sunday \n => ");
    scanf( "%d",&strtno);

    printf("Nter the no of days in month ");
    scanf("%d",&no);
    prntmonth(strtno,no);

}

void prntmonth(int strtno, int no)
{
    int wday;
    // the labelling
    printf("SUN  MON  TUE  WED  THU  FRI  SAT \n ");
    printf("---  ---  ---  ---  ---  ---  --- \n");

    int daycount;
    for (wday=0;wday<strtno;wday++)
    printf("     ");

        for (daycount=1; daycount<=no;daycount++)
        {
            if (wday>6)
            {
                printf("\n");
                wday=1;
            }
            else wday++;
            printf(" %3d ", daycount);
        }


}
