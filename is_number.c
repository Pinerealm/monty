/**
 * is_number - checks if a string is a number
 * @str: the string to check
 *
 * Return: 1 if it is a number, 0 otherwise
 */

int is_number(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
