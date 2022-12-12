#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
	t_list	*result;
	result = malloc(sizeof(t_list));
	result->content = content;
	result->next = NULL;
	return (result);
}
