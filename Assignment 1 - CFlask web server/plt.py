import matplotlib.pyplot as plt
import numpy as np

# Define X and Y variable data
x = np.array([1, 2, 3, 4, 5, 6, 7, 8])

# func1
y1 = np.array([6879.49,9468.01,9334.96,8816.24,9074.18,9188.49,9216.88,8911.44])
y2 = np.array([6576.27,9139.88,9702.32,9891.94,9065.87,9676.64,9684.22,9734.19])
y3 = np.array([6576.87,9416.67,9996.15,9055.15,9204.28,9659.69,10184.70,10296.06])

#func2
# y1 = np.array([7494.50,10338.36,11240.39,10696.66,11150.33,10201.57,10229.75,11294.37])
# y2 = np.array([7709.73,10809.39,11338.94,11368.73,11381.67,10632.28,11197.43,10608.22])
# y3 = np.array([7358.24,10664.65,11076.56,10109.42,11111.53,11177.76,11125.97,11232.63])

#func3
# y1 = np.array([7515.71,9189.27,9675.63,10792.90,10414.77,10614.15,10287.93,10904.58])
# y2 = np.array([7654.04,10752.34,10832.12,10165.76,10968.86,10997.13,10843.83,10933.77])
# y3 = np.array([7360.80,10872.18,9654.56,11012.36,10222.44,10800.04,11032.10,11126.88])

plt.plot(x, y1, label="Threadpool size = 1")
plt.plot(x, y2, label="Threadpool size = 2")
plt.plot(x, y3, label="Threadpool size = 10")
plt.xlabel("Concurrent requests")  # add X-axis label
plt.ylabel("Throughput (Requests/sec)")  # add Y-axis label
plt.ylim(bottom=0)
plt.ylim(top=12000)
plt.title("Load vs Throughput plot")  # add title
plt.legend()
plt.show()
