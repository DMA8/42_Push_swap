/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spilt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:23:22 by syolando          #+#    #+#             */
/*   Updated: 2022/05/11 22:23:23 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_if_fail(char **to_free)
{
	int	ind;

	ind = 0;
	while (to_free[ind])
	{
		free(to_free[ind]);
		ind++;
	}
	free(to_free);
}

static int	cnt_wrds(char const *s, char c)
{
	int	ind;
	int	word_conter;

	ind = 0;
	word_conter = 0;
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		if (s[ind] != '\0')
			word_conter++;
		while (s[ind] && (s[ind] != c))
			ind++;
	}
	return (word_conter);
}

static char	*get_word(char const *s, int n, char **to_free)
{
	char	*extracted_word;
	int		ind;

	ind = 0;
	extracted_word = (char *)malloc(sizeof(char) * n + 1);
	if (extracted_word == NULL)
	{
		free_if_fail(to_free);
		return (NULL);
	}
	while (ind < n)
	{
		extracted_word[ind] = s[ind];
		ind++;
	}
	extracted_word[ind] = 0;
	return (extracted_word);
}

static int	init(int *a, int *b, char const *s)
{
	*a = 0;
	*b = 0;
	if (!s)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		ind;
	int		sind;
	int		nwrd;
	char	**splt;

	if (!init(&ind, &nwrd, s))
		return (NULL);
	splt = (char **)malloc(sizeof(char *) * (cnt_wrds(s, c) + 1));
	if (splt == NULL)
		return (NULL);
	while (s[ind])
	{
		while (s[ind] == c)
			ind++;
		sind = ind;
		while (s[ind] && s[ind] != c)
			ind++;
		if (ind > sind)
		{
			splt[nwrd] = get_word(s + sind, ind - sind, splt);
			nwrd++;
		}
	}
	splt[nwrd] = NULL;
	return (splt);
}
