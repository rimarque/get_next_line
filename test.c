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

char	*ft_calloc(size_t nmemb)
{
	char	*dst;
	size_t	n;

	n = nmemb * sizeof(char);
	dst = (char *) malloc(n);
	if (!dst)
		return (0);
	while (--n)
		dst[n] = '\0';
	return (dst);
}

int	main()
{
	char	*temp;
	temp = ft_calloc(5);
	/*if(temp == NULL)
		printf("%d", 1);
	return (0);*/
	printf("%d%d%d%d%d", temp[0], temp[1], temp[2], temp[3], temp[4]);
	//printf("%zu", ft_strlen(temp));
	//return (0);
}
