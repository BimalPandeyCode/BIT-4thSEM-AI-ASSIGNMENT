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

int* copyArray(int arr[LENGTH]) {
    int* newArr = malloc(LENGTH * sizeof(int));
    for (int i = 0; i < LENGTH; i++) {
        newArr[i] = arr[i];
    }
    return newArr;
}

int DFS(int visited[LENGTH],int s, int e,int cost){
    int * newVisitedI = copyArray(visited);
    int index = includes(newVisitedI,-1);
    newVisitedI[index] = s;
    if(s == e){
        displayArray(newVisitedI,cost);
        return 1;
    }

    for(int i = 0;i < LENGTH; i++){
        if(graph[s][i] > 0){
            int isIncluded = includes(newVisitedI,i);
            int newCost = cost + graph[s][i];
            if(includes(newVisitedI,i) == -1){
                DFS(newVisitedI,i,e,newCost);
            }
        }
    }
    return 0;
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int startI = 0, endI = 5;
    DFS(visitedI,startI,endI,0);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}