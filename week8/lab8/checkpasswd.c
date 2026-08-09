#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 256

#define SUCCESS "Password verified\n"
#define INVALID "Invalid password\n"
#define NO_USER "No such user\n"

int main(void) {
  char user_id[MAXLINE];
  char password[MAXLINE];
  int res = 0; 

  /* The user will type in a user name on one line followed by a password 
     on the next.
     DO NOT add any prompts.  The only output of this program will be one 
	 of the messages defined above.
     Please read the comments in validate carefully
   */

  if(fgets(user_id, MAXLINE, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  if(fgets(password, MAXLINE, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  
  // TODO
  
  // parent writes userid, passwd to child 

  int fd[2]; 
  pipe(fd); 
  res = fork(); 

  if (res == 0){
    close(fd[1]); 
    dup2(fd[0], stdin);

    execl("./rodoshi", "rodoshi", NULL); 
    perror("execl"); 
    exit(1); 
  }
  
  else if (res > 0){
    close(fd[0]); 

    write(fd[1], user_id, MAXLINE); 
    write(fd[1], password, MAXLINE); 
    close(fd[1]); 


    int status;
    wait(&status); 

    if (!WIFEXITED(status)){
      exit(1); 
    }
    
    int code = WEXITSTATUS(status); 
    if (code == 0){
      printf(SUCCESS); 
    } else if(code == 2){
      printf(INVALID); 
    } else if (code == 3) {
        printf(NO_USER);
    } else {
        exit(1);
    }
    

  } else {
    perror("fork"); 
    exit(1); 
  }
} 
