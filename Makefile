# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcedraz- <vcedraz-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 15:37:30 by vcedraz-          #+#    #+#              #
#    Updated: 2023/05/08 14:22:55 by vcedraz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors
HGREEN = \033[1;32m
RED = \033[0;31m
HRED = \033[1;31m
DEF_COLOR =	\033[0m
CYAN = \033[0;36m

# Define flags
CFLAGS = -w -pthread -g
INCLUDES = -Isrcs/include/
BLIB = blib.a

# Define the source and object file directories
SRCSDIR = srcs/mandatory/
BSRCSDIR = srcs/bonus/
OBJSDIR = objs/
BOBJSDIR = bobjs/
LIB = srcs/lib/lib.a

# Define the source and object files
SRCS = $(wildcard $(SRCSDIR)*.c)
BSRCS = $(wildcard $(BSRCSDIR)*.c)
OBJS = $(patsubst $(SRCSDIR)%.c, $(OBJSDIR)%.o, $(SRCS))
BOBJS = $(patsubst $(BSRCSDIR)%.c, $(BOBJSDIR)%.o, $(BSRCS))

all: lib $(OBJS)
	@rm -f error.log
	@make --no-print-directory execs
	@make --no-print-directory -C ..
	@cp -f ../push_swap .
	@make --no-print-directory run

lib:
	@make --no-print-directory -C srcs/lib

execs: $(OBJS)
	@$(foreach file,$(OBJS), \
		if [ $(file) -nt $(patsubst $(OBJSDIR)%.o,%,$(file)) ] || \
		   [ ! -f $(patsubst $(OBJSDIR)%.o,%,$(file)) ] || \
		   [ $(LIB) -nt $(file) ]; then \
			printf "Compiling $(file) -> "; \
			printf "$(HGREEN)$(patsubst $(OBJSDIR)%.o,%,$(file))\n$(DEF_COLOR)"; \
			$(CC) $(CFLAGS) $(INCLUDES) $(file) $(LIB) -o $(patsubst $(OBJSDIR)%.o,%,$(file)); \
		fi; \
	)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: lib $(BOBJS)
	@make --no-print-directory -C ..
	@make --no-print-directory -C .. bonus
	@cp -f ../push_swap .
	@cp -f ../checker .
	@make --no-print-directory bexec
	./basic_bonus

bexec: $(BLIB)
	@$(CC) $(CFLAGS) $(INCLUDES) $(BLIB) $(LIB) -o basic_bonus
	@printf "$(CC) $(CFLAGS) $(INCLUDES) $(BLIB) $(LIB) -o $(HGREEN)basic_bonus$(DEF_COLOR)\n\n";

$(BOBJSDIR)%.o: $(BSRCSDIR)%.c
	mkdir -p $(BOBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BLIB): $(BOBJS)
	ar rcs $(BLIB) $?

run:
	@printf "$(CYAN)running tests with valgrind on quiet mode $(DEF_COLOR)\n\n";
	# ./error_management
	# @printf "\n\n";
	# ./identity_test
	# @rm -f tmp*
	# @rm -rf log_files
	# @mkdir -p log_files
	@./memory_tests
	@./exaustive_test100
	./test5
	@cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test5.log && rm tmp*
	@./analyse_log.sh test5.log
	@mv test5.log ./log_files
	./test100
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test100.log && rm tmp*
	@./analyse_log.sh test100.log
	@mv test100.log ./log_files
	./test500
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test500.log && rm tmp*
	@./analyse_log.sh test500.log
	@mv test500.log ./log_files

clean:
	@rm -rf objs
	@rm -rf bobjs
	@rm -f tmp*
	@make --no-print-directory -C srcs/lib clean
	@rm -f $(BLIB)

fclean: clean
	@rm -rf ./log_files
	@rm -f test* push_swap checker memory_tests basic_bonus error_management identity_test exaustive* error.log
	@make --no-print-directory -C srcs/lib fclean

re: fclean all
