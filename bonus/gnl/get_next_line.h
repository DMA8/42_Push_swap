/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syolando <syolando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 01:16:03 by syolando          #+#    #+#             */
/*   Updated: 2022/05/12 17:35:11 by syolando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		strlen_mod(const char *s);
int		check_inputs_failed(char *dest, char *buff);
void	count_len_for_two_var(int *len1, int *len2, char *dest, char *buff);
int		nl_index(char *str);

#endif
