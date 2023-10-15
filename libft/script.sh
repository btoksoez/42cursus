#!/bin/bash

# Output header file
HEADER_FILE="libft.h"

# Folder containing your source files
SOURCE_FOLDER="src"

# Find all .c files in the source folder and extract function prototypes
PROTOTYPES=$(find $SOURCE_FOLDER -name "*.c" -exec grep -H -E "^\w+\s+\*?(\w+)\s*\(" {} \; | sed -e 's/^[^:]*:\(.*\)$/char\t\t\1;/' | sort | uniq)

# Generate the header file
echo "#ifndef LIBFT_H" > $HEADER_FILE
echo "# define LIBFT_H" >> $HEADER_FILE
echo "" >> $HEADER_FILE
echo "# include <stddef.h>" >> $HEADER_FILE
echo "" >> $HEADER_FILE
echo "$PROTOTYPES" >> $HEADER_FILE
echo "" >> $HEADER_FILE
echo "#endif" >> $HEADER_FILE

echo "Generated $HEADER_FILE with formatted function prototypes."
