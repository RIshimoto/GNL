#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"
//#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd[1024];
	char *line;
	int i;
	int l;
	int r;


	if (argc > 1)
		printf("%s\n", *argv);

	int j;
	j = 0;
	fd[j++] = open("test/a.txt", O_RDONLY);
	fd[j++] = open("test/b.txt", O_RDONLY);
	fd[j++] = open("test/c.txt", O_RDONLY);
	fd[j++] = open("test/d.txt", O_RDONLY);

	l = 0;
	r = rand() % 4; 
	while (0 < (i = get_next_line(fd[r], &line)))
	{
		printf("%d return flag : %d : '%s'\n", l, i, line);
		l++;
		free(line);
		line = NULL;
		r = rand() % 4; 
	}
	printf("%d return flag : %d : '%s'\n", l, i, line);
	free(line);
	line = NULL;
	return 0;
}
