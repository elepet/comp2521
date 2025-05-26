import matplotlib.pyplot as plt

def read_times(filename):
    times = []
    with open(filename, 'r') as file:
        line = file.readline().strip()  # Read the entire first line
        if line:
            parts = line.split(',')
            for value in parts:
                try:
                    times.append(float(value.strip()))
                except ValueError:
                    print(f"Skipping invalid value: {value}")
    return times

def generate_input_sizes(n):
    return [2**i for i in range(n)]

def plot_times(y_values):
    x_values = generate_input_sizes(len(y_values))

    plt.figure(figsize=(8, 5))
    plt.plot(x_values, y_values, marker='o', linestyle='-')

    plt.xscale('log', base=2)  # Set x-axis to log base 2
    plt.xlabel("Input Size (log₂ scale)")
    plt.ylabel("Time (seconds)")
    plt.title("Input Size vs. Time")
    plt.grid(True, which="both", linestyle="--", linewidth=0.5)
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    times = read_times("times.csv")
    if times:
        plot_times(times)
    else:
    	print("No valid data to plot.")
