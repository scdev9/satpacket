
#gnome-terminal -- bash -c "./rtl; exec bash"


#!/bin/bash

# Compile the C++ program
g++ -o rtl main.cpp -lrtlsdr

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the compiled program
    ./rtl
else
    echo "Compilation failed."
fi

