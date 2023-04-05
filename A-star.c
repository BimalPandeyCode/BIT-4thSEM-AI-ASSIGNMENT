#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 8

struct node {
    int index;
    int cost;
    int h;
    int visited;
    int parent;
};

int graph[LENGTH][LENGTH] = {
    { 10, 3, -1, -1, 4, -1,-1,-1},//0
    { 3, 8.5, 4, -1, 5, -1,-1,-1},//1
    { -1, 4, 6, 4, -1, 5,-1,-1},//2
    { -1, -1, 4, 3, -1, -1,-1,-1},//3
    { 4, 5, -1, -1, 8, 2,-1,-1},//4
    { -1, -1, 5, -1, 2, 6,4,-1},//5
    {-1,-1,-1,-1,-1,4,3,3},//6
    {-1,-1,-1,-1,-1,-1,3,0}//7
};

struct node list[LENGTH];

void moveToStart(int index) {
    struct node temp = list[index];
    for (int i = index; i > 0; i--) {
        list[i] = list[i-1];
    }
    list[0] = temp;
}

int findMinFIndex(){
    int min = 100000;
    int minI = -1;

    for(int i =0;i<LENGTH;i++){
        if(list[i].index == -1 || list[i].visited == 1) continue;
        if(list[i].cost + list[i].h < min){
            minI = i;
            min = list[i].cost + list[i].h;
        }
    }
    return minI;
}
int findIndexInList(int index){
    for(int i =0;i<LENGTH;i++){
        if(list[i].index == index){
            return i;
        }
    }
    return -1;
}
int findFirstNegativeIndexInList(){
    for(int i =0;i<LENGTH;i++){
        if(list[i].index == -1){
            return i;
        }
    }
    return -1;
}

void Astar(int s,int e){
    int found = 0;

    list[0].index = s;
    list[0].cost = 0;
    list[0].h = graph[0][0];
    list[0].visited = 0;

    while (found == 0){
        if(list[0].index == e) {
            found = 1;
            continue; 
        };

        int min_f_index = findMinFIndex();
        moveToStart(min_f_index);

        list[0].visited = 1;

        for(int i =0;i<LENGTH;i++){
            if(graph[list[0].index][i] == -1 || list[0].index == i) continue;
            int indexI = findIndexInList(i);
            if(indexI == -1){
                int curr = findFirstNegativeIndexInList();
                list[curr].index = i;
                list[curr].cost = list[0].cost + graph[list[0].index][i];
                list[curr].parent = list[0].index;
            }else{
                if(list[indexI].cost > list[0].cost + graph[list[0].index][i]){
                    list[indexI].cost = list[0].cost + graph[list[0].index][i];
                    list[indexI].parent = list[0].index;
                }
            }
        }
    }
    int currIndex = e;
    while (currIndex != s){
        int listIndex = findIndexInList(currIndex);
        printf("%d=%d\t",list[listIndex].index,list[listIndex].cost);
        currIndex = list[listIndex].parent;
    }
    int listIndex = findIndexInList(s);
    printf("%d=%d\t\n",list[listIndex].index,list[listIndex].cost);
}

int main(){
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int startI = 0, endI = 7;

    // INIT
    for (int i = 0; i < LENGTH; i++) {
        list[i].index = -1;
        list[i].cost = 0;
        list[i].h = 0;
        list[i].visited = 0;
        list[i].parent = -1;
    }

    Astar(startI,endI);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}