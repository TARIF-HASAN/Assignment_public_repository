#!/bin/bash

echo "Simple Calculator"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4.Division"

read -p  "Enter the choice" choice
read -p "Enter the first no." num1
read -p "Enter the second no." num2

if [[ "$choice" -eq 1 ]]; then
	result=$((num1 + num2))

elif [[ "$choice" -eq 2 ]]; then
	result=$((num1 - num2))

elif [[ "$choice" -eq 3 ]]; then
	result=$((num1 * num2))

elif [[ "$choice" -eq 4 ]]; then
	if [[ "$num2" -eq 0 ]]; then
		echo "Error: Division by 0"
	else

	result=$((num1 / num2))
	fi

else
	echo "No such choice"
fi

echo "Result= $result"

