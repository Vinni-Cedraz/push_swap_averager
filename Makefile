#Colors
RED = \033[0;31m
HRED = \033[1;31m
HGREEN = \033[1;32m
HYELLOW = \033[1;33m
HBLUE = \033[1;34m
DEF_COLOR =	\033[0m
CYAN = \033[0;36m

# Define flags
CFLAGS = -w -pthread -O3
INCLUDES = -Isrcs/include/
BLIB = blib.a

# Define the source and object file directories
VPATH = srcs/mandatory/
BSRCSDIR = srcs/bonus/
ODIR = objs/
BOBJSDIR = bobjs/
LIB = srcs/lib/lib.a

# Define the source and object files
SRCS = $(wildcard $(VPATH)*.c)
BSRCS = $(wildcard $(BSRCSDIR)*.c)
OBJS = $(patsubst $(VPATH)%.c, $(ODIR)%.o, $(SRCS))
BOBJS = $(patsubst $(BSRCSDIR)%.c, $(BOBJSDIR)%.o, $(BSRCS))

all: pre_all
	@make --no-print-directory pre_all
	@make --no-print-directory run

pre_all: lib $(OBJS)
	@rm -f error.log
	@make --no-print-directory execs
	@if [[ -f ../Makefile ]]; then \
		make --no-print-directory -C ..; \
	else \
		printf "\n$(HRED)ERROR: RTFM: The push_swap_averager must be placed inside of your push_swap project root directory\n$(DEF_COLOR)\n"; \
		printf "\n$(HBLUE)ERROR: RTFM: The push_swap_averager must be placed inside of your push_swap project root directory\n$(DEF_COLOR)\n"; \
		printf "\n$(HYELLOW)ERROR: RTFM: The push_swap_averager must be placed inside of your push_swap project root directory\n$(DEF_COLOR)\n"; \
	fi
	@make --no-print-directory -C ..
	@cp -f ../push_swap .

lib:
	@make --no-print-directory -C srcs/lib

execs: $(OBJS)
	@$(foreach file,$(OBJS), \
		if [ $(file) -nt $(patsubst $(ODIR)%.o,%,$(file)) ] || [ ! -f $(patsubst $(ODIR)%.o,%,$(file)) ] || [ $(LIB) -nt $(file) ]; \
		then \
			printf "Compiling $(file) -> $(HGREEN)$(patsubst $(ODIR)%.o,%,$(file))\n$(DEF_COLOR)"; \
			$(CC) $(CFLAGS) $(INCLUDES) $(file) $(LIB) -o $(patsubst $(ODIR)%.o,%,$(file)); \
		fi; \
	)

$(ODIR)%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BOBJS) lib 
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
	./error_management
	@printf "\n\n";
	./identity_test
	@rm -f tmp*
	@rm -rf log_files
	@mkdir -p log_files
	@./memory_tests
	@./exaustive_test
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

averager: pre_all
	@mkdir -p log_files
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

test500: pre_all
	@mkdir -p log_files
	@printf "$(CYAN)running test500 with valgrind on quiet mode $(DEF_COLOR)\n\n";
	./test500
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test500.log && rm tmp*
	@./analyse_log.sh test500.log
	@mv test500.log ./log_files

test100: pre_all
	@mkdir -p log_files
	@printf "$(CYAN)running test100 with valgrind on quiet mode $(DEF_COLOR)\n\n";
	./test100
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test100.log && rm tmp*
	@./analyse_log.sh test100.log
	@mv test100.log ./log_files

test5: pre_all
	@mkdir -p log_files
	@printf "$(CYAN)running test5 with valgrind on quiet mode $(DEF_COLOR)\n\n";
	./test5
	@cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test5.log && rm tmp*
	@./analyse_log.sh test5.log
	@mv test5.log ./log_files

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
