#!/bin/bash

# Prompt the user for the build name
echo "Enter the name for the Docker build:"
read build_name

echo "
# Use an official Ubuntu image as a parent image
FROM ubuntu:latest

# Update and install gcc, g++, make, and valgrind
RUN apt-get update && apt-get install -y gcc g++ make valgrind

# Set the working directory in the container to /app
WORKDIR /app

# Start a shell when the Docker container runs
CMD [\"/bin/bash\"]" > Dockerfile

# Use the user-provided build name
docker build -t $build_name .
docker run -it -v ${PWD}:/app $build_name
