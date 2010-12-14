/*
 * Copyright (C) 2010 Vivien Barousse
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "radio.h"

char* radio_str(char* chs) {

    char** strs;
    int length;
    char* str;
    int strPtr;

    int i;

    strs = radio_chars(chs);

    length = 0;
    for (i = 0; strs[i] != '\0'; i++) {
        length += strlen(strs[i]) + 1;
    }

    printf("1: %i:%i\n", length, sizeof(char));
    str = malloc(sizeof(char) * length);
    printf("1-\n");

    strPtr = 0;
    for (i = 0; strs[i] != '\0'; i++) {
        strcpy(str + (strPtr * sizeof(char)), strs[i]);
        strPtr += strlen(strs[i]);
        str[strPtr] = ' ';
        strPtr += 1;
    }
    str[strPtr - 1] = (char) 0;
    free(strs);

    return str;

}

char** radio_chars(char* chs) {

    int i;
    char** strs;

    printf("2: %i\n", strlen(chs));
    strs = malloc(sizeof(char*) * (strlen(chs) + 1));
    printf("2-\n");

    for (i = 0; chs[i]; i++) {

        strs[i] = radio_char(chs[i]);

    }

    strs[i] = (char) 0;

    return strs;

}

char* radio_char(char ch) {

    char* str;

    switch(ch) {

        case 'a':
        case 'A':
            return "Alpha";

        case 'b':
        case 'B':
            return "Bravo";

        case 'c':
        case 'C':
            return "Charlie";

        case 'd':
        case 'D':
            return "Delta";

        case 'e':
        case 'E':
            return "Echo";

        case 'f':
        case 'F':
            return "Foxtrot";

        case 'g':
        case 'G':
            return "Golf";

        case 'h':
        case 'H':
            return "Hotel";

        case 'i':
        case 'I':
            return "India";

        case 'j':
        case 'J':
            return "Juliet";

        case 'k':
        case 'K':
            return "Kilo";

        case 'l':
        case 'L':
            return "Lima";

        case 'm':
        case 'M':
            return "Mike";

        case 'n':
        case 'N':
            return "November";

        case 'o':
        case 'O':
            return "Oscar";

        case 'p':
        case 'P':
            return "Papa";

        case 'q':
        case 'Q':
            return "Quebec";

        case 'r':
        case 'R':
            return "Romeo";

        case 's':
        case 'S':
            return "Sierra";

        case 't':
        case 'T':
            return "Tango";

        case 'u':
        case 'U':
            return "Uniform";

        case 'v':
        case 'V':
            return "Victor";

        case 'w':
        case 'W':
            return "Whiskey";

        case 'x':
        case 'X':
            return "X-ray";

        case 'y':
        case 'Y':
            return "Yankee";

        case 'z':
        case 'Z':
            return "Zulu";

        case '1':
            return "Unaone";

        case '2':
            return "Bissotwo";

        case '3':
            return "Terrathree";

        case '4':
            return "Kartefour";

        case '5':
            return "Pantafive";

        case '6':
            return "Soxisix";

        case '7':
            return "Setteseven";

        case '8':
            return "Oktoeight";

        case '9':
            return "Novenine";

        case '0':
            return "Nadazero";

        default:
            printf("3:\n");
            str = malloc(sizeof(char) * 2);
            str[0] = ch;
            str[1] = 0;
            return str;

    }

}
