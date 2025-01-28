/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:12:22 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 11:12:23 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(char **mat, int i);
static int	rows(char *s, char c);
static char	**init(char **mat, char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**mat;

	if (!s)
		return (0);
	mat = (char **)malloc(sizeof(char *) * (rows((char *)s, c) + 1));
	if (!mat)
		return (0);
	mat = init(mat, (char *)s, c);
	if (!mat)
		return (0);
	return (mat);
}

static char	**init(char **mat, char *s, char c)
{
	int	i;
	int	p_start;
	int	p_end;
	int	j;

	j = 0;
	i = 0;
	p_start = 0;
	p_end = 0;
	while (s[i])
	{
		while (s[i] == c)
			p_start = ++i;
		while (s[i] != c && s[i])
			p_end = ++i;
		if (p_start < p_end)
			mat[j] = ft_substr(s, p_start, p_end - p_start);
		if (p_start < p_end && !mat[j++])
		{
			clean(mat, j);
			return (0);
		}
	}
	mat[j] = 0;
	return (mat);
}

static void	clean(char **mat, int j)
{
	while (j-- > 1)
		free(mat[j - 1]);
	free(mat);
	return ;
}

static int	rows(char *s, char c)
{
	int	i;
	int	k;
	int	d;

	i = 0;
	k = 0;
	while (s[i] && c)
	{
		d = 0;
		while (s[i] == c)
			++i;
		while (s[i] != c && s[i])
		{
			i++;
			d++;
		}
		if (d)
			k++;
	}
	return (k);
}
