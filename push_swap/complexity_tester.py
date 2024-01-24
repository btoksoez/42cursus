# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    complexity_tester.py                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/01 14:19:22 by btoksoez          #+#    #+#              #
#    Updated: 2024/01/24 15:15:44 by btoksoez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This plots and approximates a polynomial to the input
# size n and the amount of commands needed to sort of the given algorthim.


import subprocess
import matplotlib.pyplot as plt
import numpy as np
import random

def run_program(input_list):
    # Run your program with the given input
    command = ["./a.out"] + input_list
    subprocess.run(command)

def count_lines(file_path):
    # Count the number of lines in the specified file
    with open(file_path, 'r') as file:
        lines = file.readlines()
    return len(lines)

def main():
    input_sizes = list(range(5, 1001, 10))  # Adjust step size as needed
    commands_counts = []

    for size in input_sizes:
        # Generate list of non-duplicated integers
        input_data = list(range(1, size + 1))
        random.shuffle(input_data)

        # Convert integers to strings and run the program
        input_str = [str(i) for i in input_data]
        run_program(input_str)

        # Count lines in commands.txt
        lines_count = count_lines('commands.txt')
        commands_counts.append(lines_count)

        # Output the input size and corresponding lines count
        print(f"Input Size: {size}, Lines Count: {lines_count}")

    # Fit a polynomial of degree 3 to the data (you can change the degree)
    degree = 3
    coefficients = np.polyfit(input_sizes, commands_counts, deg=degree)
    polynomial = np.poly1d(coefficients)

    # Print the polynomial
    print(f"\nFitted Polynomial: {polynomial}")

    # Plot the data and the fitted polynomial
    plt.plot(input_sizes, commands_counts, marker='o', label='Data')
    plt.plot(input_sizes, polynomial(input_sizes), label=f'Fitted Polynomial (degree {degree})', linestyle='--')
    plt.title('Relationship between Input Size and Commands Count')
    plt.xlabel('Input Size')
    plt.ylabel('Commands Count')
    plt.legend()
    plt.grid(True)
    plt.show()

if __name__ == "__main__":
    main()
