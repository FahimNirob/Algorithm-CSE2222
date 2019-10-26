#include<stdio.h>
#include<string.h>

char str[100000];
char substr[100000];
int b[100000];

int kmp(char *str, char *substr);
void kmpPreprocess(char *substr);

int main(){
    int tc,i;
    printf("Enter case number : ");
    scanf("%d",&tc);
    for(i=0;i<tc;i++){
        scanf("%s %s",str,substr);
        printf("Case %d: %d\n",i+1,kmp(str,substr));
    }
    return 0;
}

int kmp(char *str, char *substr){
    int i = 0;
    int j = 0;
    int count = 0;
    int n = strlen(str);
    int m = strlen(substr);

    kmpPreprocess(substr);

    while(i<n){
        while(j>=0 && str[i] != substr[j]){
            j = b[j];
        }
        i++;
        j++;

        if(j==m){
            count++;
            j = b[j];
        }
    }
    return count;
}

void kmpPreprocess(char *substr){
    int m = strlen(substr);
    int i = 0;
    int j = -1;
    b[i] = -1;

    while(i<m){
        while(j>=0 && substr[i] != substr[j]){
            j = b[j];
        }

        i++;
        j++;
        b[i] = j;
    }
}
