class CircularQueue:
    def __init__(self, name):
        self.name=name
        self.size=6
        self.front=0
        self.rear=0
        self.data=[NULL*self.size]
    def isEmpty(): return self.front==self.rear
    def isFull(): return self.front==(self.rear+1)%self.size
    def enqueue():
        if isFull():
            print("Queue is full.")
            return 0
        self.rear=(self.rear+1)%self.size
        self.data[self.rear]=input("데이터 입력: ")
    def dequeue():
        if isEmpty():
            print("Queue is empty.")
            return 0
        self.front=(self.front+1)%self.size
        output=self.data[self.front]
        self.data[self.front]=NULL
        return output
    def display():
        if isEmpty():
            print("Queue is empty.")
            return 0
        print(f"name: {self.name} | front: {self.front} | rear: {self.rear}\ndata: ",end="")
        idx=self.front
        while idx!=self.rear:
            idx=(idx+1)%self.size
            print(f"{self.data[idx]} ",end="")
        print("")

rep,i,QueueList=1,0,{i:[] for i in range(1,6)}
# while rep:
#     todo=int(input("실행: [1] 새 큐 [2] 큐 삭제 [3] 큐 목록 [4] 큐 선택\n->"))
#     if todo==1:
#         while 
print(QueueList)