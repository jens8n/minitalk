/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebucoy <jebucoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:54:35 by jebucoy           #+#    #+#             */
/*   Updated: 2022/10/23 17:26:59 by jebucoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <unistd.h>


void	get_bitvalue(char c, pid_t pid);
void	getstr_bit(char *str, pid_t pid);
int		ft_atoi(const char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
// void	ft_putstr_fd(char *s, int fd);
// void	ft_putchar_fd(char c, int fd);

#endif