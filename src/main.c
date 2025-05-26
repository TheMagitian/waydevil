#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/colors.h"

extern void display_usage();
extern char *get_wm_env_var();

int main(int argc, char **argv) {
  int i;
  char *wm = (char *)malloc(20 * sizeof(char));
  char *f_path = (char *)malloc(40 * sizeof(char));
  int default_config = 0;
  
  if (argc < 2) {
    wm = argv[1];
	default_config = 1;
  }

  wm = get_wm_env_var();
  printf("%s\nDetected WM:%s %s%s%s\n", BOLD, RESET, GREEN, wm, RESET);
  if (default_config) {
	f_path = "~/.config/waybar/";
	printf("%s%sUsing Waybar's config file located at %s%s%s%s", RESET, ITALIC, RESET, GREEN, f_path, RESET);
  }

  if (!default_config) {
	for (i=1; i<argc; i++) {
	  if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
		display_usage();
		return 0;
	  }
	  
	  char *f_path = argv[i + 1];

      if (!strcmp(argv[i], "--config") && !access(f_path, F_OK)) {
        printf("%s%sUsing Waybar's config file located at %s%s%s%s", RESET, ITALIC, RESET, GREEN, f_path, RESET);
      } else {
        if (access(f_path, F_OK) == 0) {
          printf("%sEncountered error while accessing config file.%s", RED, RESET);
          return -1;
        } else {
		  display_usage();
		  printf("%sInvalid Usage.%s Consult %swaydevil --help%s for more information.", BOLD, RESET, ITALIC, RESET);
        }
      }
    }
  }

  /* free(wm); */
  return 0;
}
