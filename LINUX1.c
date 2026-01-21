
# include < stdio .h >
# include < stdlib .h >
# include < unistd .h >
# include < sys / wait .h >
# include < time .h >
int main () {
int arr [30] , key1 , key2 , status ;
pid_t p1 , p2 ;
srand ( time ( NULL ) ) ;
printf ( " Array : " ) ;
for ( int i = 0; i < 30; i ++) {
arr [ i ] = rand () % 50 + 1;
printf ( " % d " , arr [ i ]) ;
}
printf ( " \ n \ nEnter Key 1 and Key 2: " ) ;
scanf ( " % d % d " , & key1 , & key2 ) ;
// Child 1
p1 = fork () ;
if (p1 ==0) {
    int count =0;
    for(int i=0;i <30;i++){
    if (arr[i]==key1)
       count++;
}
   exist(count);
  } 
// Parent waits for Child 1
waitpid ( p1 , & status , 0) ;
int res1 = WEXITSTATUS ( status ) ;
// Child 2
p2 = fork () ;
if (p2== 0) {
    int count =0;
    for(int i=0;i < 30;i++){
    if (arr[i] == key2)
     count++;
     }
     exist(count);
     }
// Parent waits for Child 2
waitpid ( p2 , & status , 0) ;
int res2 = WEXITSTATUS ( status ) ;
   printf("\nkey %d found %d times", key1,
   res1);
   printf("\nkey %d found %d times\n",key2,
   res2);
return 0;
}

