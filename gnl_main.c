#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"
//#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int i;
	//int r;
	int l;
	char *line;

	if (argc > 1)
		printf("%s\n", *argv);

	/*
	int j;
	j = 0;
	fd[j++] = open("a.txt", O_RDONLY);
	fd[j++] = open("b.txt", O_RDONLY);
	fd[j++] = open("c.txt", O_RDONLY);
	fd[j++] = open("d.txt", O_RDONLY);
	*/

	fd = open("a.txt", O_RDONLY);
	//fd = open("bar.txt", O_RDONLY);
	//fd = open("normal.txt", O_RDONLY);
	//fd = open("only_newline.txt", O_RDONLY);
	//fd = open("fewchar_perline.txt", O_RDONLY);
	//fd = open("few.txt", O_RDONLY);
	//fd = open("long_line.txt", O_RDONLY);
	//fd = open("longtext.txt", O_RDONLY);
	//fd = open("64bit_paragraph.txt", O_RDONLY);
	//fd = open("64bit_line.txt", O_RDONLY);
	//fd = open("special.txt", O_RDONLY);
	//fd = 10;

	l = 0;
	//r = 0;
	//r = rand() % 1; 
	while (0 < (i = get_next_line(fd, &line)))
	{
		printf("%d return flag : %d : '%s'\n", l, i, line);
		l++;
		free(line);
		line = NULL;
	//	r = rand() % 1; 
	}
	printf("%d return flag : %d : '%s'\n", l, i, line);
	free(line);
	line = NULL;
	return 0;
}
