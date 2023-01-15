#include"minitalk.h"

char	*bin_str(char *ch)
{
	char	*result;
	char	*str;
	int	index;
	int	i;
	int	limit;

	i = -1;
	limit = 0;
	str = ft_strdup(ch);
	result = ft_calloc(0, ft_strlen(str) * BYTE_SIZE + 1);
	if (!result)
		return (NULL);
	while (str[++i])
	{
		index = (i + 1) * BYTE_SIZE;
		result[index] = 0;
		while (--index >= limit)
		{
			result[index] = 48 + (str[i] & 1);
			str[i] = str[i] >> 1;
		}
		limit += BYTE_SIZE;
	}
	return (result);
}

int	str_bin(int ch)
{
	int	binary;
	int	num;
	int	topower;
	int	dec;

	topower = 0;
	dec = 0;
	binary = ch;
	while (binary)
	{
		num = binary % 10;
		num <<= topower;
		dec += num;
		topower++;
		binary /= 10;
	}
	return (dec);
}
