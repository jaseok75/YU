/**
 * 파일명 : "PL04_21912150_김하림_Lab01.cpp"
 * 프로그램의 목적 및 기본 기능 :
 *   - 이 프로그램은 키보드로부터 전자 피아노 음에 설정된 문자를 입력받고,
 *     문자에 해당하는 옥타브, 음, 주파수를 출력하는 프로그램이다.
 *
 * 프로그램 작성자 : 김하림(2020년 4월 13일),
 * 최종 Update : 2020년 04 13일 (김하림).
 */
#include <stdio.h>
#include <conio.h>  //for getch()
#include <Windows.h>    //for beep()

double key_to_freq(int index, char shift_on, char alt_on, char ch);

int main(void)
{
    char ch, alt_on, shift_on = 0;
    int duration = 100; //100ms
    double freq;
    int index = 0;

    printf("Simple Electric Piano !!\n");
    printf("'A' ~ 'J' : octave 8 도 레 미 파 솔 라 시,\n");
    printf("'Z' ~ 'M' : octave 7 도 레 미 파 솔 라 시,\n");
    printf("'q' ~ 'u' : octave 6 도 레 미 파 솔 라 시,\n");
    printf("'a' ~ 'j' : octave 5 도 레 미 파 솔 라 시, and\n");
    printf("'z' ~ 'm' : octave 4 도 레 미 파 솔 라 시\n");
    printf("\npiano key <ESC to end> : ");

    while ((ch = _getch()) != 27)   //ASCII 코드 값 (27) = ESC
    {
        alt_on = 0;

        if (GetAsyncKeyState(VK_MENU) & 0x8000) //#이 함께 눌렸는지 확인
        {
            alt_on = 1;
        }

        if ((ch >= 'a') && (ch <= 'z')) //전자 피아노에 포함된 문자입력시 index포함-소문자
        {
            shift_on = 0;
            index = ch - 'a';   //index : 0 ~ 25
        }

        else if ((ch >= 'A') && (ch <= 'Z'))    //전자 피아노에 포함된 문자입력시 index포함-대문자
        {
            shift_on = 1;
            index = ch - 'A';   //index : 0 ~ 25
        }

        else   //전자 피아노에 포함되지 않은 문자입력시
        {
            index = -1; //wrong key
        }

        freq = key_to_freq(index, shift_on, alt_on, ch);

        if (freq != -1 && index != -1)
        {
            Beep(freq, duration);
        }

        else
        {
            printf("%c\nInput key (%c) is wrong key input..\n", ch, ch);
        }

        printf("piano key <ESC to end> : ");
    }

    return 0;
}

double key_to_freq(int index, char shift_on, char alt_on, char ch)  //입력받은 문자의 옥타브, 음, 주파수 출력하는 함수
{
    double freq;

    //주파수
    double Key_to_Freq[2][2][26] =
    {
        // alt_on = 0
        {
            { 523.20, 392.00, 329.60, 659.20, 1318.40, 698.40, 784.00, 880.00, -1, 987.84, -1, -1, 493.92, 440.00, -1, -1, 1046.40, 1396.80, 587.36, 1568.00, 1975.68, 349.20, 1174.72, 293.68, 1760.00, 261.60},
            { 4185.60, 3136.00, 2636.80, 5273.60, -1, 5587.20, 6272.00, 7040.00, -1, 7902.72, -1, -1, 3951.36, 3520.00, -1, -1, -1, -1, 4698.88, -1, -1, 2793.60, -1, 2349.44, -1, 2092.80 }
        },
        //alt_on = 1
        {
            { 554.24, 415.28, -1, -1, -1, 740.00, 830.56, 932.32, -1, -1, -1, -1, -1, 466.16, -1, -1, 1108.48, 1480.00, 622.24, 1661.12, -1, 370.00, 1244.48, 311.12, 1864.64, 277.12 },
            { 4433.92, 3322.24, -1, -1, -1, 5920.00, 6644.48, 7458.56, -1, -1, -1, -1, -1, 3729.28, -1, -1, -1, -1, 4977.92, -1, -1, 2960.00, -1, 2488.96, -1, 2216.96 }
        }
    };

    freq = Key_to_Freq[alt_on][shift_on][index];

    if (freq == -1 || index == -1) //전자 피아노 음에 설정되지 않은 문자일 때
    {
        return -1;
    }

    if (shift_on == 0) //옥타브 출력-소문자
    {
        if (index == 25 || index == 23 || index == 2 || index == 21 || index == 1 || index == 13 || index == 12)
        {
            printf("%c : Octave 4 ? ", ch);
        }

        else if (index == 0 || index == 18 || index == 3 || index == 5 || index == 6 || index == 7 || index == 9)
        {
            printf("%c : Octave 5 ? ", ch);
        }

        else
        {
            printf("%c : Octave 6 ? ", ch);
        }
    }

    else if (shift_on == 1)    //옥타브 출력-대문자
    {
        if (index == 25 || index == 23 || index == 2 || index == 21 || index == 1 || index == 13 || index == 12)
        {
            printf("%c : Octave 7 ? ", ch);
        }

        else
        {
            printf("%c : Octave 8 ? ", ch);
        }
    }

    //음 및 주파수 출력
    if ((freq / 32.70) - (int)(freq / 32.70) == 0)
    {
        printf("도<C>, %.2lfHz\n", freq);
    }

    else if ((freq / 34.64) - (int)(freq / 34.64) == 0)
    {
        printf("도#<C#>, %.2lfHz\n", freq);
    }

    else if ((freq / 36.71) - (int)(freq / 36.71) == 0)
    {
        printf("레<D>, %.2lfHz\n", freq);
    }

    else if ((freq / 38.89) - (int)(freq / 38.89) == 0)
    {
        printf("레#<D#>, %.2lfHz\n", freq);
    }

    else if ((freq / 41.20) - (int)(freq / 41.20) == 0)
    {
        printf("미<E>, %.2lfHz\n", freq);
    }

    else if ((freq / 43.65) - (int)(freq / 43.65) == 0)
    {
        printf("파<F>, %.2lfHz\n", freq);
    }

    else if ((freq / 46.25) - (int)(freq / 46.25) == 0)
    {
        printf("파#<F#>, %.2lfHz\n", freq);
    }

    else if ((freq / 49.00) - (int)(freq / 49.00) == 0)
    {
        printf("솔<G>, %.2lfHz\n", freq);
    }

    else if ((freq / 51.91) - (int)(freq / 51.91) == 0)
    {
        printf("솔#<G#>, %.2lfHz\n", freq);
    }

    else if ((freq / 55.00) - (int)(freq / 55.00) == 0)
    {
        printf("라<A>, %.2lfHz\n", freq);
    }

    else if ((freq / 58.27) - (int)(freq / 58.27) == 0)
    {
        printf("라#<A#>, %.2lfHz\n", freq);
    }

    else if ((freq / 61.74) - (int)(freq / 61.74) == 0)
    {
        printf("시<B>, %.2lfHz\n", freq);
    }

    return freq;
}