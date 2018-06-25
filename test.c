/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaporoz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:44:18 by azaporoz          #+#    #+#             */
/*   Updated: 2018/06/22 16:44:19 by azaporoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_list_push(t_thread **list, int i)
{
	t_thread *cp;

	cp = *list;
	while (cp->next)
		cp = cp->next;
	cp = (t_thread*)malloc(sizeof(t_thread));
	cp->y = i;
	cp->next = NULL;
}

void f(t_thread **src)
{
	t_thread *list;

	list = (t_thread*)malloc(sizeof(t_thread));
	list->y = 0;
	list->next = (t_thread*)malloc(sizeof(t_thread));
	list->next->y = 1;
	list->next->next = (t_thread*)malloc(sizeof(t_thread));
	list->next->next->y = 2;
	list->next->next->next = (t_thread*)malloc(sizeof(t_thread));
	list->next->next->next->y = 3;
	list->next->next->next->next = NULL;
	*src = list;
}

void f2(t_thread **head, int data)
{
   t_thread *link;
   link = (t_thread*)malloc(sizeof(t_thread));
   link->y = data;
   link->next = *head;
   *head = link;
}

int main()
{
	t_thread *list;
    list = (t_thread*) malloc(sizeof(t_thread));
	list->y = 228;
	list->next = NULL;
	for(int i = 0; i < 5; i++)
		f2(&list, i);
	while (list)
	{
		printf("HUY%d\n", list->y);
		list = list->next;
	}
	return (0);
}
