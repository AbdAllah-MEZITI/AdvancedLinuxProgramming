#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
  printf ("The ID of the process is %d\n", (int) getpid () );
  printf ("The ID of the father process is %d\n", (int) getppid() );

  return 0;
}

