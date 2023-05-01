LIB = srcs/lib/lib.a
INC = srcs/include/
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

CFLAGS = -w -pthread -I$(INC) -O3
C_BFLAGS = -w -I$(INC) -O3

SRCS_ = \
		basic_test \
		test5 \
		test100 \
		test500

BSRCS_ = \
		main \
		build_bonus_command \
		execute_bonus \
		basic_bonus \

SRCS = $(addprefix srcs/mandatory/, $(SRCS_))
BSRCS = $(wildcard srcs/bonus/*.c)
OBJS = $(SRCS:%=%.o)
BOBJS = $(BSRCS:%=%.o)

EXECS = $(SRCS_:srcs/mandatory/%=%)
BEXECS = basic_bonus

all: lib $(EXECS)
	@make --no-print-directory -C ..
	@cp -f $(PUSH_SWAP) .
	@make --no-print-directory run

lib:
	@make --no-print-directory -C srcs/lib

$(EXECS):
	$(CC) $(CFLAGS) srcs/mandatory/$@.c $(LIB) -o $@

$(BEXECS):
	$(CC) $(C_BFLAGS) $(BSRCS) $(LIB) -o $@

bonus: lib $(BEXECS)
	@make bonus --no-print-directory -C ..
	@cp -f $(PUSH_SWAP) .
	@cp -f $(PUSH_SWAP_BONUS) .
	# ./basic_bonus

run:
	./basic_test
	@mkdir -p log_files
	@rm -f tmp*
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
	@rm -f test* push_swap checker basic_test basic_bonus
	@rm -f tmp*
	@make --no-print-directory -C srcs/lib clean

fclean: clean
	@rm -rf ./log_files
	@make --no-print-directory -C srcs/lib fclean

re: fclean mandatory

.PHONY: all clean
