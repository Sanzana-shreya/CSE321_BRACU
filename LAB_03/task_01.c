#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

struct shared {
    char sel[100];
    int b;
};

void home_process(int pipe_fd[2], struct shared *shm) {
    close(pipe_fd[0]);

    printf("Provide Your Input From Given Options:\n");
    printf("1. Type a to Add Money\n");
    printf("2. Type w to Withdraw Money\n");
    printf("3. Type c to Check Balance\n");

    fgets(shm->sel, 100, stdin);
    shm->sel[strcspn(shm->sel, "\n")] = 0; 

 
    if (shm->b == 0) {
        shm->b = 1000;
    }

    printf("Your selection: %s\n", shm->sel);

    if (fork() == 0) {

        if (strcmp(shm->sel, "a") == 0) {
            int amount;
            printf("Enter amount to be added:\n");
            scanf("%d", &amount);
            if (amount > 0) {
                shm->b += amount;  
                printf("Balance added successfully\n");
                printf("Updated balance after addition: %d\n", shm->b);
            } else {
                printf("Adding failed, Invalid amount\n");
            }
        } else if (strcmp(shm->sel, "w") == 0) {
            int amount;
            printf("Enter amount to be withdrawn:\n");
            scanf("%d", &amount);
            if (amount > 0 && amount <= shm->b) {
                shm->b -= amount;  
                printf("Balance withdrawn successfully\n");
                printf("Updated balance after withdrawal: %d\n", shm->b);
            } else {
                printf("Withdrawal failed, Invalid amount\n");
            }
        } else if (strcmp(shm->sel, "c") == 0) {
 
            printf("Your current balance is: %d\n", shm->b);
        } else {
            printf("Invalid selection\n");
        }
    
        write(pipe_fd[1], "Thank you for using\n", 21);
        close(pipe_fd[1]);
        exit(0);
    } else {
  
        wait(NULL); 
        char buffer[100];
        read(pipe_fd[0], buffer, 100);
        printf("%s", buffer);  
        close(pipe_fd[1]);
    }
}

int main() {
    int shmid;
    key_t key = 1234;
    struct shared *shm;


    if ((shmid = shmget(key, sizeof(struct shared), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

  
    if ((shm = (struct shared *)shmat(shmid, NULL, 0)) == (struct shared *) -1) {
        perror("shmat");
        exit(1);
    }

    if (shm->b == 0) {
        shm->b = 1000;
    }

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(1);
    }

    home_process(pipe_fd, shm);

    
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}





