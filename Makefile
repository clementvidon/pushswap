# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvidon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 12:21:39 by cvidon            #+#    #+#              #
#    Updated: 2022/04/19 15:51:08 by cvidon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== [ Project files ]

# TODO set name
PREFIX			= push_swap
NAME			= $(PREFIX)
NAME_CHECKER	= checker

# TODO set libriaires
LIB_DIR		= lib
LIB			= libft
LIB			:= $(LIB:%=$(LIB_DIR)/%)

# TODO set frameworks
FRAMEWORK	=

INC_DIR		= include
INC			= $(INC_DIR) \
			  $(LIB:%=%/$(INC_DIR)) $(LIB)

# TODO set sources
SRC_DIR		= src
SRCS		= main.c				\
			  parse_args.c			\
			  check_args.c			\
			  algo/pre_sort.c		\
			  algo/moves.c			\
			  algo/sort.c			\
			  algo/smallsort.c		\
			  algo/id.c				\
			  algo/leader.c			\
			  algo/costs.c			\
			  operations_1.c		\
			  operations_2.c		\
			  listutils_1.c			\
			  listutils_2.c			\
			  listutils_3.c			\
			  char_listutils.c		\
			  security.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

SRCS_CHECKER = checker/main.c			\
			   parse_args.c				\
			   check_args.c				\
			   checker/checker.c		\
			   operations_1.c			\
			   operations_2.c			\
			   listutils_1.c			\
			   listutils_2.c			\
			   listutils_3.c			\
			   char_listutils.c			\
			   security.c
SRCS_CHECKER := $(SRCS_CHECKER:%=$(SRC_DIR)/%)

OBJ_DIR 		= obj
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_CHECKER	= $(SRCS_CHECKER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ========== [ Compiler flags ]

CC			= gcc

# TODO set extra compiler flags
CFLAGS		=
CFLAGS		:= $(CFLAGS) -Wall -Wextra -Werror -Wconversion -Wsign-conversion

# TODO set extra linker flags
CPPFLAGS	=
CPPFLAGS	:= $(CPPFLAGS) $(INC:%=-I%)
LDFLAGS		=
LDFLAGS 	:= $(LDFLAGS) $(LIB:%=-L%) $(FRAMEWORK)
LDLIBS		=
LDLIBS		:= $(LDLIBS) $(LIB:$(LIB_DIR)/lib%=-l%)

# ========== [ Misc ]

RM		= rm -rf
MAKE	= make --silent --jobs --directory

# ========== [ Recipe ]

.PHONY: all sani checker clean fclean norm update re test leak

all: $(NAME)

sani: CFLAGS := $(CFLAGS) -fsanitize=address,undefined,signed-integer-overflow -g3
sani: $(NAME)
sani: checker

$(NAME): $(OBJS)
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@$(ECHO)"$(G)created $(END)$(NAME)\n"

checker: $(OBJS_CHECKER)
	@echo -n "\r\033[K"
	@for f in $(LIB); do $(MAKE) $$f --no-print-directory; done
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(OBJS_CHECKER) $(LDLIBS) -o $(NAME_CHECKER)
	@$(ECHO)"$(G)created $(END)$(NAME_CHECKER)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@[ ! -d $(@D) ] && mkdir -p  $(@D) || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@$(ECHO)"$(G)created $(END)$@"

clean:
	@for f in $(LIB); do $(MAKE) $$f clean --no-print-directory; done
	@[ -d $(OBJ_DIR) ] \
		&& $(RM) $(OBJ_DIR) && $(ECHO)"$(R)removed$(END) $(OBJ_DIR)/\n" || true

fclean: clean
	@for f in $(LIB); do $(MAKE) $$f fclean --no-print-directory; done
	@[ -f $(NAME) ] \
		&& $(RM) $(NAME) && $(ECHO)"$(R)removed$(END) $(NAME)\n" || true
	@[ -f $(NAME_CHECKER) ] \
		&& $(RM) $(NAME_CHECKER) && $(ECHO)"$(R)removed$(END) $(NAME_CHECKER)\n" || true

norm:
	@for f in $(LIB); do $(MAKE) $$f norm --no-print-directory; done
	@norminette -R CheckForbiddenSourceHeader $(SRCS) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) sources\n"
	@norminette -R CheckDefine $(INC_DIR) | grep -v "OK" || true
	@$(ECHO)"$(G)checked$(END) headers\n"

update:
	@git pull
	@git submodule update
	@$(ECHO)"$(G)updated$(END)\n"

re : fclean all

# ========== [ Tests ]

test: fclean sani
	@while true; do ARG=$$(shuf -z -i 1-999 -n 500 | tr '\0' ' '); ./push_swap $$ARG | wc -l; done | tee -a test/test_output

leak: re
	@while true; do ARG=$$(shuf -z -i 1-999 -n 500 | tr '\0' ' '); valgrind -q --leak-check=yes --show-leak-kinds=all ./push_swap $$ARG | wc -l; done | tee -a test/leak_output

# ========== [ Stdout ]

R		= $(shell tput setaf 1)
G		= $(shell tput setaf 2)
Y		= $(shell tput setaf 3)
B		= $(shell tput setaf 4)
M		= $(shell tput setaf 5)
C		= $(shell tput setaf 6)
W		= $(shell tput setaf 7)
K		= $(shell tput setaf 8)
END		= $(shell tput sgr0)
ECHO	= echo -n "\r\033[K$(PREFIX): "
