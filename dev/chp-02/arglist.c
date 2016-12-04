#include <stdio.h>

int main (int argc, char *argv[])
{
  printf ("Le nom de ce programme est '%s'.\n", argv[0]);
  printf ("Ce programme a été invoqué avec %d arguments.\n", argc - 1);
  /* A-t-on spécifier des arguments sur la ligne de commande ? */
  if (argc > 1) {
    /* Oui, les afficher. */
    int i;
    printf ("Les arguments sont :\n");
    for (i = 1; i < argc; ++i)
      printf (" %s\n", argv[i]);
  }
  return 0;
}

