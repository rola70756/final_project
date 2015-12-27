#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include "console_draw3.h"
#include "kb_input2.h"
#include "image.h"
#include "font.h"
#include "audio.h"

#define NUM_KEYS 4

int main(void)
{
    int k;
    int key_down[NUM_KEYS] = {0};
    int key_val[NUM_KEYS] = {VK_A, VK_S, VK_D, VK_ESCAPE};
    initializeKeyInput();

    /*Audio sample*/
    Audio audio[3];
    openAudioFile("DR220A_CH.wav", &audio[0]);
    openAudioFile("DR220A_SD.wav", &audio[1]);
    openAudioFile("DR220A_HT.wav", &audio[2]);

    /*
    Your code here
    In this part, you need to declare the string in logo , large font and read_image into a Image struct type
    */
    //char logo[] = "";
    //declare Font
    //declare Image

    while (1)
    {
        for (k = 0 ; k < NUM_KEYS ; k++)
        {
            /* ����B�b�Q���U�����A  ��o�Өƥ�O���bkey_down[k] */
            if(KEY_DOWN(key_val[k]) && !key_down[k])
            {
                key_down[k] = 1;
                /* �b�o�ӨҤl�� ���U A, S, D�|���񤣦P����*/

                switch (key_val[k])
                {
                case VK_A:
                    /* ������������� */
                    playAudio(&audio[0]);
                    break;
                case VK_S:
                    /* ������������� */
                    playAudio(&audio[1]);
                    break;
                case VK_D:
                    /* ������������� */
                    playAudio(&audio[2]);
                 break;
            }
            }
            /*����q�쥻�Q���U�����A,�ܦ���}�����A*/
            if(KEY_UP(key_val[k]) && key_down[k])
            {
                key_down[k] = 0;
           }
        }

        /* Your code here
        In this part, you need to show_image, and putString
        */
        //clear the Screen
        //put string(logo)
        //show image
        //put large font
        //putStringLarge(large_font, 10, 10, "SAMPLE PROGRAM", 5);
        //drawcmdwindow
        //sleep
        //Sleep(500);
    }
    //destroy image

    return 0;
}



