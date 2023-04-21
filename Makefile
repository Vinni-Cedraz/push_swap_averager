SHELL := /bin/bash
PUSH_SWAP = ../push_swap
PUSH_SWAP_BONUS = ../checker

CFLAGS = $(CC) -w -O3

all: $(PUSH_SWAP)
	@cp -f $(PUSH_SWAP) .
	@if [ ! -f test5 ]; then \
		$(CFLAGS) src/test5.c -o test5; \
		printf "test5 created\n"; \
	fi
	@if [ ! -f test100 ]; then \
		$(CFLAGS) src/test100.c -o test100; \
		printf "test100 created\n"; \
	fi

test5: all
	@mkdir -p log_files_test5
	@if [ ! -f log_files_test5/log_t1.txt ]; then \
		./test5; \
	fi;
	@if [ ! -f test100_log/log_t1.txt ]; then \
		mv -f log*.txt log_files_test5; \
	fi

test100: all
	@mkdir -p test100_log
	@if [ ! -f tmp1 ]; then \
		./test100; \
	fi
	@cat tmp8 >> tmp7 && cat tmp7 >> tmp6 && cat tmp6 >> tmp5 && cat tmp5 >> tmp4 && cat tmp4 >> tmp3 && cat tmp3 >> tmp2 && cat tmp2 >> tmp1 && cat tmp1 > test100.log && rm tmp*
	@./analyse_log.sh test100.log
	@mv test100.log log_files

clean:
	rm -f test5 test100 push_swap checker
	@rm -f tmp*

fclean: clean
	rm -rf ./log_files

re: fclean all
