#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>


int main (int argc, char* argv[])
{
  pid_t child_pid;
  printf ("ID de process du programme principal : %d\n", (int) getpid ());

  child_pid = fork ();

  if (child_pid != 0) {
    printf ("------------------------------------\n");
    printf ("je suis le processus parent, ID : %d\n", (int) getpid ());
    printf ("Identifiant du process fils : %d\n", (int) child_pid);
    printf ("------------------------------------\n");
  }
  else {
    printf ("************************************\n");
    printf ("je suis le process fils, ID : %d\n", (int) getpid ());
    printf ("************************************\n");
  }

  return 0;
}
