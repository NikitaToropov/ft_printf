/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjenae <fjenae@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 22:18:51 by fjenae            #+#    #+#             */
/*   Updated: 2019/05/29 17:59:51 by fjenae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i1;
	size_t	i2;
	size_t	i3;
	char	*trim;

	if (!s)
		return (NULL);
	i3 = ft_strlen(s);
	i1 = 0;
	i2 = 0;
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	if (i1 == i3)
		return (ft_strdup(""));
	while (s[i3] == ' ' || s[i3] == '\n' || s[i3] == '\t' || s[i3] == '\0')
		i3--;
	if (!(trim = (char *)malloc(sizeof(char) * (i3 - i1 + 2))))
		return (NULL);
	while (i1 <= i3)
		trim[i2++] = s[i1++];
	trim[i2] = '\0';
	return (trim);
}
