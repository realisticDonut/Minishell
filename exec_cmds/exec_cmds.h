/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agebert <agebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 11:55:47 by fharing           #+#    #+#             */
/*   Updated: 2021/11/12 15:35:39 by agebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMDS_H
# define EXEC_CMDS_H

# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../includes/builtins.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>

typedef struct s_commands
{
	char	**cmd_paths;
	char	**cmds;
	char	*current_cmd_str;
	char	**current_cmd_lst;
	char	*current_cmd_path;
	int		i;
}				t_commands;

typedef struct s_files
{
	int		fd_old;
	int		fd_save_in;
	int		fd_save_out;
	char	*file1;
	char	*file2;
	int		fd_pipe[2];
	int		pid;
	int		save_out;
	int		in_file_valid;
	int		fd_temp_heredoc;
	int		out_file_valid;
}				t_files;

typedef struct s_redirect
{
	int	str_pos_red_in;
	int	str_pos_red_out;
	int	red_count;
	int	str_pos;
}				t_redirect;

typedef struct s_vars
{
	char	*var_value;
	char	*var_name;
	char	*newcmd;
	int		var_size;
	int		f_quote;
	int		f_quote_double;
	int		count;
	int		x;
}				t_vars;

int		get_input_and_init(char **input, t_list *env,
			t_commands *commands, t_files *files);
void	free_structs(t_commands *commands);
int		check_input(int argc);
char	**get_cmd_paths(t_list *env);
int		init_files(t_files *files);
char	*check_command(char *command, t_commands *commands);
void	execute_child(t_files *files, t_commands *commands, t_list *env);
void	execute_parent(t_files *files);
int		exec_cmds(char **input, t_list *env);
char	*set_redirects(t_commands *commands, t_files *files,
			int cmd_count, int *exit_status);
int		redirect(t_files *files, t_redirect *redirects, int *exit_status);
char	*read_red_file_name(char redirect_char, int str_pos, char *command);
char	get_rev_redirect_char(char redirect_char);
int		count_chain_chars(char *str, int str_pos);
int		get_last_red_pos(char *str, char c);
char	*remove_redirects(char *command);
char	**ft_linked_to_string(t_list *env);
void	heredoc_readline(char *delim, int fd);
int		heredoc(char *delim, t_files *files);
void	heredoc_loop(t_commands *commands, t_files *files,
			t_redirect *redirects, int *exit_status);
int		get_heredoc_pos(char *cmd, t_redirect *redirects);
char	*convert_vars(char *cmd, t_list *env, int exit_status);
char	*convert_vars(char *cmd, t_list *env, int exit_status);
int		count_chars_env_list(t_list *env);
void	init_t_vars(t_vars *vars, t_list *env);
void	free_vars(t_vars *vars);
int		get_input_and_init(char **input, t_list *env,
			t_commands *commands, t_files *files);
int		errno_to_exit(void);
void	remove_quotes_from_cmds(t_commands *commands, int *i);
void	convert_vars_and_set_cmds(t_commands *commands, t_list *env,
			 int exit_status, int i);
void	get_red_str(t_commands *commands, t_files *files,
			 int cmd_count, int *exit_status);
void	split_cmds_and_paths(t_commands *commands);
void	sigfunc_child(int sig);
void	check_if_builtin(t_files *files, t_commands *commands,
			 t_list *env, int *exit_status);
int		check_out_file_valid(t_commands *commands, t_files *files, int *i);
char	**copy_str_list(char **old_list, char **env);
void	init_t_redirect(t_redirect *redirects);
int		check_file_access(char *filename, int *exit_status);
void	open_all_out(t_files *files, t_commands *commands,
			int *exit_status, t_redirect *redirects);
int		open_append_trunc(t_commands *commands, char *filename,
			int i, t_files *files);
void	get_file_names(t_files *files, t_commands *commands,
			t_redirect *redirects);
void	check_quotes(int *f_quote_d, int *f_quote_s, char *command);
void	init_remove_redirects(int *count, int *i,
			int *f_quote_d, int *f_quote_s);
void	init_open_all_out(int *i, int *f_quote);
void	sigfunc_child(int sig);
int		check_open(int i, t_commands *commands,
			t_files *files, int *exit_status);

#endif
