#include<stdio.h>
#define MAX 15
struct team{
    char teamname[20];
    int matchesPlay;
    int wins;
    int draws;
    int losses;
    int goalscores;
    int goalconceded;
    int goalDifference;
    int points;
};
void sort(struct team t[])
{
        struct team temp;
    for(int i=0;i<MAX;i++)
    {

        for(int j=0; j<MAX; j++)
        {
            if(t[j+1].points>t[j].points)
            {
                temp=t[j+1];
                t[j+1]=t[j];
                t[j]=temp;
            }


          if(t[j+1].points==t[j].points)
            {
                if(t[j+1].goalDifference>t[j].goalDifference)
                {
                temp=t[j+1];
                t[j+1]=t[j];
                t[j]=temp;
                }
            }
            if(t[j+1].points==t[j].points && t[j+1].goalDifference==t[j].goalDifference)
            {
                if(t[j+1].goalscores>t[j].goalscores)
                {
                  temp=t[j+1];
                  t[j+1]=t[j];
                  t[j]=temp;
                }
            }
        }

    }
}
int main()
{
    struct team t[MAX];
    printf("\n==========================================\n");
    printf("         NATIONAL FOOTBALL TORNAMENT          ");
     printf("\n==========================================\n");
    for(int i=0;i<MAX;i++)
    {
        printf("\n-----team %d info------\n",i+1);
        printf("enter team %d's name: ",i+1);
        scanf("%s",t[i].teamname);
        printf("enter number of matches played: ");
        scanf("%d",&t[i].matchesPlay);
        printf("enter number of matches won: ");
        scanf("%d",&t[i].wins);
         printf("enter number of matches lossed: ");
        scanf("%d",&t[i].losses);
        printf("enter number of matches drawed: ");
        scanf("%d",&t[i].draws);
        printf("enter number of goals scored: ");
        scanf("%d",&t[i].goalscores);
        printf("enter number of goals conceded: ");
        scanf("%d",&t[i].goalconceded);
        t[i].goalDifference=t[i].goalscores - t[i].goalconceded;


        t[i].points=t[i].wins * 3 + t[i].draws * 1 + t[i].losses * 0;
    }
    int maxpoint=t[0].points;
    int topindex=0;
    int lowindex=0;
    int maxdfindex=0;

    int maxgoal=t[0].goalDifference;

    int minpoint=t[0].points;
    for(int i=0;i<MAX;i++)
    {
        if(t[i+1].points > maxpoint)
        {
            maxpoint=t[i].points;
           int i=topindex;
        }

        if(t[i].goalDifference > maxgoal)
        {
            maxgoal=t[i].goalDifference;
            int i=maxdfindex;
        }

        if(t[i].points<minpoint)
        {
            minpoint=t[i].points;
           int i=lowindex;
        }
    }


    printf("\n===================================================\n");
    printf("                TOURNAMENT RESULTS                     ");
     printf("\n===================================================\n");
     sort(t);

    printf("\n--------------RESULT TABLE---------------\n");
    printf("%-17s  %-8s  %-8s  %-8s\n","team","points","GD","goals");
    for(int i=0;i<=MAX;i++)
    {
        printf("%d. %-17s  %-8d   %-8d   %-d\n",i+1,t[i].teamname,t[i].points,t[i].goalDifference,t[i].goalscores);
    }
    printf("\n");
    printf("\n------------------CHAMPION----------------\n");
    printf("\nteam name: %s\n",t[0].teamname);
    printf("total goals : %d\n",t[0].goalscores);
    printf("total points : %d\n",t[0].points);
    printf("total goal differeence: %d\n",t[0].goalDifference);
    printf("\n-------------------------------------------\n");

    printf("\n-----------------TOP 3 TEAMS---------------\n");
    printf("\n | team name       | goals  \n");
    for(int i=0; i<MAX && i<3; i++)
    {
        printf("%d.  %s           %d\n",i+1, t[i].teamname,t[i].points);
    }
    printf("\n-------------------------------------------\n");

    printf("\n---------------BOTTOM 3 TEAMS--------------\n");
    printf("\n | team name       | goals  \n");
    for(int i=MAX-3; i<=MAX; i++)
    {
        printf("%d.  %s           %d\n",i+1, t[i].teamname,t[i].points);
    }
    printf("\n-------------------------------------------\n");
    int total=0;
    for(int i=0;i<=MAX;i++)
    {
       total +=t[i].goalscores;
    }
    printf("\nnumber of goal scored in the tournament: %d",total);
    printf("\naverage goal score per team: %.2f",(float)total/MAX);
}
