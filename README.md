# minitalk
## Description
This is the project from the third layer of the 42  school curriculum.
It's purpose  is to implement minitalk communication protocol.
## Installation
Here's what you have to do in order to get the final library
+ Install make if you don't have it
```sh
sudo apt-get install make
```
+ Build the library
```sh
make
```
## Run the project
Run the server
```sh
./server_app
```
You get the following output
![image](https://github.com/neulad/minitalk/assets/116178300/154fed53-b249-48c1-a7ed-960dd4da2570)
Copy the number of pid
Now run the client
```sh
./cient_app (pid) ["message"]
```
The third message can be anything, then the server should display your message
![image](https://github.com/neulad/minitalk/assets/116178300/6650e3ab-3552-48b4-b85f-d4774b943649)

## Useful commands
Here're the commands you might find useful
+ Clean up (delete all binaries)
```sh
make clean
```
## Copyright
Feel free to copy and distribute this code for any purposes as long
as you take full responsibility for the actions  you take using it. All code is uploaded only in educational purposes.
