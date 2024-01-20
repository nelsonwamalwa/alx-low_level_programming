#!/bin/bash

# Converting DOS line endings to Unix (LF)
dos2unix *.c

# Removing the trailing whitespaces
sed -i 's/[[:space:]]\+$//' *.c