SHELL := /bin/bash
PUSH_SWAP = ../push_swap
PUSH_SWAP_BONUS = ../checker

# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW      =  \033[0;93m
MAGENTA     =  \033[0;95m
DEF_COLOR   =  \033[0;39m

CFLAGS = $(CC) -w -pthread -O3

mandatory: compile 
	@make --no-print-directory basic 
	@make --no-print-directory test5
	@make --no-print-directory test100
	@make --no-print-directory test500
	@make clean

averager: compile
	@make --no-print-directory test5
	@make --no-print-directory test100
	@make --no-print-directory test500
	@make clean

compile: $(PUSH_SWAP)
	@cp -f $(PUSH_SWAP) .
	@if [ ! -f test5 ]; then \
		$(CFLAGS) srcs/test5.c -o test5; \
	fi
	@if [ ! -f test100 ]; then \
		$(CFLAGS) srcs/test100.c -o test100; \
	fi
	@if [ ! -f test500 ]; then \
		$(CFLAGS) srcs/test500.c -o test500; \
	fi

$(PUSH_SWAP):
	@make --no-print-directory -C ..

basic:
	@if [ ! -f basic_test ]; then \
		$(CFLAGS) srcs/basic_test.c -o basic_test; \
	fi
	@./basic_test

test5: compile 
	@mkdir -p log_files
	@if [ ! -f tmp1 ]; then \
		./test5; \
	fi;
	@cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test5.log && rm tmp*
	@./analyse_log.sh test5.log
	@mv test5.log ./log_files
	@mkdir -p executables
	@mv test5 ./executables

test100: compile
	@mkdir -p log_files
	@if [ ! -f tmp1 ]; then \
		./test100; \
	fi;
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test100.log && rm tmp*
	@./analyse_log.sh test100.log
	@mv test100.log ./log_files
	@mkdir -p executables
	@mv test100 ./executables

test500: compile
	@mkdir -p log_files
	@if [ ! -f tmp1 ]; then \
		./test500; \
	fi;
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test500.log && rm tmp*
	@./analyse_log.sh test500.log
	@mv test500.log ./log_files
	@mkdir -p executables
	@mv test500 ./executables

bonus: $(PUSH_SWAP_BONUS)
	@if [ ! -f push_swap ]; then \
		make --no-print-directory -C ..; \
	fi
	@if [ ! -f test5_bonus ]; then \
		$(CFLAGS) srcs/test5_bonus.c -o test5_bonus; \
		printf "test5_bonus created\n"; \
	fi
	cp -f ../checker .
	cp -f ../push_swap .
	./test5_bonus
	@if [ ! -f test100_bonus ]; then \
		$(CFLAGS) srcs/test100_bonus.c -o test100_bonus; \
		printf "test100_bonus created\n"; \
	fi
	cp -f ../checker .
	cp -f ../push_swap .
	./test100_bonus

$(PUSH_SWAP_BONUS):
	@make --no-print-directory -C .. bonus;

clean:
	@rm -f test* push_swap checker basic_test
	@rm -rf ./executables
	@rm -f tmp*

fclean: clean
	@rm -rf ./log_files

re: fclean mandatory
