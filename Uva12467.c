// secret word
//Uva 12467

#include<stdio.h>
#include<string.h>
#define MAX 1000

char str[MAX];
char substring[MAX];
int b[MAX];
int n,m,anslen;

void kmp();
void kmpPreprocess();

int main(){
    int tc,i,len;
    printf("Number of total case : ");
    scanf("%d",&tc);

    while(tc--){
        scanf("%s",str);
        len = strlen(str);
        for(i=0;i<len;i++){
            substring[i] = str[len - i - 1];
        }

        substring[len] = '\0';
        kmpPreprocess();
        anslen = -1;
        kmp();

        for(i = anslen-1; i>=0; i--){
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

void kmp(){
    n = strlen(substring);
    int i = 0;
    int j = 0;

    while(i<n){
        while(j>0 && substring[i] != str[j]){
            j = b[j];
        }

        i++;
        j++;

        if(j > anslen) anslen = j;
        if(j == m) j = b[j];
    }
}

void kmpPreprocess(){
    m = strlen(str);
    int i = 0;
    int j = -1;
    b[0] = -1;
    //b[i] = -1;

    while(i<m){
        while(j>=0 && str[i] != str[j]){
            j = b[j];
        }

        i++;
        j++;
        b[i] = j;
    }
}
