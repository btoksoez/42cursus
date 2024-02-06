import subprocess
import random

# List of valid shell commands without input
valid_commands = [
    "ls", "ls -a", "ls -l", "ls -la",
    "wc -l", "wc -w", "wc -c",
    "cat", "head", "tail",
    "grep -r", "grep -i", "grep -v", "grep -r",
    "sort", "uniq"
]

def generate_random_shell_command():
    """Generate a random shell command."""
    return random.choice(valid_commands)

def run_a_out(infile, cmd1, cmd2, outfile):
    """Execute ./a.out with given input file and commands."""
    command = f"./a.out {infile} \"{cmd1}\" \"{cmd2}\" {outfile}"
    subprocess.run(command, shell=True)

def compare_outputs(infile, cmd1, cmd2, outfile):
    """Compare the outputs of ./a.out and shell command."""
    my_output = f"{outfile}.my_output.txt"
    shell_output = f"{outfile}.shell_output.txt"

    # Run ./a.out
    run_a_out(infile, cmd1, cmd2, my_output)

    # Run shell command
    shell_command = f"< {infile} \"{cmd1}\" | {cmd2} > {shell_output}"
    subprocess.run(shell_command, shell=True, stderr=subprocess.PIPE)

    # Compare outputs
    with open(my_output, 'r') as my_output_file, open(shell_output, 'r') as shell_output_file:
        my_output_content = my_output_file.read().strip()
        shell_output_content = shell_output_file.read().strip()

    if my_output_content == shell_output_content:
        print(f"Commands: {cmd1} | {cmd2} - Outputs match!")
    else:
        print(f"Commands: {cmd1} | {cmd2} - Outputs do not match!")

# Test multiple random shell commands
num_tests = 5
for _ in range(num_tests):
    infile = "infile.txt"  # Replace with your input file
    outfile = "outfile.txt"  # Replace with your output file
    cmd1 = generate_random_shell_command()
    cmd2 = generate_random_shell_command()
    compare_outputs(infile, cmd1, cmd2, outfile)
