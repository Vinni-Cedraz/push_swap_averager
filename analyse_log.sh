#!/bin/bash

#Colors
HRED="\033[1;31m"
GREEN="\033[0;32m"
HGREEN="\033[0;92m"
DEF_COLOR="\033[0;39m"
CYAN="\033[0;36m"
HCYAN="\033[1;36m"

# take the directory with the logfiles as an argument:
log_file=$1

LIMIT_5=12
LIMIT_100=1500
LIMIT_500=11500

list_size=0

dir="log_files/"

if [[ "$log_file" == "test5.log" || "$log_file" == $dir"test5.log" ]]; then
    list_size=5
elif [[ "$log_file" == "test100.log" || "$log_file" == $dir"test100.log" ]]; then
    list_size=100
elif [[ "$log_file" == "test500.log" || "$log_file" == $dir"test500.log" ]]; then
    list_size=500
fi

# get all non-zero values of the number of operations into an array
arr=($(grep -v 'number of operations: 0' $log_file | grep -o 'number of operations: [0-9]*' | awk '{print $NF}'))

# calculate the total number of operations and the total number of lines
total_ops=0
total_lines=0
for ops in "${arr[@]}"; do
  # Check if ops is a number
  if [[ $ops =~ ^[0-9]+$ ]]; then
    ((total_ops += ops))
    ((total_lines++))
  else
	  cat $log_file | grep "Error"
	  exit 1
  fi
done

# calculate the average number of operations
average=$((total_ops / total_lines))

# calculate the lowest and highest number of operations
sorted=($(echo "${arr[@]}" | tr ' ' '\n' | sort -n))
lowest=${sorted[0]}
highest=${sorted[-1]}

COLOR=$CYAN
if [ "$list_size" -eq 5 -a "$highest" -ge "$LIMIT_5" ] || [ "$list_size" -eq 100 -a "$highest" -ge "$LIMIT_100" ] || \
	[ "$list_size" -eq 500 -a "$highest" -ge "$LIMIT_500" ]; then
    COLOR=$HRED
	printf "\n$COLOR ERROR: YOU ARE DOING TOO MANY MOVEMENTS SOMEWHERE, CHECK YOUR WORST CASE AND LOG FILES\n"
fi

# print the lines with the lowest, highest, and average number of operations
printf "$GREEN< best case arrays >\n$DEF_COLOR"
cat $log_file | grep "number of operations: $lowest" | head -n 2

printf "$COLOR< worst case arrays >\n$DEF_COLOR"
string=$(cat $log_file | grep "number of operations: $highest" | head -n 2 | awk '{gsub(ENVIRON["CYAN"], ENVIRON["COLOR"]); print}')
printf "$string\n"$DEF_COLOR

# print the lowest, highest, and average number of operations
if [[ "$list_size" -ge 100 ]];
then printf "$HGREEN< AVERAGE > $CYAN average case: $average$DEF_COLOR\n\n\n"
fi
