#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct msg {
    long int type;
    char txt[6];
};

void login_process(int msgid);
void otp_generator_process(int msgid);
void mail_process(int msgid);

int main() {
    int msgid;
    key_t key = 1234;


    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid < 0) {
        perror("msgget");
        exit(1);
    }


    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { 
        otp_generator_process(msgid);
        exit(0);
    } else {
        login_process(msgid);
        wait(NULL); 
    }


    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

void login_process(int msgid) {
    struct msg message;
    char workspace[10];

    printf("Please enter the workspace name:\n");
    scanf("%s", workspace);

    if (strcmp(workspace, "cse321") != 0) {
        printf("Invalid workspace name\n");
        return;
    }

    
    message.type = 1;
    strncpy(message.txt, workspace, sizeof(message.txt) - 1);
    message.txt[sizeof(message.txt) - 1] = '\0';
    msgsnd(msgid, &message, sizeof(message.txt), 0);
    printf("Workspace name sent to otp generator from log in: %s\n", message.txt);


    msgrcv(msgid, &message, sizeof(message.txt), 2, 0);
    printf("Log in received OTP from OTP generator: %s\n", message.txt);
    char otp_from_otp_generator[6];
    strncpy(otp_from_otp_generator, message.txt, sizeof(otp_from_otp_generator));


    msgrcv(msgid, &message, sizeof(message.txt), 3, 0);
    printf("Log in received OTP from mail: %s\n", message.txt);
    char otp_from_mail[6];
    strncpy(otp_from_mail, message.txt, sizeof(otp_from_mail));


    if (strcmp(otp_from_otp_generator, otp_from_mail) == 0) {
        printf("OTP Verified\n");
    } else {
        printf("OTP Incorrect\n");
    }
}

void otp_generator_process(int msgid) {
    struct msg message;


    msgrcv(msgid, &message, sizeof(message.txt), 1, 0);
    printf("OTP generator received workspace name from log in: %s\n", message.txt);

   
    snprintf(message.txt, sizeof(message.txt), "%d", getpid());


    message.type = 2;
    msgsnd(msgid, &message, sizeof(message.txt), 0);
    printf("OTP sent to log in from OTP generator: %s\n", message.txt);


    message.type = 4;
    msgsnd(msgid, &message, sizeof(message.txt), 0);
    printf("OTP sent to mail from OTP generator: %s\n", message.txt);


    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) { 
        mail_process(msgid);
        exit(0);
    } else {
        wait(NULL); 
    }
}

void mail_process(int msgid) {
    struct msg message;


    msgrcv(msgid, &message, sizeof(message.txt), 4, 0);
    printf("Mail received OTP from OTP generator: %s\n", message.txt);

  
    message.type = 3;
    msgsnd(msgid, &message, sizeof(message.txt), 0);
    printf("OTP sent to log in from mail: %s\n", message.txt);
}



