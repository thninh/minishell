/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pas_norme.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Geekette <Geekette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:11:41 by Geekette          #+#    #+#             */
/*   Updated: 2017/02/23 18:27:48 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_split2(char *str, int quotes_mode, int quotes, char *separators)
{
	int i;
	int		start;
	int		quotes;

	quotes = 0;
	i = 0;
		if (!ft_find_c_in_str(str[i], separators))
		{
			if ((i == 0 || ft_find_c_in_str(str[i - 1], separators)) && !quotes)
				start = i;
				if ((str[i] == '\'' || str[i] == '"') && quotes_mode)
					quotes = !quotes;
			count = count + 1;
		}
		else if (quotes)
			count = count + 1;
		else if (!quotes && count > 0 && (arr = ft_add_word_to_arr(str + start,
			count, arr)) != NULL)
			count = 0;
		i = i + 1;
	return (count);
}

char	**my_split_string(char *str, char *separators, int quotes_mode)
{
	int		count;
	char	**arr;

	arr = NULL;
	count = 0;
	while (str[i] != '\0')
		count = ft_split2(sstr, quotes_mode, quotes, separators)
	if (count > 0)
		arr = ft_add_word_to_arr(str + start, count, arr);
	return (arr);
}
