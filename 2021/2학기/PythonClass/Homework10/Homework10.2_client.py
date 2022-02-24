import socket
import numpy as np
import cv2
from queue import Queue
from _thread import *
import time

CLIENT_WEBCAM = 0

def recvall (sock, count):
    buf = b''
    while count:
        newbuf = sock.recv (count)
        if not newbuf:
            return None
        buf += newbuf
        count -= len (newbuf)
    return buf

def video_recvfrom_server (client_socket):
    while True:
        try:
            length = recvall (client_socket, 16)
            stringData = recvall (client_socket, int (length))
            data = np.frombuffer (stringData, dtype = 'uint8')
            decimg = cv2.imdecode (data, 1)
            cv2.imshow ('Server:: Received from Client', decimg)
            key = cv2.waitKey (1)
            if key == 27:
                break
        except ValueError:
            pass

def video_sendto_server (client_socket, queue):
    while True:
        try:
            if not queue.empty ():
                stringData = queue.get ()
                client_socket.send (str (len (stringData)).ljust (16).encode ())
                client_socket.send (stringData)
        except ConnectionResetError as e:
            break
    client_socket.close ()

def video_chat_client (queue):
    client_webcam = cv2.VideoCapture (0 + CLIENT_WEBCAM)
    while True:
        ret, frame = client_webcam.read ()
        if ret == False:
            continue
        encode_param = [int (cv2.IMWRITE_JPEG_QUALITY), 90]
        result, imgencode = cv2.imencode ('.jpg', frame, encode_param)
        img_data = np.array (imgencode)
        stringData = img_data.tobytes ()
        queue.put (stringData)
        cv2.imshow ('Client:: Client_Video', frame)
        key = cv2.waitKey (1)
        if key == 27:
            break

if __name__ == "__main__":
    serverAddr = '127.0.0.1'
    PORT = 9999
    enclosure_queue = Queue ()
    serverAddr = input ("Input server IP address = ")
    print ('Client::Connecting to Server')
    client_socket = socket.socket (socket.AF_INET, socket.SOCK_STREAM)
    print ('Client::Connected to Server ({} : {})'.format (serverAddr, PORT))
    start_new_thread (video_chat_client, (enclosure_queue,))
    start_new_thread (video_sendto_server, (client_socket, enclosure_queue,))
    start_new_thread (video_recvfrom_server, (client_socket,))
    while True:
        try:
            time.sleep (1)
        except KeyboardInterrupt:
            client_socket.close ()
            break