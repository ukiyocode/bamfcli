#include <stdio.h>
#include <libbamf/libbamf.h>

void printHelp(char *progName) {
	printf("Usage: %s <window_id>\n", progName);
}

int main(int argc, char **argv) {

	if (argc != 2) {
        printHelp(argv[0]);
        return 1;
    }
    if (strcmp(argv[1],"--help") == 0) {
    	printHelp(argv[0]);
    	return 0;
    }

    guint32 window_id = strtoul(argv[1], NULL, 0);
    if (window_id == 0) {
        printf("Invalid <window_id>\n");
        return 1;
    }

    BamfMatcher *matcher = bamf_matcher_get_default();
    BamfApplication *app = bamf_matcher_get_application_for_xid(matcher, window_id);
    if (app == NULL) {
    	printf("Unable to match any aplication to this window ID: %u", window_id);
    	return 1;
    }

    const gchar *desktopf = bamf_application_get_desktop_file(app);
    if (desktopf == NULL) {
    	printf("The application doesn't seem to have a .desktop file.");
    	return 0;
    }

    printf("%s", desktopf);
	return 0;
}