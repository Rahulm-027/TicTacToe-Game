#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int countt=0;

void Print(int*a){
    int n;
    printf("\n\n");
    for(int i=1;i<4;i++){
        for(int j=1;j<5;j++){
            for(int k=1;k<4;k++){
                n=(i-1)*3 + k;
                if(i==3){
                    if(j==4) printf("\n");
                }
                else{
                    if(j==4){
                        printf("-----");
                        if(k==3) printf("\n");
                        else printf("|");
                    }
                }
                if(j==2){
                    if(a[n-1]==1) printf("  X  ");
                    else if(a[n-1]==2) printf("  0  ");
                    else printf("  %d  ",n);
                    if(k==3) printf("\n");
                    else printf("|");
                }
                else if(j==1||j==3){
                    printf("     ");
                    if(k==3) printf("\n");
                    else printf("|");
                }
            }
        }
    }
}

int Check(int*a){
    for(int i=0;i<7;i=i+3){
        if(a[i]==1&&a[i+1]==1&&a[i+2]==1) return 1;
        if(a[i]==2&&a[i+1]==2&&a[i+2]==2) return 2;
    }
    for(int i=0;i<3;i++){
        if(a[i]==1&&a[i+3]==1&&a[i+6]==1) return 1;
        if(a[i]==2&&a[i+3]==2&&a[i+6]==2) return 2;
    }
    if(a[0]==1&&a[4]==1&&a[8]==1) return 1;
    if(a[2]==1&&a[4]==1&&a[6]==1) return 1;
    if(a[0]==2&&a[4]==2&&a[8]==2) return 2;
    if(a[2]==2&&a[4]==2&&a[6]==2) return 2;
    return 0;
}

int GP(int*a,int n){
    countt++;
    if(countt==1) return 7;
    if(countt==2){
        int i=0;
        for(;i<9;i++){
            if(a[i]==n) break;
        }
        if(i==3||i==7||i==1||i==5) return 5;
        if(i==2) return 1;
        if(i==4||i==0||i==8) return 3;
    }
    if(countt==3){
        for(int i=1;i<10;i++){
            if(a[i-1]==0){
                a[i-1]= n==1 ? 2:1;
                if(Check(a)){
                    a[i-1]=0;
                    return i;
                }
                a[i-1]= n;
                if(Check(a)){
                    a[i-1]=0;
                    return i;
                }
                else a[i-1]=0;
            }
        }
        if(a[4]!=0&&a[4]!=n){
            if(a[1]==n||a[7]==n) return 1;
            else return 9;
        }
        if(a[0]!=0&&a[0]!=n) return 9;
        if(a[2]!=0&&a[2]!=n){
            if(a[0]==n) return 9;
            if(a[8]==n) return 1;
        }

        while(1){
            int r=rand()%10;
            if(a[r-1]==1||a[r-1]==2||r==0) continue;
            return r;
        }

    }
    for(int i=1;i<10;i++){
        if(a[i-1]==0){
            a[i-1]= n==1 ? 2:1;
            if(Check(a)){
                a[i-1]=0;
                return i;
            }
            a[i-1]= n;
            if(Check(a)){
                a[i-1]=0;
                return i;
            }
            else a[i-1]=0;
        }
    }
    while(1){
        int r=rand()%10;
        if(a[r-1]==1||a[r-1]==2||r==0) continue;
        return r;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));
    char ch,name[30][30],winner[15][30];
    int count=-2,coun=-1;
    printf("\t\t\tTIC-TAC-TOE\n\nWelcome to the most played 2D game and a sort of the fun using X and 0\n\nFor rules press Y else type any other character:- ");
    scanf("%c",&ch);

    if(ch=='Y') printf("1: Each player will be entering the number to put respective X or 0 in desired position.\n2: Player who gets a combination of 3 same character either digonally or horizontally or\nvertically will be decrlared as the winner.\n\n");

    printf("Enjoy the game!\n\n\n");
    while(1){
        printf("\nType 1 to start the game.\n");
        printf("Type 2 to view the leader board.\nType 3 to exit.\n");
        int num;
        countt=0;
        scanf("%d",&num);
        if(num==1){
            count=count+2;
            coun++;
            printf("Enter 1 for multiplayer or enter 2 to play with computer else enter 3 to go back: ");
            scanf("%d",&num);
            if(num==1){
                int place[9]={0};
                printf("\n\nEnter name of player1: ");
                scanf("%s",name[count]);
                printf("Enter name of player2: ");
                scanf("%s",name[count+1]);
                printf("\n%s choose X or 0: ",name[count]);
                scanf(" %c",&ch);
                Print(place);
                if(ch=='X'){
                    int i;
                    for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count+1]);
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count+1]);
                            scanf("%d",&r2);
                            if(place[r2-1]==1||place[r2-1]==2) continue;
                            else{
                                place[r2-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count+1]);
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                }
                if(ch=='0'){
                    int i;
                    for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count+1]);
                                strcpy(winner[coun],name[count+1]);
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count+1]);
                            scanf("%d",&r2);
                            if(place[r2-1]==1||place[r2-1]==2) continue;
                            else{
                                place[r2-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count]);
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\n%s is the winner!!!\n\n",name[count+1]);
                                strcpy(winner[coun],name[count+1]);
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                }
            }
            if(num==3){
                count=count-2;
                coun--;
                num=1;
            }
            if(num==2){
                int place[9]={0},mode;
                printf("\n\nChoose mode:\nPress 1 for easy or Press 2 for hard: ");
                scanf("%d",&mode);
                printf("\nEnter name of player1: ");
                scanf("%s",name[count]);
                strcpy(name[count+1],"computer");
                printf("\n%s choose X or 0: ",name[count]);
                scanf(" %c",&ch);
                Print(place);
                if(mode==1){
                    if(ch=='X'){
                        int i;
                        for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            r2=rand()%10;
                            if(place[r2-1]==1||place[r2-1]==2||r2==0) continue;
                            else{
                                place[r2-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                    }
                    if(ch=='0'){
                        int i;
                        for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            r2=rand()%10;
                            if(place[r2-1]==1||place[r2-1]==2||r2==0) continue;
                            else{
                                place[r2-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                    }
                }    
                if(mode==2){
                    if(ch=='X'){
                        int i;
                        for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            r2=GP(place,1);
                            if(place[r2-1]==1||place[r2-1]==2||r2==0) continue;
                            else{
                                place[r2-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==1){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==2){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                    }
                    if(ch=='0'){
                        int i;
                        for(i=0;i<5;i++){
                        int r1,r2;
                        while(1){
                            r2=GP(place,2);
                            if(place[r2-1]==1||place[r2-1]==2||r2==0) continue;
                            else{
                                place[r2-1]=1;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                        if(i==4) continue;
                        while(1){
                            printf("%s type any place to fill your response:- ",name[count]);
                            scanf("%d",&r1);
                            if(place[r1-1]==1||place[r1-1]==2) continue;
                            else{
                                place[r1-1]=2;
                                break;
                            }
                        }
                        Print(place);
                        if(Check(place)){
                            if(Check(place)==2){
                                printf("\n\n\nYou Won!!!\n\n");
                                strcpy(winner[coun],name[count]);
                            }
                            if(Check(place)==1){
                                printf("\n\n\nYou Lost!!!\n\n");
                                strcpy(winner[coun],"Computer");
                            }
                            break;
                        }
                    }
                    if(i==5){
                        printf("\n\n\nDRAW!!!\n\n");
                        strcpy(winner[coun],"Draw");
                    }
                    }
                }    
                num=1;
            }
        }
        if(num==2){
            printf("\n\t\t\tLEADERBOARD\n\n");
            printf("PLAYER1   PLAYER2   WINNER\n\n");
            int l=0;
            for(int i=0;i<=coun;i++){
                printf("%-10s%-10s%-10s\n",name[l],name[l+1],winner[i]);
                l=l+2;
            }
        }
        if(num==3) break;
    }
    return 0;
}
