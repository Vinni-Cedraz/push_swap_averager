#!/bin/bash
GREEN="\033[0;32m"
HGREEN="\033[0;92m"
DEF_COLOR="\033[0;39m"
CYAN="\033[0;36m"
HCYAN="\033[1;36m"

# take the directory with the logfiles as an argument:
log_file=$1

# get all non-zero values of the number of operations into an array
arr=($(grep -v 'number of operations: 0' $log_file | grep -o 'number of operations: [0-9]*' | awk '{print $NF}'))

# calculate the total number of operations and the total number of lines
total_ops=0
total_lines=0
for ops in "${arr[@]}"; do
  ((total_ops += ops))
  ((total_lines++))
done

# calculate the average number of operations
average=$((total_ops / total_lines))

# calculate the lowest and highest number of operations
sorted=($(echo "${arr[@]}" | tr ' ' '\n' | sort -n))
lowest=${sorted[0]}
highest=${sorted[-1]}

# print the lines with the lowest, highest, and average number of operations
printf "$GREEN< best case arrays >\n$DEF_COLOR"
cat $log_file | grep "number of operations: $lowest$" | head -n 2

printf "$GREEN<worst case arrays >\n$DEF_COLOR"
cat $log_file | grep "number of operations: $highest$" | head -n 2

# print the lowest, highest, and average number of operations
printf "\n$HGREEN					< MOST IMPORTANT FOR THE EVALUATION > $CYAN average case: $average$DEF_COLOR\n"
