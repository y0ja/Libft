#include "libft.h"

wchar_t	*ft_wcscat(wchar_t *s1, const wchar_t *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);	
}
