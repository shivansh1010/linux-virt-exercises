**CS695 Assignment 1 Readme**
Name: Shivansh Dhiman
Roll No.: 22m2120
Assignment name: cflask


AIM/PURPOSE OF THE EXPERIMENT:
To study the relationship between throughput of a webserver and number of threads.


SETUP AND EXECUTION DETAILS
Steps to run the experiment 5(a):
1) Copy this experiment folder into the `examples` directory of the libhttp1.8 directory
2) `cd` into the directory and run the `make` command
3) Run the server on a single core using the following command, with varying number of threads
    `taskset -c 0 ./cflask 8081 <number_of_threads>`
4) Hit the endpoints (description below) with required parameters to get the desired output.

Description of Endpoints:
1) `http://locahost:8081/`: This returns a hello world message. It works without any arguments.
2) `http://locahost:8081/square?num=2`: This takes a `num` parameter and returns the square of that number. In absence of the parameter, it returns `1`.
3) `http://locahost:8081/cube?num=2`: This takes a `num` parameter and returns the cube of that number. In absence of the parameter, it returns `1`.
4) `http://locahost:8081/helloworld?str=Shivansh`: This takes a `str` parameter and returns the string `Hello, Shivansh`. In absence of the parameter, it just returns `Hello`.
5) `http://locahost:8081/pingpong?str=Shivansh`: This takes a `str` parameter and returns the same string back `Shivansh`. In absence of the parameter, it returns `PingPong`.
6) `http://locahost:8081/arithmetic/prime?num=1009`: This takes a `num` parameter and returns `True` if the number is a prime and `False` otherwise. In absence of a parameter, it returns `False`.
7) `http://locahost:8081/arithmetic/fibonacci?num=5`: This takes a parameter `n` and returns the `n`th number in the Fibonacci series. In absence of a parameter, it just returns `1`.

Steps to run the experiment 5(b):
1) Run the following benchmark command for different number of threads of the server, such as 1, 2, and 10. In this command, change the value of -c (concurrency factor) to get different data points as a result.
    `ab -n 100000 -c 1 http://localhost:8081/`
2) Run the following benchmark command for different number of threads of the server, such as 1, 2, and 10. In this command, change the value of -c (concurrency factor) to get different data points as a result.
    `ab -n 100000 -c 1 http://localhost:8081/cube`
3) Run the following benchmark command for different number of threads of the server, such as 1, 2, and 10. In this command, change the value of -c (concurrency factor) to get different data points as a result.
    `ab -n 100000 -c 1 http://localhost:8081/arithmetic/prime?num=1009`
4) The results received from the above experiment are stored into the respective files in the `plots` folder.

HYPOTHESIS
With the increase in number of threads of the webserver, the throughput also increases.


OBSERVATIONS
On generating the graph plots, we observe that the throughput indeed increases with the increase in number of threads of the webserver. The throughput increase until a certain point after which, it flattens out and remains constant. Although it sometimes increases or decreases slightly.


EXPLANATION
With increase in number of threads of the webserver, it has more threads at its disposal. So, it is able to handle the requests concurrently, thus increasing throughput. The reason for slight deviation in the results is within margin of error and is due to reasons beyond our control. Our observations conincide with the hypothesis and prove its correctness.
