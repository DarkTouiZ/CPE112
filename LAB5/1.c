// 66070501060  ADISORN PARAMA
// Lab 5.1: Spotify

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue{
    char name[101];
    char artist[101];
    int sec;
    struct queue *next;
}queue;

queue *assignSong();
void addSong(queue **songQueue);
void popQueue(queue **songQueue);
void showRemainTime(queue *songQueue);

int main()
{
    queue *songQueue = NULL;
    char oper[11];
    while (1)
    {
        scanf("%s", &oper);
        if(strcmp(oper, "add") == 0){
            addSong(&songQueue);
        }else if(strcmp(oper, "play") == 0){
            popQueue(&songQueue);
        }else if(strcmp(oper, "sum") == 0){
            showRemainTime(songQueue);
            return 0;
        }
        else{
            printf("Invalid command\n");
            return 1;
        }
    }
}

queue *assignSong(){
    queue *newSong = (queue *)malloc(sizeof(queue));
    if(newSong == NULL){
        printf("memory allocation failed\n");
        exit(1);
    } 
    getchar();
    //clear buffer
    fgets(newSong->name, 101, stdin);
    //assign last to whitespace
    newSong->name[strlen(newSong->name) - 1] = '\0';
    fgets(newSong->artist, 101, stdin);
    //assign last to whitespace
    newSong->artist[strlen(newSong->artist) - 1] = '\0';
    scanf("%d", &newSong->sec);
    newSong->next = NULL;
    return newSong;
}

void addSong(queue **songQueue){
    queue *newSong = assignSong();
    if(*songQueue == NULL){
        *songQueue = newSong;
    }else{
        queue *curr = *songQueue;
        while(curr->next != NULL)
            curr = curr->next;
        
        curr->next = newSong;
    }
}

void popQueue(queue **songQueue){
    if(*songQueue == NULL){
        printf("No songs in the playlist\n");
    }
    else{
        printf("Now playing: %s by %s\n", (*songQueue)->name, (*songQueue)->artist);
        queue *tmp = *songQueue;
        *songQueue = (*songQueue)->next;
        free(tmp);   
    }
}

void showRemainTime(queue *songQueue){
    int sum;
    printf("Songs in the playlist:\n");
    while(songQueue != NULL){
        printf("%s by %s %d\n", songQueue->name, songQueue->artist, songQueue->sec);
        sum += songQueue->sec;
        songQueue = songQueue->next;
    }
    printf("Remaining Time: %d\n", sum);
}