#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	char	*text;
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%i ---> ", get_next_line(fd, &text));
	printf("%s\n", text);
	free(text);
	printf("%i ---> ", get_next_line(fd, &text));
        printf("%s\n", text);
	free(text);
	printf("%i ---> ", get_next_line(fd, &text));
        printf("%s\n", text);
	free(text);
	printf("%i ---> ", get_next_line(fd, &text));
        printf("%s\n", text);
	free(text);
	printf("%i ---> ", get_next_line(fd, &text));
        printf("%s\n", text);
	free(text);
	close(fd);
	return (0);
}