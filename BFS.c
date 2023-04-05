#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 6

int graph[LENGTH][LENGTH] = {
    { 0, 2, 3, 0, 0, 0},
    { 2, 0, 1, 0, 0, 10},
    { 3, 1, 0, 2, 0, 0},
    { 0, 0, 2, 0, 1, 0},
    { 0, 0, 0, 1, 0, 1},
    { 0,10, 0, 0, 1, 0}
};

int visitedI[LENGTH] = {-1,-1,-1,-1,-1,-1};
int v[LENGTH][LENGTH] = {{-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1},
                        {-1,-1,-1,-1,-1,-1}};

int includes(int visited[LENGTH],int x){
    for(int i=0;i<LENGTH;i++)
        if(visited[i] == x)
            return i;
    return -1;
}

void displayArray(int arr[LENGTH],int cost){
    for(int i =0;i<LENGTH;i++){
        if(arr[i] != -1){
            printf("%d\t",arr[i]);
        }else{
            printf("\t");
        }
    }
    printf("cost :: %d\n",cost);
}

void display_2d_Array(int arr[LENGTH][LENGTH]){
    for(int i =0;i<LENGTH;i++){
        for(int j =0;j<LENGTH;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void copy_2d_array(int arr[LENGTH][LENGTH], int new_arr[LENGTH][LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            new_arr[i][j] = arr[i][j];
        }
    }
}
int BFS(int level[LENGTH],int visited[LENGTH][LENGTH],int s,int e,int cost[LENGTH]){

    if(level[0] == -1){
        return 0;
    }

    int newLevel[LENGTH] = {-1,-1,-1,-1,-1,-1};
    int newCost[LENGTH] = {-1,-1,-1,-1,-1,-1};

    int newVisited[LENGTH][LENGTH] ={{-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1},
                                    {-1,-1,-1,-1,-1,-1}};
    copy_2d_array(visited,newVisited);

    for(int i = 0; i < LENGTH; i++){
        if(level[i] == -1) continue;
        if(level[i] == e){
            newVisited[i][includes(newVisited[i],-1)] = e;
            visited[i][includes(visited[i],-1)] = e;
            displayArray(visited[i],cost[i]);
            continue;
        }
        for(int j = 0; j < LENGTH; j++){
            if(graph[level[i]][j] <= 0) continue;
            int newLevelIndex = includes(newLevel,-1);
            for(int k = 0;k<LENGTH;k++){
                newVisited[newLevelIndex][k] = visited[i][k];
            }
            newVisited[newLevelIndex][includes(newVisited[newLevelIndex],-1)] = level[i];

            int isIncluded = includes(newVisited[newLevelIndex],j);
            if(isIncluded != -1) continue;
            newLevel[newLevelIndex] = j;
            if(cost[i] != -1){
                newCost[includes(newCost,-1)] = graph[level[i]][j] + cost[i];
            }else{
                newCost[includes(newCost,-1)] = graph[level[i]][j];
            }
        }
    }

    return BFS(newLevel,newVisited,s,e,newCost);
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int startI = 0, endI = 5;

    int startingLevel[LENGTH] = {startI,-1,-1,-1,-1,-1};
    BFS(startingLevel,v,startI,endI,visitedI);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}