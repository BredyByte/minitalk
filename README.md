# 📡 Minitalk 📡

<img width="1224" alt="Screen Shot 2023-08-25 at 7 47 01 PM" src="https://github.com/Dvaid0805/42_minitalk/assets/81176650/88c36bd2-1554-44bd-819e-e4f2bf2036f0">

Minitalk is a project to learn IPC (inter-process communication) in C by developing a small data exchange program.

## What is it?

The main idea is to design a simple protocol to allow two processes to communicate by sending each other signals. Minitalk accomplishes this by using UNIX signals to transmit information between instances of a server and client. 

## How it works

It uses UNIX signals as the method of communication. The server process sets up signal handlers to receive data from the client. The client serially encodes a message into individual bits and sends each bit as a separate signal to the server.

On the receiving side, the server pieces the bits back together in a buffer. Once the full message is received, it is printed out. This demonstrates how to transfer data between processes without using traditional IPC mechanisms like pipes or sockets.

Key aspects covered include threading with pthreads, signal handling, serialization of data across signals, and error handling. Completing Minitalk provides experience with core C skills and an understanding of basic IPC implemented at the system call level.

## Key Learning Outcomes

- IPC fundamentals using signals
- Multithreading with pthreads  
- Data serialization over signals
- Error handling in C

## Useful Links

👀 Learn more about signals:

https://man7.org/linux/man-pages/man7/signal.7.html

🛠 Examples of IPC methods in C: 

https://www.gnu.org/software/libc/manual/html_node/IPC-Overview.html
