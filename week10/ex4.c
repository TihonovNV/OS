#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

ino_t inodes[MAX];

int main(){
    DIR *dirp = opendir("./tmp");
    if (dirp == NULL) { 
        return -1; 
    }
    struct dirent *dp;
    char *names[MAX];
    int i = 0;

    while((dp = readdir(dirp)) != NULL && i < MAX){
        if(strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")){
            inodes[i] = dp->d_ino;
            names[i] = dp->d_name;
            ++i;
        }
    }
    for(i = 0; i < MAX; ++i){
        int counter = 1;
        for(int j = i + 1; j < MAX; ++j){
            if(inodes[i] == inodes[j] && inodes[j] != 0){
                if(counter == 1){
                    printf("Files with i-nodes with hard link count of two or more: %s %s", names[i], names[j]);
                    ++counter;
                    inodes[j] = 0;
                }
                else{
                    printf("%s", names[j]);
                    inodes[j] = 0;
                }
            }
        }
        inodes[i] = 0;
        if(counter != 1)
            printf("\n");
    }
    closedir(dirp);
    return 1;
}