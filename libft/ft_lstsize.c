/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcreus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:35:57 by mcreus            #+#    #+#             */
/*   Updated: 2023/04/27 12:35:59 by mcreus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Counts the number of nodes in a list */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst -> next;
		len++;
	}
	return (len);
}

/*#include <stdio.h> int main()
{
	char    str[] = "Rafael";
  char    str2[] = "23";
  t_list    *elem, *elem2;
  t_list *head;
	size_t i;

	elem = ft_lstnew((void *)str);
    
  elem2 = ft_lstnew((void *)str2);

  head = elem;
  elem -> next = elem2;
  elem2 -> next = NULL;

	i = ft_lstsize (head);
	printf("%d\n", i);
}*/
