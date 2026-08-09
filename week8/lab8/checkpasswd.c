#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAXLINE 256

#define MAX_PASSWORD 10

#define SUCCESS "Password verified\n"
#define INVALID "Invalid password\n"
#define NO_USER "No such user\n"

int main(void) {
  char user_id[MAXLINE];
  char password[MAXLINE];
  int res = 0; 
  int status; 

  /* The user will type in a user name on one line followed by a password 
     on the next.
     DO NOT add any prompts.  The only output of this program will be one 
	 of the messages defined above.
     Please read the comments in validate carefully
   */

  if(fgets(user_id, MAX_PASSWORD, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  if(fgets(password, MAX_PASSWORD, stdin) == NULL) {
      perror("fgets");
      exit(1);
  }
  
  // TODO

  // child process needs to validate the login
  // parent process will give the info to child
  // child needs to run the validate program to see what it returns

  // the only way to communicate is through a pipe

  int fd[2]; 
  if (pipe(fd) == -1){
    perror("pipe"); 
    exit(1); 
  } 


  res = fork(); 

  if (res == 0){
    //child process has access to the userid and passwd so you might think ok lets just redirect from stdin to these var
    // but, dup2 only works with file descriptors and also after execl you wont have acess to the programs var anymore
    // so we use a pipe where parent writes that to teh child
    

    close(fd[1]); 
    //redirect from stdin to user info
    if (dup2(fd[0], STDIN_FILENO) == -1){
      perror("dup2"); 
      exit(1); 
    } 
    close(fd[0]); 
    
    //replace this program with the executable
    // note: we ran gcc validate.c -0 rodoshi
    execl("./rodoshi", "rodoshi", NULL); 
    //if this part is reached - that means execl didnt acc replace the program
    perror("execl"); 
    exit(1); 
    
  }

  else if(res > 0){
    //parent

    close(fd[0]); 
    write(fd[1], user_id, MAX_PASSWORD); 
    write(fd[1], password, MAX_PASSWORD); 
    close(fd[1]); 


    wait(&status); 

    if (WIFEXITED(status)){

      int code = WEXITSTATUS(status); 

      if (code == 0){
        printf(SUCCESS);  
        exit(0); 
      }

      if (code == 1){
        exit(0);
      }

      if (code == 2){
        printf(INVALID);  
        exit(0); 
      }

      if (code == 3){
        printf(NO_USER);  
        exit(0); 
      }

    }
    else{
      perror("process not terminated successfully"); 
      exit(1); 
    }
    
  }
  else{
    perror("fork"); 
    exit(1); 
  }
  
} 