#include "libft.h"

int	ft_isspace_no_space(int c)
{
	if (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
