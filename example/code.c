#include <stddef.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


FILE *xfopen(char *filename, char *mode)
{
	FILE *f = fopen(filename, mode);
	if (f == NULL) {
		fprintf(stderr, "%s: %s\n", strerror(errno), filename);
		abort();
	}
	return f;
}


int main(int argc, char **argv)
{
	FILE *f;

	puts("Hello, World!");
	fputs("I am a busy program, and I am tired of that!\n", stderr);

	f = xfopen("my_args_in_reverse.txt", "w");
	for (int i = argc - 1; i > 0; i--) {
		fputs(argv[i], f);
		fputc('\n', f);
	}
	fclose(f);

	f = xfopen("my_stdin_copy.txt", "w");
	for (int c; (c = getchar()) != EOF;) {
		fputc(c, f);
	}
	fclose(f);

	FILE *src = xfopen("file.txt", "r");
	f = xfopen("copy.txt", "w");
	for (int c; (c = fgetc(src)) != EOF;) {
		fputc(c, f);
	}
	fclose(src);
	fclose(f);

	char buf[] = "Hello, World!\n";
	f = xfopen("file.bin", "wb");
	fwrite(buf, sizeof(*buf), sizeof(buf) / sizeof(*buf) - 1, f);
	fclose(f);

	f = xfopen("env_report.txt", "w");
	if (getenv("INVARIANT_COVARIANT_CONTRAVARIANT") != NULL) {
		fputs("VARVARVAR presented!\n", f);
	}
	fclose(f);

	return 0;
}



