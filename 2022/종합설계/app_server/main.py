import socket
import time
import threading
import os
from collections import deque

def send(client_socket, send_data):
    print("send thread")
    while True:
        while len(send_data) != 0:
            app_data = send_data.popleft()
            print("Data is", app_data)
            client_socket.send(app_data.encode('utf-8'))
            time.sleep(1)
        time.sleep(1)

def receive(client_socket, send_data, user_phone):
    print("receive thread")
    while True:
        recvData = client_socket.recv(1024)
        recvData = recvData[2:].decode('utf-8')
        print("Receive Data is", recvData)
        if recvData == "":
            print("Nothing Data")
            client_socket.close()
            print(client_socket)
            print("====")
            return
        file_name = './' + user_phone + '/' + recvData + '.txt'
        print("file name is", file_name)
        try:
            file = open(file_name, 'rt', encoding='UTF8')
            file_data = file.read()
            file.close()
            send_data.append(file_data)
        except IOError:
            print("No such File")
            send_data.append("입력하신 날짜에 감정분석된 결과가 없습니다.")

        time.sleep(1)

def main_thread():
    host = '165.229.185.195'
    port = 9999

    while True:
        send_data = deque()
        server_socket = socket.socket(socket.AF_INET)
        server_socket.bind((host, port))
        server_socket.listen(1)

        print('waiting for client . . .')
        client_socket, addr = server_socket.accept()
        print(client_socket)
        print('Connected by', addr)
        user_phone = client_socket.recv(1024)
        user_phone = user_phone[2:].decode('utf-8')
        if os.path.isdir('./'+user_phone):
            print("isdir!")
        else:
            isnotUser = '존재하지 않는 사용자입니다.'
            client_socket.send(isnotUser.encode('utf-8'))
            client_socket.close()
            continue
        print(user_phone)
        data = user_phone + '님과 연결에 성공하였습니다.'
        send_data.append(data)

        sender = threading.Thread(target=send, args=(client_socket,send_data,))
        receiver = threading.Thread(target=receive, args=(client_socket,send_data,user_phone,))

        sender.start()
        receiver.start()
        time.sleep(1)

if __name__ == "__main__":
    main_start = threading.Thread(target=main_thread, args=())
    main_start.start()

    while True:
        print("thread working")
        time.sleep(1)
        pass