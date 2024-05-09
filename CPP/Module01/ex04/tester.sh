#!/bin/bash

# Create a test file
echo "Hello World" > test.txt
echo "Hello Universe" >> test.txt
echo "Goodbye World" >> test.txt

# Test replacing "Hello" with "Hi"
echo "Running Test 1: Replacing 'Hello' with 'Hi'"
./replace test.txt "Hello" "Hi"
if grep -q "Hi World" test.txt.replace; then
    echo "Test 1 passed"
else
    echo "Test 1 failed"
fi

# Test replacing "World" with "Everyone"
echo "Running Test 2: Replacing 'World' with 'Everyone'"
./replace test.txt "World" "Everyone"
if grep -q "Hello Everyone" test.txt.replace; then
    echo "Test 2 passed"
else
    echo "Test 2 failed"
fi

# Test replacing a string that doesn't exist in the file
echo "Running Test 3: Replacing 'Nonexistent' with 'Nothing'"
./replace test.txt "Nonexistent" "Nothing"
if grep -q "Nothing" test.txt.replace; then
    echo "Test 3 failed"
else
    echo "Test 3 passed"
fi

# Clean up
rm test.txt test.txt.replace
