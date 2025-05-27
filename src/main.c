#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/colors.h"

extern void display_usage();
extern char *get_wm_env_var();

static char *default_path = "~/.config/waybar/config";

int main(int argc, char **argv) {
  int i;
  char *wm = get_wm_env_var();
  char *f_path = default_path;
  
  for (i=0; i<argc; i++) {
	if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
	  display_usage();
	  return 0;
	}
  }

  if (argc==2) {
	if (access(argv[1], F_OK)==0) {
	  f_path = argv[1];
	} else {
	  /* if (wm) free(wm); */
	  wm = strdup(argv[1]);
	}
  }

  else if (argc==3){
	/* if (wm) free(wm); */
	wm = argv[1];
	f_path = argv[2];
  }

  printf("%s\nDetected WM:%s %s%s%s\n", BOLD, RESET, GREEN, wm, RESET);
  printf("%s%sUsing Waybar's config file located at %s%s%s%s", RESET, ITALIC, RESET, GREEN, f_path, RESET);

  return 0;
}
