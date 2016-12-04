#include <stdio.h>
/* La variable ENVIRON contient l'environnement. */
extern char** environ;
int main()
{
  char** var;
  for (var = environ; *var != NULL; ++var)
    printf ("%s\ns", *var);
  return 0;
}
