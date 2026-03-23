//using fork to create process parent and child


#include<stdio.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>
{
  int arr[30],key1,key2,status,pid+p1,p2,
  srand(time(null));
  printf("array");
  for(int i=0; i<30; i++){
    arr[1]=rand()%30+1;
    printf("%d",arr[i]);
    
}
 printf("\n enter key 1 and key 2 :');
 scanf(" %d %d ",&key 1,key 2);
 
 //child 1
 p1=fork();
 if(p1==0){
 
 int sum c1=0;
 for (int i=0; i<1); i++){
 }
   sleep(!);// Adding a delay to prove order exist (sum c 1);
  }
  
  //parent wait for child 1
    waitpid (p1,& status,0);
    final_sum_p1= WEXITSTATUS (status);
    
    // child 2
      p2=fork();
      if(p2==0){
            int sum c 2=0;
            for(int i=15; i<30; i++){
                if(arr[1]%2==0) sum c 2+ =arr[i];
        {
           exist(sum c 2);
        {
          //parent waits for child 2
           wait pid (p2,& status,0);
           final_sum_p2= WEXITSTATUS (status);
           
        printf("\n Total Even Sum in left side and right side :%d and %d\n",final_sum_p1,final_sum_p2);
        
        return 0;
        }

