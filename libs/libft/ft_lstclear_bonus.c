/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kposthum <kposthum@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 14:05:54 by kposthum      #+#    #+#                 */
/*   Updated: 2023/02/07 16:35:23 by kposthum      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		current = temp;
		temp = temp->nxt;
		ft_lstdelone(current);
	}
	*lst = NULL;
	free(*lst);
}
