# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 11:38:18 by fharing           #+#    #+#              #
#    Updated: 2021/11/12 15:21:39 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
RM_D = rm -rf
CFLAGS = -lreadline $(LDFLAGS) $(CPPFLAGS)
NAME = minishell
LDFLAGS =
CPPFLAGS =
SRC = ./prompt/main.c ./exec_cmds/utils.c ./exec_cmds/exec_cmds.c ./parsing/parse_readline.c \
	./exec_cmds/redirect.c ./builtins/env.c ./builtins/pwd.c ./builtins/echo.c ./builtins/cd.c \
	./builtins/exit.c ./builtins/unset.c ./builtins/export.c ./builtins/get_env_variable.c \
	./builtins/cd_set_pwd.c ./builtins/builtins.c ./exec_cmds/heredoc.c ./exec_cmds/redirect_utils.c \
	./exec_cmds/convert_vars.c ./exec_cmds/convert_vars_utils.c ./prompt/init.c ./prompt/helper.c \
	./parsing/helper_pars.c ./parsing/helper_pars_2.c ./parsing/helper_pars_3.c ./exec_cmds/inits.c \
	./exec_cmds/cmd_format_utils.c ./exec_cmds/cmd_checks.c ./exec_cmds/redirect_manage_files.c \
	./exec_cmds/sigfunc_child.c ./exec_cmds/open_all_out.c

NAME_LIB = libft.a

#build everything
all: $(NAME)

#compile all files
$(NAME): LIB
	$(CC) $(CFLAGS) $(SRC) $(NAME_LIB) -lreadline -o $(NAME)

LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME_LIB)

#removes all *.o files
clean:
	$(RM) ./libft/*.o
	$(RM) temp


#removes all *.o files + executable
fclean: clean
	$(RM) $(NAME) $(NAME_LIB)
	$(RM) ./libft/libft.a

#removes all *.o files + executable and rebuild everything
re: fclean all
