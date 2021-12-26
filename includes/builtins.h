/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:04:29 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 15:58:21 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/libft.h"
# include "../includes/shell.h"
# include <sys/wait.h>

typedef struct s_var_echo
{
	int		i;
	int		quotes;
	int		end;
	int		x;
	char	c;
}				t_var_echo;

int		ft_env(t_list *env);
int		ft_pwd(void);
int		ft_echo(char *in);
int		ft_exit(char *cmd_args, int *exit_status);
int		ft_unset(char *s, t_list *env);
char	*ft_get_var(char *s);
int		ft_export(char *s, t_list *env);
char	*ft_get_env_var(char *s, t_list *env);
char	*ft_get_var(char *s);
int		call_builtins(char *cmd, t_list *env, int *exit_status);
int		ft_print_error(void);
int		ft_cd(const char *path, t_list *env);
void	ft_set_old_pwd(char *old, t_list *env);
void	ft_set_pwd(t_list *env);
char	*ft_strcat(char *a, char *b);

#endif
