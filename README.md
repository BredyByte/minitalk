# 📡 Minitalk 📡

<img width="1224" alt="Screen Shot 2023-08-25 at 7 47 01 PM" src="https://github.com/Dvaid0805/42_minitalk/assets/81176650/88c36bd2-1554-44bd-819e-e4f2bf2036f0">

Minitalk is a project to learn IPC (inter-process communication) in C by developing a small data exchange program.

## What is it?

The main idea is to design a simple protocol to allow two processes to communicate by sending each other signals. Minitalk accomplishes this by using UNIX signals to transmit information between instances of a server and client. 

## How it works

The server establishes a listening thread that waits for signal messages. When a signal is received, it interprets the bits and appends them to a message buffer. Once the full message is received, it is printed out.

The client handles generating and sending the signals that represent the data. It uses signals to serially transmit each bit of a message to the server.

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
