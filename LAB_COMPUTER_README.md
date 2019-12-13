# Laboratory 1

## Excercise 1

Run a syscall analysis on the echo and ls command and a Hello World C Program and write down a description of the system calls that are being called. You have to add another command to analyze as well. The description should be in-depth and not superficial, google the syscall that you don't know and try to infer from the parameters what are they doin and if they are used in the same order in all of the executions.

All necessary files are located in the `ex2` folder.

Strace manpage:
http://manpages.ubuntu.com/manpages/bionic/man1/strace.1.html

```bash
strace echo "Hello"
strace -e trace=read echo "Hello"
```

```bash
gcc -o hello hello.c
strace ./hello
```

## Excercise 2

Relying on the provided files, write a chat program, based on two C programs using shared memory (not pipes, nor fifo). You can safely assume that the messages won't be long, between 1024 and 4096 bytes is more than enough. You can also assume that only one person will chat at the same time, meaning that only one of the two users can send text at the same time, this does not mean that that one user is limited to one message. This means that, user1 writes and he could write again multiple times, after user2 can reply with one or more messages.

All necessary files are located in the `ex3` folder.

## Excercise 3

To be completed on your personal computer, since it needs to install some packages which are not allowed in the lab computers. If you have any problems with this you can email me to find a solution.

Write a program in the language of your chosing, that consist of two files, a publisher and a suscriber. The publisher, as the word describes it, it will publish a message read from the keyboard. The suscriber, will run endlessly showing all messages. You will have to chose between using Google Pub/Sub, Amazon SQS or a local Redis. All of those tools are well documented and heavily used in the industry. If you want to go one step beyond you can integrate Amazon SNS and Amazon SQS.

Here are some reference links:
- https://cloud.google.com/pubsub/
- https://aws.amazon.com/sqs/
- https://redis.io/topics/pubsub
- https://aws.amazon.com/sns/

The differences are:
- For Google Cloud, you need to create an account, it's free, and create the topic and suscriber for it to work.
- For Amazon Web Services, you also need to create an account, it's also free, and create the queue for it to work.
- For Redis, you need to create a local container or install redis (not recommended), and then expose the ports, therefore you need to google more about Docker and running containers.

Quick example for Google Cloud Pub/Sub relying on the cli:
```bash
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud init
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud auth login
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud pubsub topics publish belt-test --message "Test message" --attribute url=http://www.bla.com,foo=bar
docker run --rm -ti -v $HOME/.config/gcloud:/root/.config/gcloud google/cloud-sdk gcloud pubsub subscriptions pull projects/assistant-backend-dev/subscriptions/belt-sub --auto-ack --format='flattened'
```
