# Function to create an infinite process
create_infinite_process() {
    while true; do
        sleep 1
    done
}

# Create the first infinite process in the background
create_infinite_process &

# Store the PID of the first process
pid1=$!

# Create the second infinite process in the background
create_infinite_process &

# Store the PID of the second process
pid2=$!

# Wait for some time
sleep 5

# Terminate the first infinite process
kill $pid1

# Terminate the second infinite process
kill $pid2

echo "Infinite processes terminated."
