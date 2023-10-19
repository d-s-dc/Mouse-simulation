#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <linux/input.h>

int main ( int argc, char *argv[], char *env[] )
{
    int left_key = KEY_LEFT, right_key = KEY_RIGHT, up_key = KEY_UP, down_key = KEY_DOWN;
    // int left_key = KEY_A, sright_key = KEY_D, up_key = KEY_W, down_key = KEY_S;

    FILE *kbd = fopen("/dev/input/by-path/platform-i8042-serio-0-event-kbd", "r");
    // FILE *mouse = fopen("/dev/input/by-path/pci-0000:00:15.0-platform-i2c_designware.0-mouse", "rb");
    unsigned char buffer[3];

    char key_map[KEY_MAX/8 + 1];    //  Create a byte array the size of the number of keys
    
    int val = 0, previous_val = 0, up_cmd, down_cmd;
    
    while (1) {
        sleep(0.05);

        memset(key_map, 0, sizeof(key_map));    //  Initate the array to zero's
        ioctl(fileno(kbd), EVIOCGKEY(sizeof(key_map)), key_map);    //  Fill the keymap with the current keyboard state

        // printf("File read \t");
        // fflush(stdin);
        int l_keyb = key_map[left_key/8];  //  The key we want (and the seven others arround it)
        int l_mask = 1 << (left_key % 8);  //  Put a one in the same column as out key state will be in;

        int r_keyb = key_map[right_key/8];
        int r_mask = 1 << (right_key % 8);

        int u_keyb = key_map[up_key/8];
        int u_mask = 1 << (up_key % 8);

        int d_keyb = key_map[down_key/8];
        int d_mask = 1 << (down_key % 8);

        val = 0;
        if (l_keyb & l_mask)
            val = 1;
        else if (r_keyb & r_mask)
            val = 2;
        
        up_cmd = (u_keyb & u_mask) > 0;
        down_cmd = (d_keyb & d_mask) > 0;

        if (!up_cmd & !down_cmd & val == previous_val)
        {
            // printf("No change continue\n");
            continue;
        }
        
        // fread(buffer, sizeof(buffer), 1, mouse);
        // if (buffer[0] & 0x1)
        //     system("ydotool click 0x80");
        system("ydotool click 0x80");
        
        if (up_cmd) {
            system("ydotool mousemove --absolute 350 200 && ydotool click 0x40 0x80 0x40");
            for (int i = 0; i < 5; i++)
                system("sleep 0.02 && ydotool mousemove -x 0 -y -20");
            system("ydotool click 0x80");
        }
        
        if (down_cmd) {
            system("ydotool mousemove --absolute 350 200 && ydotool click 0x40 0x80 0x40");
            for (int i = 0; i < 4; i++)
                system("sleep 0.01 && ydotool mousemove -x 0 -y 25");
            system("ydotool click 0x80");
        }

        if (val == 1)
            system("ydotool mousemove --absolute 100 200 && ydotool click 0x40 0x80 0x40 && sleep 0.2");
        else if (val == 2)
            system("ydotool mousemove --absolute 500 200 && ydotool click 0x40 0x80 0x40 && sleep 0.2");

        // if (buffer[0] & 0x1)
        //     printf("Remove previous click\n");

        // printf("Remove previous click");
        
        // if (up_cmd)
        //     printf("Up key pressed\n");

        // if (down_cmd)
        //     printf("Down key pressed\n");

        // if (val == 1)
        //     printf("Move left");
        // else if (val == 2)
        //     printf("Move right");
        
        previous_val = val;
    }
}