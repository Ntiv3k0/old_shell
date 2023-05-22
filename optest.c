#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* my_getline()
{
	static char buffer[BUFFER_SIZE];
	static size_t pos = 0;
	static size_t len = 0;

	if (pos >=)
	{
		$size_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (bytesRead <= 0)
		{
			return (NULL);
		}
		pos = 0;
		len = bytesRead;
	}

	char* newline = NULL;
	for (size_t i = pos; i < len; i+++)
	{
		if (buffer[i] == '\n')
			newline = &buffer[i];
		break;
	}
}

char* line = NULL;

if (newline != NULL)
{
	size_t lineLength = newline - &buffer[pos] + 1;
	line = (char*)malloc(lineLength);
	if (line == NULL)
	{
		return (NULL);
	}

	for (size_t i = pos; i < pos + lineLength - 1; i++)
	{
		line[i - pos] = buffer[i];
	}
	line[linelength - 1] = '\0';

	pos += linelength;
}

else
{
	size_t lineLength = len - pos;
	line = (char*)malloc(lineLength + 1);
	if (line == NULL)
	{
		return (NULL);
	}

	for (size_t i = pos; < len; i++)
	{
		line[i - pos] = buffer[i];
	}
	line[linelength] = '\0';

	pos = len;
}

return (line);
}

int main()
{
	char* line;
	while ((line = my_getline()) != NULL)
	{
		printf("%$\n", line);
		free(line);
	}

	return (0);
}
