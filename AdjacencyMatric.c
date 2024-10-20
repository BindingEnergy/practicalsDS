#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void createMatrix(int size , int graph[][size] )
{
    int i,j,choice =1,node;
    for(i = 0 ; i < size ; i++)
    {
        printf("\nCreating links for Node %d",i+1);
        choice = 1;
        while(choice)
        {
            printf("\nconnect to: ");
            scanf("%d",&node);
            if(node > size && node < 1)
            {
                printf("\nInvalid node entered !");
            }
            else
            {
                graph[i][node-1] = 1;
            } 
            printf("\nCreate another connection? Yes or No\nChoice: ");
            scanf("%d",&choice);
        }
        printf("\nLinks for Node %d created !",i+1);
    }
}

void main()
{
    int n,vertices;
    int i,j;
    int graph[10][10];
    printf("\nEnter number of vertices: ");
    scanf("%d",&vertices);
    createMatrix(vertices,graph);
    printf("\nThe adjacency Matrix created is:\n");
    for(i = 0 ; i < vertices ; i++)
    {
        for(j = 0 ; j < vertices ; j++)
        {
            printf("%2d ",graph[i][j]);
        }
        printf("\n");
    }
    getch();
}