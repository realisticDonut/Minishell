/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 10:31:17 by fharing           #+#    #+#             */
/*   Updated: 2021/11/11 13:09:49 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"
# include "../exec_cmds/exec_cmds.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

typedef struct s_flags
{
	int	quoation;
	int	s_quote;
	int	redirect;
	int	i;
}				t_flags;

typedef struct s_wflags
{
	int	i;
	int	x;
	int	q;
	int	dq;
	int	flag;
}				t_wflags;

void	ft_parse(char *s, t_list *history, t_list *env);
int		ft_free_stack(t_list *history);
void	ft_print_stack(t_list *list);
void	ft_print_stack(t_list *list);
int		ft_free_stack(t_list *list);
t_list	*ft_create_struct_env(char **env);
void	sigfunc(int sig);
char	**ft_echtoctl(void);
void	ft_init_shell(int argc, int *out, int *in, t_list	*env);
char	**ft_start(void);
void	ft_init_shell_say(char **argv, int *out, int *in, t_list	*env);
void	ft_free_structs_history(t_list *history, t_list *env_s);
char	*ft_prepare_string(char *s);
void	ft_skip_all_until_quotes(char *s, t_flags *flags);
void	ft_skip_all_until_singlequote(char *s, t_flags *flags);
void	ft_skip_whitspace_until_char(char *s, t_flags *flags);
void	ft_skip_whitspace(char *s, t_flags *flags);
void	ft_delete_whitespaces_end(char **s);
void	ft_delete_whitespaces(char **s);
void	ft_remove_whitspaces_strings_end(char *s);
void	ft_remove_whitspaces_strings(char *s);
void	ft_print(char **s);
void	ft_init_flags(t_flags *flags);
void	ft_setflags(t_flags *flags, char c);
void	ft_init_whitspace_flags(t_wflags *wflags);
int		ft_check_quotes(char *s);
void	ft_parse(char *s, t_list *history, t_list *env);
void	ft_init_flags(t_flags *flags);
void	ft_setflags(t_flags *flags, char c);
void	ft_skip_whitspace(char *s, t_flags *flags);
void	ft_skip_whitspace_until_char(char *s, t_flags *flags);
void	ft_print(char **s);
void	ft_skip_all_until_singlequote(char *s, t_flags *flags);
void	ft_skip_all_until_quotes(char *s, t_flags *flags);
char	*ft_prepare_string(char *s);
int		ft_check_quotes(char *s);
void	ft_init_whitspace_flags(t_wflags *wflags);
void	ft_remove_whitspaces_strings(char *s);
void	ft_remove_whitspaces_strings_end(char *s);
void	ft_delete_whitespaces(char **s);
void	ft_delete_whitespaces_end(char **s);
int		ft_is_space(char *s);

#endif
