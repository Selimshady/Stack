include <stdio.h>

typedef struct queue{
    int val;
    struct queue *next;    
}QUEUE;

QUEUE *FRONT;
QUEUE *REAR;
int toplam = 0;


int insertData(int);
void removeData();
int showQueue();
int full();
int empty();
void peek();

int main(int argc, char **argv)
{
    QUEUE q0;
    QUEUE q1;
    QUEUE q2;
    QUEUE q3;
    QUEUE q4;
    QUEUE q5;

    
    q0.next=&q1;q1.next=&q2;q2.next=&q3;q3.next=&q4;q4.next=&q5;q5.next=&q0;
    FRONT = &q0;
    REAR  = &q0;

    
    
    showQueue();
    removeData();
    showQueue();
    insertData(18011067);
    showQueue();
    peek();
    removeData();
    removeData();
    removeData();
    removeData();
    removeData();
    removeData();
    showQueue();
    printf("------------------------\n");
    insertData(10);
    insertData(11);
    insertData(15);
    insertData(10);
    insertData(11);
    insertData(15);
    showQueue();
    printf("------------------------\n");
    removeData();
    removeData();
    showQueue();



    


	return 0;
}

int showQueue() {
    if(empty()) {
        return -1;
    }
    else {
        int i;
        QUEUE *tmp;
        tmp=FRONT;
        for(i=0;i<toplam;i++) {
            printf("%d-",tmp->val);
            tmp=tmp->next;
        }
        return 0;
    }
}

int insertData(int x) {
    if(full()) {
        return -1;
    }
    else {
        REAR->val=x;
        REAR = REAR->next;
        toplam++;
        return 0;
    }
}

void removeData() {
    if(!empty()) {
        FRONT = FRONT->next;
        toplam--;
    }
}

int empty() {
    if(REAR == FRONT && toplam == 0) {
        printf("Queue is empty!!\n");
        return 1;
    }
    else 
        return 0;
}

int full() {
    if(REAR == FRONT && toplam == 6) {
        printf("Queue is full!!\n");
        return 1;
    }
    else {
        return 0;
    }
}

void peek() {
    if(REAR == FRONT && toplam == 0) {
        printf("Queue is empty!!\n");
    }
    else {
        printf("%d\n",FRONT->val);
    }
}