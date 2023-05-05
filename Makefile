
# Define flags
CFLAGS = -w -O3 -pthread
INCLUDES = -Isrcs/include/

# Define the source and object file directories
SRCDIR = srcs/mandatory
OBJDIR = objs
LIB = srcs/lib/lib.a

# Define the source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(OBJS) lib
	@make --no-print-directory execs
	@make --no-print-directory -C ..
	@cp -f ../push_swap .
	@make --no-print-directory run

lib:
	@make --no-print-directory -C srcs/lib

execs: $(OBJS)
	@$(foreach file,$(OBJS), \
		if [ $(file) -nt $(patsubst $(OBJDIR)/%.o,%,$(file)) ] || \
		   [ ! -f $(patsubst $(OBJDIR)/%.o,%,$(file)) ]; then \
			printf "Compiling $(file) -> $(patsubst $(OBJDIR)/%.o,%,$(file))\n"; \
			$(CC) $(CFLAGS) $(INCLUDES) $(file) $(LIB) -o $(patsubst $(OBJDIR)/%.o,%,$(file)); \
		fi; \
	)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

run:
	./error_management
	./identity_test
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
	@rm -rf objs
	@rm -f test* push_swap checker basic_test basic_bonus error_management identity_test
	@rm -f tmp*
	@make --no-print-directory -C srcs/lib clean

fclean: clean
	@rm -rf ./log_files
	@make --no-print-directory -C srcs/lib fclean

re: fclean all
