SHELL := /bin/bash
PUSH_SWAP = ../push_swap
PUSH_SWAP_BONUS = ../checker

# Colors
RED    	  	=  \033[0;91m
GRAY      	=  \033[0;37m
CYAN      	=  \033[0;96m
WHITE     	=  \033[0;97m
GREEN     	=  \033[0;92m
YELLOW          =  \033[0;93m
MAGENTA         =  \033[0;95m
DEF_COLOR       =  \033[0;39m

CFLAGS = $(CC) -w -O3 -pthread

all: $(PUSH_SWAP)
	@cp -f $(PUSH_SWAP) .
	@if [ ! -f test5 ]; then \
		$(CFLAGS) srcs/test5.c -o test5; \
		printf "test5 created\n"; \
	fi
	@if [ ! -f test100 ]; then \
		$(CFLAGS) srcs/test100.c -o test100; \
		printf "test100 created\n"; \
	fi
	@if [ ! -f test500 ]; then \
		$(CFLAGS) srcs/test500.c -o test500; \
		printf "test500 created\n"; \
	fi
	@printf "$(CYAN)Now run make with the chosen test as argument, example: $(GRAY)make -C pushswap-averager test5$(DEF_COLOR)\n"

$(PUSH_SWAP):
	@make --no-print-directory -C ..

test5: all
	@mkdir -p log_files
	@if [ ! -f tmp1 ]; then \
		./test5; \
	fi;
	@cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test5.log && rm tmp*
	@./analyse_log.sh test5.log
	@mv test5.log ./log_files
	@mkdir -p executables
	@mv test5 ./executables

test100: all
	@mkdir -p log_files
	@if [ ! -f tmp1 ]; then \
		./test100; \
	fi;
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test100.log && rm tmp*
	@./analyse_log.sh test100.log
	@mv test100.log ./log_files
	@mkdir -p executables
	@mv test100 ./executables

test500: all
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
	@if [ ! -f test5_bonus ]; then \
		$(CFLAGS) srcs/test5_bonus.c -o test5_bonus; \
		printf "test5_bonus created\n"; \
	fi


test5_bonus: bonus
	@mkdir -p log_files
	@cp -f $(PUSH_SWAP_BONUS) .

clean:
	rm -f test5 test100 test500 push_swap checker
	@rm -rf ./executables
	@rm -f tmp*

fclean: clean
	@rm -rf ./log_files

re: fclean all
