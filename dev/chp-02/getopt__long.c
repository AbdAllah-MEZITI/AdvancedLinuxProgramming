#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
/* Nom du programme. */
const char* program_name;
/* Envoie les informations sur l'utilisation de la commande vers STREAM
(typiquement stdout ou stderr) et quitte le programme avec EXIT_CODE.
Ne retourne jamais. */

void print_usage (FILE* stream, int exit_code)
{
  fprintf (stream, "Utilisation : %s option [fichierentrée ...]\n", program_name);
  fprintf ( stream, 
	  " -h --help                        Affiche ce message.\n"
	  " -o --output filename             Redirige la sortie vers un fichier.\n"
	  " -v --verbos                      Affiche des messages détaillé.\n");

  exit (exit_code);
}

/* Point d'entrée du programme. ARGC contient le nombre d'éléments de la liste d'arguments ;
ARGV est un tableau de pointeurs vers ceux-ci.*/
int main(int argc, char* argv[])
{
  int next_option;
  /* Chaine listant les lettres valides pour les options courtes. */
  const char* const short_options = "ho:v";
  /* Tableau décrivant les options longues valides. */
  const struct option long_options[] = {
    { "help", 0, NULL, 'h'},
    { "output", 1, NULL, 'o'},
    { "verbose", 0, NULL, 'v'},
    { NULL, 0, NULL, 0} /* Requis à la fin du tableau. */
  };

  /* Nom du fichier vers lequel rediriger les sorties, ou NULL pour la sortie standard. */
  const char* output_filename = NULL;
  /* Indique si l'on doit affichier les messages détaillés. */
  int verbose = 0;
  /* Mémorise le nom du programme, afin de l'intégrer aux messages.
     Le no est contenu dans argv[0]. */
  program_name = argv[0];
  
  do {
    next_option = getopt_long (argc, argv, short_options, long_options, NULL);
    switch (next_option)
      {
      case 'h':
	print_usage (stdout, 0);
      case 'o':
	output_filename = optarg;
	break;
      case 'v':
	verbose = 1;
	break;
      case '?':
	print_usage (stderr, 1);
      case -1:
	break;
      default:
	abort ();
      }
  }
  while (next_option != -1);
  
  if (verbose) {
    int i;
    for (i = optind; i < argc; ++i)
      printf ("Argument : %s\n", argv[i]);
  }
  return 0;
}


