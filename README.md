# Laboratory 1

## Excercise 1

Install VirtualBox or Docker to run the following exercises. You can run the commands in your own computer at your own risk.

Install links for Docker:

- https://docs.docker.com/install/linux/docker-ce/ubuntu/
- https://docs.docker.com/docker-for-windows/install/
- https://docs.docker.com/docker-for-mac/install/

Install links for VirtualBox:

- https://www.virtualbox.org/wiki/Downloads
- https://ubuntu.com/download/server

You could rely on a pre-defined virtual machine provided by me:

- https://chepeftw.s3-us-west-2.amazonaws.com/DesktopUbuntu20.ova

## Excercise 2

Run a syscall analysis on the `echo`, `ls` command and a Hello World C Program and write down a description of the system calls that are being called. You have to add another command (e.g., `ping -c 1 8.8.8.8`) to analyze as well. The description should be in-depth and not superficial, google the syscall that you don't know and try to infer from the parameters what are they doin and if they are used in the same order in all of the executions.

All necessary files are located in the `ex2` folder. To start do:
```bash
cd ex2
docker build -t lab1_ex2 .
```

Strace manpage:
http://manpages.ubuntu.com/manpages/bionic/man1/strace.1.html

```bash
# This are examples for the echo command
docker run --rm -ti lab1_ex2 strace echo "Hello"
docker run --rm -ti lab1_ex2 strace -e trace=read echo "Hello"
```

```bash
# This is how to run a docker to run the strace in the hello command
docker run --rm -ti -v $(pwd)/:/home/test lab1_ex2 /bin/bash -c "cd /home/test; gcc -o hello hello.c; strace ./hello"
```

#### Bonus (in the name of knowledge)

Write a Dockerfile that removes the need to attach a volume and compile the file in that line, so that you can only do:

```bash
docker run --rm -ti lab1_ex2 strace ./root/hello
```

## Excercise 3

Relying on the provided files, write a chat program, based on two C programs using shared memory (not pipes, nor fifo). You can safely assume that the messages won't be long, between 1024 and 4096 bytes is more than enough. You can also assume that only one person will chat at the same time, meaning that only one of the two users can send text at the same time, this does not mean that that one user is limited to one message. This means that, user1 writes and he could write again multiple times, after user2 can reply with one or more messages.

All necessary files are located in the `ex3` folder.

## Excercise 4

Write a program in the language of your chosing, that consist of two files, a publisher and a suscriber. The publisher, as the word describes it, it will publish a message read from the keyboard. The suscriber, will run endlessly showing all messages. You will have to chose between using Google Pub/Sub, Amazon SQS or a local Redis. All of those tools are well documented and heavily used in the industry. If you want to go one step beyond you can integrate Amazon SNS and Amazon SQS.

Here are some reference links:

- https://cloud.google.com/pubsub/
- https://aws.amazon.com/sqs/
- https://redis.io/topics/pubsub
- https://aws.amazon.com/sns/

The differences are:

- For Google Cloud, you need to create an account, it's "free", and create the topic and suscriber for it to work.
- For Amazon Web Services, you also need to create an account, it's also "free", and create the queue for it to work.
- For Redis, you need to create a local container or install redis (not recommended), and then expose the ports, therefore you need to google more about Docker and running containers.

Quick example for Google Cloud Pub/Sub relying on the cli:
```bash
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud init
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud auth login
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud pubsub topics publish belt-test --message "Test message" --attribute url=http://www.bla.com,foo=bar
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud pubsub subscriptions pull projects/assistant-backend-dev/subscriptions/belt-sub --auto-ack --format='flattened'
```
