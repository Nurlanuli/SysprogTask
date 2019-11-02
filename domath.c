#include  <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(int args,char* argv[]){
  int pid = fork();
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  if(pid==0){
  	printf("child1: %d+%d=%d \n", a,b,a+b);
  }else{
    int pid2 = fork();
    if (pid2 == 0){ //child 2
       printf("child2: %d*%d=%d \n", a,b,a*b);
    }else{
        int pid3 = fork();  
        if(pid3 == 0){ //child 2
          printf("child3: %d-%d=%d \n", a,b,a-b);
        }else{
          int pid4 = fork();  
          if(pid4==0){
            printf("child4: %d/%d=%d \n", a,b,a/b);
          }else{
            waitpid(pid,0,0);
            waitpid(pid2,0,0);
            waitpid(pid3,0,0);
            waitpid(pid4,0,0);
            printf("parent: done\n");
            
          }
        }
    }
  }
}
