#include <stdio.h>
#include <stdbool.h>

void printgame(int f[3], int s[3], int t[3]) {
    printf("%d %d %d\n",f[0],f[1],f[2]);
    printf("%d %d %d\n",s[0],s[1],s[2]);
    printf("%d %d %d\n",t[0],t[1],t[2]);
}

void pO(int f[3], int s[3], int t[3]){
    int x,y;
    bool done=false;
    bool error=true;
    while(!done){
        printf("Choose line:");
        scanf("%d", &x);
        printf("Choose column:");
        scanf("%d", &y);
        if(x>3||x<1||y<1||y>3){
            printf("insert valid positions\n");
        }else{
            error=false;
        }
        if(!error){
        y=y-1;
        if (x == 1) {
            if(f[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            f[y]=1;
            done=true;
        }
        }
        if (x == 2) {
            if(s[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            s[y]=1;
            done=true;
        }
        }
        
        if (x == 3) {
            if(t[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            t[y]=1;
            done=true;
        }
        }
    }
    }
}

void pT(int f[3], int s[3], int t[3]){
    int x,y;
    bool done=false;
    bool error=true;
    while(!done){
        printf("Choose line:");
        scanf("%d", &x);
        printf("Choose column:");
        scanf("%d", &y);
        if(x>3||x<1||y<1||y>3){
            printf("insert valid positions\n");
        }else{
            error=false;
        }
        if(!error){
        y=y-1;
        if (x == 1) {
            if(f[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            f[y]=2;
            done=true;
        }
        }
        if (x == 2) {
            if(s[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            s[y]=2;
            done=true;
        }
        }
        
        if (x == 3) {
            if(t[y]!=0){
                printf("position is already in-use\n");
                done = false;
            }else{
            t[y]=2;
            done=true;
        }
        }
    }
    }
}

bool win(int f[3], int s[3], int t[3]){
    for(int i=0; i<3; i++){
        if(f[i]==s[i]&&s[i]==t[i]&&f[i]!=0){
            return true;
        }
    }
        if(f[0]==f[1]&&f[1]==f[2]&&f[0]!=0){
            return true;
        }
        if(s[0]==s[1]&&s[1]==s[2]&&s[0]!=0){
            return true;
        }
        if(t[0]==t[1]&&t[1]==t[2]&&t[0]!=0){
            return true;
        }
        if ((f[0]==s[1]&&s[1]==t[2]&&f[0]!=0)||(f[2]==s[1]&&s[1]==t[0]&&f[2]!=0)) {
            return true;
        }
    return false;
}

bool draw(int f[3], int s[3], int t[3]) {
    for(int i = 0; i < 3; i++) {
        if(f[i]==0||s[i]==0||t[i]==0){
            return false;
        }else{
            return true;
        }
    }
}


int main() {
    int fs[3] = {0, 0, 0};
    int sc[3] = {0, 0, 0};
    int td[3] = {0, 0, 0};
    bool gameOver = false;
    
    while (!gameOver) {
        printgame(fs, sc, td);
        pO(fs, sc, td);
        if(win(fs, sc, td)){
            printf("Player 1 wins!\n");
            gameOver = true;
            break;
        }
        if(draw(fs, sc, td)){
            printf("It's a draw!\n");
            gameOver=true;
            break;
        }
        printgame(fs, sc, td);
        pT(fs, sc, td);
        if(win(fs, sc, td)){
            printf("Player 2 wins!\n");
            gameOver = true;
            break;
        }
        if(draw(fs, sc, td)){
            printf("It's a draw!\n");
            gameOver=true;
            break;
        }
    }
}
