#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main()
{
	char	*temp;
	temp = (char *) malloc((5 + 1) * sizeof (char));
	if(temp == NULL)
		printf("%d", 1);
	return (0);
	//printf("%s", temp);
	//printf("%zu", ft_strlen(temp));
	//return (0);
}
