/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:08:46 by fjenae            #+#    #+#             */
/*   Updated: 2019/09/25 21:12:02 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static      t_list      *ft_struct_malloc(t_list *root, int m)
{
    root = (t_list*)malloc(sizeof(t_list));
    root->content = &m;
    root->content_size = sizeof(m);
    return (root);
}

int     main()
{
    t_list  *root;
    t_list  *omega;
    int     m;
    int     *temp_m;
    size_t  temp_size;

    root = NULL;

    m = 15;
    if (!root)
        ft_struct_malloc(root, m);

    omega = root;
    while (m != 0)
    {
        omega->content = &m;
        omega->content_size = sizeof(m);
        omega->next = (t_list*)malloc(sizeof(t_list));
        m--;
        omega->next->content = &m;
        omega->next->content_size = sizeof(m);
    }
    omega = root;
    m = 15;
    while (m != 0)
    {
        temp_m = omega->content;
        temp_size = omega->content_size;
        printf("content %d\n", *temp_m);
        printf("content size %d\n", (int)temp_size);
        omega = omega->next;
    m--;
    }
    return (0);
}