package com.example.myapplication;

import android.content.Intent;
import android.os.Handler;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    Button connect_btn;                 // ip 받아오는 버튼
    Button send_btn;

    EditText ip_edit;               // ip 에디트
    EditText date_edit;
    TextView show_text;             // 서버에서온거 보여주는 에디트
    TextView show_emotion;
    // 소켓통신에 필요한것
    private String html = "";
    private Handler mHandler;

    private Socket socket;

    private BufferedReader networkReader;
    private PrintWriter networkWriter;

    private DataOutputStream dos;
    private DataInputStream dis;

    private String ip = "165.229.185.219";            // IP 번호
    private int port = 9999;                          // port 번호
    private String input_message;

    private static int BUF_SIZE = 100;
    private int flag_send = 0;

    private String phone_number = "";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        connect_btn = (Button)findViewById(R.id.connect_btn);
        connect_btn.setOnClickListener(this);
        send_btn = (Button)findViewById(R.id.send_btn);
        send_btn.setOnClickListener(this);

        ip_edit = (EditText)findViewById(R.id.ip_edit);
        show_text = (TextView)findViewById(R.id.show_text);
        date_edit = (EditText)findViewById(R.id.date_edit);
        show_emotion = (TextView)findViewById(R.id.show_emotion);
    }

    @Override
    public void onClick(View v) {
        switch(v.getId()){
            case R.id.connect_btn:     // ip 받아오는 버튼
                connect();
                break;
            case R.id.send_btn:
                send();
                break;
        }
    }

    void send() {
        Thread sendThread = new Thread() {
            @Override
            public void run() {
                String text_send = String.valueOf(date_edit.getText());
                if(text_send != null)   {
                    try {
                        dos.writeUTF(text_send);
                    } catch (Exception e)   {

                    }
                }
                while(true) {
                    try {
                        flag_send = 1;
                        dos.flush();
                    } catch (Exception e) {

                    }
                }
            }
        };
        sendThread.start();
    }

    // 로그인 정보 db에 넣어주고 연결시켜야 함.
    void connect(){
        mHandler = new Handler();
        flag_send = 0;
        Log.w("connect","연결 하는중");
        // 받아오는거
        Thread checkUpdate = new Thread() {
            public void run() {
                // ip받기
                //String newip = String.valueOf(ip_edit.getText());
                phone_number = String.valueOf(ip_edit.getText());

                /*
                if (newip.equals(phone_number)) {
                    ip = "165.229.185.195";
                }*/

                // 서버 접속
                try {
                    socket = new Socket(ip, port);
                    Log.w("서버 접속됨", "서버 접속됨");
                } catch (IOException e1) {
                    Log.w("서버접속못함", "서버접속못함");
                    e1.printStackTrace();
                }

                Log.w("edit 넘어가야 할 값 : ","안드로이드에서 서버로 연결요청");

                // Buffered가 잘못된듯.
                try {
                    dos = new DataOutputStream(socket.getOutputStream());   // output에 보낼꺼 넣음
                    dis = new DataInputStream(socket.getInputStream());     // input에 받을꺼 넣어짐
                    //dos.writeUTF("안드로이드에서 서버로 연결요청");

                } catch (IOException e) {
                    e.printStackTrace();
                    Log.w("버퍼", "버퍼생성 잘못됨");
                }
                Log.w("버퍼","버퍼생성 잘됨");

                try {
                    dos.writeUTF(phone_number);
                    dos.flush();
                } catch (Exception e) {

                }

                while(true) {
                    // 서버에서 받아옴
                    try {
                        String line = "";
                        int line2;
                        byte[] buf = new byte[BUF_SIZE];
                        while (true) {
                            //line = (String) dis.readUTF();
                            line2 = dis.read(buf);
                            input_message = new String (buf, 0, line2);
                            Log.w("서버에서 받아온 값 ", "" + line);
                            Log.w("=====", "" + input_message);

                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    if(flag_send == 0)  {
                                        show_text.setText(input_message);
                                    }
                                    else    {
                                        show_emotion.setText(input_message);
                                    }
                                }
                            });

                            //Log.w("서버에서 받아온 값 ", "" + line2);

                        }
                    } catch (Exception e) {

                    }
                }

            }
        };
        // 소켓 접속 시도, 버퍼생성
        checkUpdate.start();
    }
}