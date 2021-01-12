/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:24:38 by clbrunet          #+#    #+#             */
/*   Updated: 2020/08/26 14:32:10 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "structs.h"

void			ft_putstr_fd(int fd, char *str);
int				ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);
int				ft_atoi(char *str);
char			*ft_strdup(char *src);
char			**ft_split(char *str, char *charset);

t_file_content	*ft_create_elem(char *str);
int				ft_list_push_back(t_file_content **begin_list, char *str);
void			ft_list_clear(t_file_content *begin_list);

#endif
