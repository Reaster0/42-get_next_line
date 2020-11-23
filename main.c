#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	char	*line;
	int		file;
	int		res;
ft_putstr_fd("\nle programme a commence\n", 1);
	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
	}
	else
	{
		file = open("test.txt", O_RDONLY);
	}
	res = 1;
	while (res > 0)
	{
		res = get_next_line(file, &line);
		if (res != -1)
		{
			printf(res ? "%s\n" : "%s", line);
			free(line);
		}
		else
		{
			printf("error -1");
			return (0);
		}
	}
	return (0);
}
