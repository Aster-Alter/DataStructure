class CircularQueue:
    def __init__(self, name):
        self.name=name
        self.size=6
        self.front=0
        self.rear=0
        self.data=[None for i in range(self.size)]
    def isEmpty(self): return self.front==self.rear
    def isFull(self): return self.front==(self.rear+1)%self.size
    def enqueue(self):
        if self.isFull():
            print("Queue is full.")
            return 0
        self.rear=(self.rear+1)%self.size
        self.data[self.rear]=input("데이터 입력: ")
    def dequeue(self):
        if self.isEmpty():
            print("Queue is empty.")
            return 0
        self.front=(self.front+1)%self.size
        output=self.data[self.front]
        self.data[self.front]=None
        return output
    def display(self):
        if self.isEmpty():
            print("Queue is empty.")
            return 0
        print(f"name: {self.name} | front: {self.front} | rear: {self.rear}\ndata: ",end="")
        idx=self.front
        while idx!=self.rear:
            idx=(idx+1)%self.size
            print(f"{self.data[idx]} ",end="")
        print("")

def find(value):
    for k,v in QueueList.items():
        if v==[value]:
            return k
Q=[]
QueueList={i:[] for i in range(5)}

while 1:
    todo=int(input("실행: [1] 새 큐 [2] 큐 삭제 [3] 큐 목록 [4] 큐 선택 [0] 종료\n->"))
    if todo==1:
        if len(Q)==5:
            print("큐 개수 제한에 도달했습니다.")
            continue
        i=0
        while(QueueList[i]!=[]):
            i+=1
        newQ=input("큐 이름: ")
        if newQ in Q:
            print("이미 존재하는 이름입니다.")
            continue
        Q.append(newQ)
        QueueList[i].append(newQ)
        if i==0:
            q1=CircularQueue(newQ)
        elif i==1:
            q2=CircularQueue(newQ)
        elif i==2:
            q3=CircularQueue(newQ)
        elif i==3:
            q4=CircularQueue(newQ)
        elif i==4:
            q5=CircularQueue(newQ)
        else:
            print("error in newq")
    elif todo==2:
        if len(Q)==0:
            print("큐가 존재하지 않습니다.")
            continue
        kill=input("삭제할 큐: ")
        if not kill in Q:
            print("해당 큐는 존재하지 않습니다.")
            continue
        Q.remove(kill)
        qnum=find(kill)
        QueueList[qnum]=[]
        if qnum==0:
            del q1
        elif qnum==1:
            del q2
        elif qnum==2:
            del q3
        elif qnum==3:
            del q4
        elif qnum==4:
            del q5
        else:
            print("error in qdel")
    elif todo==3:
        if len(Q)==0:
            print("큐가 존재하지 않습니다.")
            continue
        print(Q)
    elif todo==4:
        if len(Q)==0:
            print("큐가 존재하지 않습니다.")
            continue
        curq=input("선택할 큐: ")
        if not curq in Q:
            print("해당 큐는 존재하지 않습니다.")
            continue
        qnum=find(curq)
        if qnum==0:
            currq=q1
        elif qnum==1:
            currq=q2
        elif qnum==2:
            currq=q3
        elif qnum==3:
            currq=q4
        elif qnum==4:
            currq=q5
        else:
            print("error in qpick")
        while 1:
            subtodo=int(input("실행: [1] 삽입 [2] 삭제 [3] 출력 [0] 종료\n->"))
            if subtodo==1:
                currq.enqueue()
            elif subtodo==2:
                removed=currq.dequeue()
                if removed!=0:
                    print(f"삭제된 데이터: {removed}")
            elif subtodo==3:
                currq.display()
            elif subtodo==0:
                break
            else:
                print("잘못된 입력입니다.")
    elif todo==0:
        break
    else:
        print("잘못된 입력입니다.")