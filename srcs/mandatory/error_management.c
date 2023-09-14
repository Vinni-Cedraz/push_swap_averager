#include "../include/averager.h"

int main(void) {
    static void (*test[])() = {
		no_args,       non_numeric1,     non_numeric2,        non_numeric3,
		non_numeric4,  non_numeric5,     non_numeric6,        non_numeric_empty_string,
		max_int_overf, duplicate_sorted, duplicate_arguments, NULL
	};
    exec_each_function_in(test, "./push_swap");
}
