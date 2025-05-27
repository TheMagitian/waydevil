#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/colors.h"


void display_usage() {
	printf("\n%sUsage%s: %swaydevil%s %s[WM] [filepath]%s\n\n", BOLD, RESET, RED, RESET, YELLOW, RESET);
	printf("%sArgs%s:\n", BOLD, RESET);

	printf("\n  %s--help (-h)%s ", UNDERLINE, RESET);
	printf("Display this help page.\n\n");
}

char *get_wm_env_var() {
  /**
   * Requires XDG_CURRENT_DESKTOP to be set correctly.
   * It's intended to be a failsafe in case the user doesn't provide
   * the optional argument.
   */
  char *wm = getenv("XDG_CURRENT_DESKTOP");
  return wm;
}
